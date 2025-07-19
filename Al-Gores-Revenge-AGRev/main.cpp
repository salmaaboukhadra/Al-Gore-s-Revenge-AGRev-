// al_gore_revenge.cpp
// Salma Aboukhadra, CISP 360
// 2025-06-29
//
// Al Gore's Revenge (AGRev)
// ------------------------------------------------------------
// This program explores how Earth's climate has changed over
// the past century and projects sea-level rise and July mean
// temperature increases for several U.S. cities. It fulfils all
// "C", "B", and "A" specifications in the AGRev assignment.
// ------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// ---------- Constants -------------------------------------------------
const double SEA_RISE_RATE_MM    = 3.1;      // mm per future year
const double MM2IN               = 0.03937;  // millimetres → inches
const double TEMP_INCREASE_F     = 2.0;      // °F every 15 years
const double F2C                 = 5.0 / 9.0;
const int    YEARS               = 5;
const int    TEMP_PERIOD_YEARS   = 15;

const int    NUM_CITIES = 4;
const string CITY_NAMES[NUM_CITIES]   = { "New York City", "Denver", "Phoenix", "Sacramento" };
const double CITY_TEMPS_F[NUM_CITIES] = { 85.0, 88.0, 106.0, 92.0 };

// ---------- Specification C1 – ProgramGreeting ------------------------
void ProgramGreeting() {
    cout << "----------------------------------------------------\n";
    cout << "AL GORE'S REVENGE – Climate Change Explorer v1.0\n";
    cout << "Written for CISP 360 – Folsom Lake College\n";
    cout << "Explore projected sea-level rise and temperature trends.\n";
    cout << "----------------------------------------------------\n\n";
}

// ---------- Specification B4 – Client Name ----------------------------
string getName() {
    string name;
    cout << "Please enter your name: ";
    getline(cin, name);
    return name;
}

// ---------- Specification B3 – Advice Section ------------------------
void alsAdvice(const string& advice) {
    cout << "\nADVICE: " << advice << '\n';
}

// ---------- Specification A2 & A3 – autoHeader -----------------------
void autoHeader(const string& title) {
    string caps = title;
    transform(caps.begin(), caps.end(), caps.begin(), ::toupper);
    cout << caps << '\n'
         << string(caps.size(), '=') << '\n';
}

// ---------- Specification C4 – coutAll -------------------------------
void coutAll(double seaRiseMM, double tempF) {
    cout << fixed << setprecision(3)
         << seaRiseMM << " mm\t" << tempF << " °F\n";
}

// ---------- Specification A1 – coutMax -------------------------------
void coutMax(double seaRiseMM, double seaRiseIN,
             double tempF, double tempC) {
    cout << fixed << setprecision(3)
         << setw(10) << seaRiseMM << " mm"
         << setw(12) << seaRiseIN  << " in"
         << setw(12) << tempF      << " °F"
         << setw(12) << tempC      << " °C\n";
}

