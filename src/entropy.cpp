#include "entropy.hpp"
#include <vector>
#include <cmath>

double calculateMemoryEntropy(HANDLE hProcess) {
    std::vector<BYTE> buffer(1024 * 1024);
    SIZE_T bytesRead = 0;
    ReadProcessMemory(hProcess, (LPCVOID)0x00400000, buffer.data(), buffer.size(), &bytesRead);

    if (bytesRead == 0) return 0.0;

    int freq[256] = {0};
    for (SIZE_T i = 0; i < bytesRead; i++) {
        freq[buffer[i]]++;
    }

    double entropy = 0.0;
    for (int i = 0; i < 256; i++) {
        if (freq[i]) {
            double p = (double)freq[i] / bytesRead;
            entropy -= p * log2(p);
        }
    }
    return entropy;
}