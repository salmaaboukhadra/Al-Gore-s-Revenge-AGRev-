# Al-Gore-s-Revenge-AGRev-
Al Gore's Revenge (AGRev) - Climate Change Explorer
A C++ program that explores Earth's climate changes over the past century and projects future sea-level rise and temperature increases for major U.S. cities.

📋 Project Overview
Course: CISP 360 - Structured Programming in C++
Author: Salma Aboukhadra
Date: June 29, 2025
Assignment: Al Gore's Revenge (AGRev)

This program analyzes climate data and provides projections for:

Sea level rise over the next 5 years (based on 3.1 mm/year rate)

Temperature increases for 4 major U.S. cities over the next 5 years

Mixed unit outputs (mm/inches for sea rise, °F/°C for temperatures)

🌡️ Cities and Base Data
City	Base July Temperature (°F)
New York City	85.0
Denver	88.0
Phoenix	106.0
Sacramento	92.0
Climate Projections:

Sea level rise: 3.1 mm per year (accelerated from historical 1.8 mm over past century)

Temperature increase: 2°F every 15 years, continuing at that rate

🚀 How to Compile and Run
Prerequisites
Ubuntu Desktop Linux 18.04 or compatible

GCC compiler with C++14 support

Compilation
bash
g++ -std=c++14 -g -Wall al_gore_revenge.cpp -o al_gore_revenge
Execution
bash
./al_gore_revenge
🏗️ Program Structure
The program implements multiple specification levels:

C-Level Specifications (Required)
C1: Program greeting function

C2: 5-year sea level rise calculations

C3: 5-year temperature projections for all cities

C4: coutAll function for formatted output

B-Level Specifications (Enhanced)
B1: Mixed length output (mm and inches)

B2: Mixed temperature output (°F and °C)

B3: Advice section with alsAdvice function

B4: Client name input with getName function

A-Level Specifications (Advanced)
A1: coutMax function displaying all 4 measurements

A2: autoHeader function with automatic uppercase conv
