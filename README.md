# Traffic-Controller (C++)

This repository contains the **Control Logic** component of the Smart Traffic System project. 
It acts as the "hands" of the system, receiving real-time traffic decisions from the AI Brain (Python) and simulating traffic light cycles.

## 🚀 Key Features
* **Inter-process Communication:** Reads traffic density data and decisions from shared JSON files.
* **Real-time Logic:** Simulates light synchronization for a 4-way intersection.
* **Modular Design:** Independent controller that can be integrated with Arduino/Microcontrollers or physical hardware.

## 🛠 Tech Stack
* **Language:** C++ (Standard 17)
* **Data Interchange:** JSON (using nlohmann/json)
* **Build System:** CMake / G++

## 🔗 Integrated Components
This project works in sync with:
1. `Traffic-Vision` (Python/YOLO) - Vehicle detection.
2. `Traffic-Brain` (AI) - Optimization logic.
3. `Traffic-Dashboard` (Angular) - Real-time monitoring UI.