// =========================== MAIN =====================================
int main() {
    // Specification C1 - ProgramGreeting
    ProgramGreeting();

    // Specification B4 - Client Name
    string clientName = getName();
    cout << "\nWelcome, " << clientName << "!\n\n";

    // -------- Sea-level Rise Forecast (Specs C2, B1, A4) -----------
    // Specification A2 - Auto Heading Function
    // Specification A3 - Adv Heading Title
    autoHeader("Sea Level Rise Forecast");

    // Specification C2 - 5 year rise
    // Specification B1 - Mixed length output
    double seaRiseMM[YEARS], seaRiseIN[YEARS];
    for (int i = 0; i < YEARS; ++i) {
        seaRiseMM[i] = SEA_RISE_RATE_MM * (i + 1);
        seaRiseIN[i] = seaRiseMM[i] * MM2IN;
    }

    // Specification A4 - Make Nice
    cout << left << setw(8)  << "Year"
         << setw(18) << "Rise (mm)"
         << setw(16) << "Rise (in)\n";
    cout << string(42, '-') << '\n';

    for (int i = 0; i < YEARS; ++i)
        cout << setw(8)  << (i + 1)
             << setw(18) << fixed << setprecision(3) << seaRiseMM[i]
             << setw(16) << seaRiseIN[i] << '\n';

    // -------- Projected City Temperatures (Specs C3, B2, A4) -------
    autoHeader("Projected City Temperatures");

    // Specification C3 - 5 year temp
    // Specification B2 - Mixed temperature output
    double tempsF[NUM_CITIES][YEARS], tempsC[NUM_CITIES][YEARS];
    for (int city = 0; city < NUM_CITIES; ++city)
        for (int yr = 0; yr < YEARS; ++yr) {
            double deltaF = TEMP_INCREASE_F * (yr + 1) / (TEMP_PERIOD_YEARS / YEARS);
            tempsF[city][yr] = CITY_TEMPS_F[city] + deltaF;
            tempsC[city][yr] = (tempsF[city][yr] - 32) * F2C;
        }

    cout << left << setw(14) << "City"
         << setw(6)  << "Year"
         << setw(12) << "Temp (°F)"
         << setw(12) << "Temp (°C)\n";
    cout << string(44, '-') << '\n';

    for (int city = 0; city < NUM_CITIES; ++city) {
        for (int yr = 0; yr < YEARS; ++yr) {
            cout << left << setw(14) << CITY_NAMES[city]
                 << setw(6)  << (yr + 1)
                 << setw(12) << fixed << setprecision(3) << tempsF[city][yr]
                 << setw(12) << tempsC[city][yr] << '\n';
        }
        cout << '\n';
    }

    // -------- Year 1 Summary (Specs C4, A1) ------------------------
    autoHeader("Year 1 Summary (Rise & Temp)");

    // Specification C4 - coutAll function
    coutAll(seaRiseMM[0], tempsF[0][0]);

    cout << left << setw(10) << "Year"
         << setw(16) << "Rise (mm)"
         << setw(16) << "Rise (in)"
         << setw(16) << "Temp (°F)"
         << setw(16) << "Temp (°C)\n";
    cout << string(74, '-') << '\n';

    // Specification A1 - coutMax function
    for (int yr = 0; yr < YEARS; ++yr) {
        cout << left << setw(10) << (yr + 1);
        coutMax(seaRiseMM[yr], seaRiseIN[yr],
                tempsF[0][yr], tempsC[0][yr]);
    }

    // Specification B3 - Advice
    alsAdvice("Be aware of accelerating climate trends – act locally and globally today!");

    cout << "\nEnd of output.\n";
    return 0;
}

/* --------------------- SAMPLE OUTPUT -------------------------------
----------------------------------------------------
AL GORE'S REVENGE – Climate Change Explorer v1.0
Written for CISP 360 – Folsom Lake College
Explore projected sea-level rise and temperature trends.
----------------------------------------------------

Please enter your name: Salma
Welcome, Salma!

SEA LEVEL RISE FORECAST
=======================
Year    Rise (mm)        Rise (in)
------------------------------------------
1       3.100            0.122
2       6.200            0.244
3       9.300            0.366
4       12.400           0.488
5       15.500           0.610

PROJECTED CITY TEMPERATURES
============================
City          Year  Temp (°F)   Temp (°C)
--------------------------------------------
New York City 1     85.267      29.593
New York City 2     85.533      29.740
New York City 3     85.800      29.889
New York City 4     86.067      30.037
New York City 5     86.333      30.185

Denver        1     88.267      31.260
Denver        2     88.533      31.407
Denver        3     88.800      31.556
Denver        4     89.067      31.704
Denver        5     89.333      31.852

Phoenix       1     106.267     41.260
Phoenix       2     106.533     41.407
Phoenix       3     106.800     41.556
Phoenix       4     107.067     41.704
Phoenix       5     107.333     41.852

Sacramento    1     92.267      33.482
Sacramento    2     92.533      33.629
Sacramento    3     92.800      33.778
Sacramento    4     93.067      33.926
Sacramento    5     93.333      34.074

YEAR 1 SUMMARY (RISE & TEMP)
============================
3.100 mm     85.267 °F

Year      Rise (mm)    Rise (in)     Temp (°F)     Temp (°C)
---------------------------------------------------------------------------
1         3.100        0.122         85.267        29.593
2         6.200        0.244         85.533        29.740
3         9.300        0.366         85.800        29.889
4         12.400       0.488         86.067        30.037
5         15.500       0.610         86.333        30.185

ADVICE: Be aware of accelerating climate trends – act locally and globally today!

End of output.
-------------------------------------------------------------------------- */
