#include "logger.hpp"
#include <fstream>
#include <filesystem>

void logToCSV(const std::vector<ProcessInfo>& processes) {
    std::filesystem::create_directory("logs");
    std::ofstream file("logs/output.csv");
    file << "PID,Process Name,Entropy,Suspicious\n";
    for (const auto& proc : processes) {
        file << proc.pid << "," << proc.name << "," << proc.memoryEntropy << "," << (proc.isSuspicious ? "Yes" : "No") << "\n";
    }
}