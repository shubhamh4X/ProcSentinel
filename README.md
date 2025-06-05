# ProcSentinel 🔒

A lightweight C++ tool to monitor and detect suspicious process behavior based on memory entropy. Inspired by anti-cheat systems and malware scanners.

## 📌 Features
- Lists running processes with PID and name
- Reads memory of each process (1MB sample)
- Calculates Shannon entropy of memory
- Flags suspicious processes (entropy > 7.5)
- Exports to `logs/output.csv`

## 🛠 Build Instructions

### Requirements
- Windows
- CMake
- Visual Studio / MinGW

### Steps
```bash
git clone https://github.com/shubhamh4x/ProcSentinel.git
cd ProcSentinel
mkdir build && cd build
cmake ..
cmake --build .
```

## 📊 Sample Output

| PID | Process Name | Entropy | Suspicious |
|-----|--------------|---------|------------|
| 1234 | explorer.exe | 6.89    | No         |
| 5678 | evilproc.exe | 7.90    | Yes        |

## 📝 License
This project is licensed under the MIT License.
