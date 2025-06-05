#include "process_scanner.hpp"
#include "entropy.hpp"
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <iostream>

std::vector<ProcessInfo> scanRunningProcesses() {
    std::vector<ProcessInfo> results;
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE) return results;

    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(snap, &entry)) {
        do {
            HANDLE hProc = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, entry.th32ProcessID);
            if (hProc) {
                double entropy = calculateMemoryEntropy(hProc);
                ProcessInfo info;
                info.pid = entry.th32ProcessID;
                info.name = entry.szExeFile;
                info.memoryEntropy = entropy;
                info.isSuspicious = entropy > 7.5;
                results.push_back(info);
                CloseHandle(hProc);
            }
        } while (Process32Next(snap, &entry));
    }
    CloseHandle(snap);
    return results;
}