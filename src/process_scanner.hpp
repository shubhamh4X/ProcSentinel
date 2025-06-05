#pragma once
#include <string>
#include <vector>

struct ProcessInfo {
    int pid;
    std::string name;
    double memoryEntropy;
    bool isSuspicious;
};

std::vector<ProcessInfo> scanRunningProcesses();