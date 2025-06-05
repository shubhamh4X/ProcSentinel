#include <iostream>
#include "process_scanner.hpp"
#include "entropy.hpp"
#include "logger.hpp"

int main() {
    std::cout << "[*] ProcSentinel started...\n";
    auto processes = scanRunningProcesses();
    logToCSV(processes);
    std::cout << "[+] Scan completed. Output written to logs/output.csv\n";
    return 0;
}