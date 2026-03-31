#include <iostream>
#include <fstream>
#include "include\nlohmann\json.hpp"
#include <thread>
#include <chrono>

using json = nlohmann::json;

void updateTrafficLights() {
    while (true) {
        std::ifstream file("traffic_data.json");
        
        if (file.is_open()) {
            json data;
            try {
                file >> data; 
                
                int phase = data.value("selected_phase", -1);
                std::string phaseName = data.value("phase_description", "Unknown Phase");
                
                std::cout << "[TRAFFIC CONTROL] Switch to Phase " << phase << ": " << phaseName << std::endl;
                
                if (data.contains("active_lanes")) {
                    std::cout << "Lights turning GREEN for lanes: ";
                    for (auto& lane : data["active_lanes"]) {
                        std::cout << lane << " ";
                    }
                    std::cout << std::endl;
                }
            } 
            catch (json::parse_error& e) {
            }
            file.close();
        } else {
            std::cout << "Waiting for traffic_data.json from AI Brain..." << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main() {
    updateTrafficLights();
    return 0;
}