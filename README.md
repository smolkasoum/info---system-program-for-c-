# System Information Tool

A lightweight C++ application that retrieves and displays essential system information on Windows platforms.

## 🚀 Features

- **Processor Architecture Detection** - Identifies x64 (64-bit) or x86 (32-bit) architecture
- **Core Information** - Displays both physical and logical processor core counts
- **Memory Analysis** - Shows total installed RAM in megabytes
- **Windows Native API** - Utilizes Windows system calls for accurate information

## 🛠️ Technical Details

### System Information Retrieved
- Processor architecture (x86/x64)
- Number of physical CPU cores
- Number of logical processors
- Total physical RAM

### Built With
- **C++** - Core programming language
- **Windows API** - System information retrieval
- **SYSTEM_LOGICAL_PROCESSOR_INFORMATION** - Processor topology
- **MEMORYSTATUSEX** - Memory status information

## 📋 Prerequisites

- Windows operating system
- C++ compiler with Windows SDK
- Compatible with both 32-bit and 64-bit systems

## 🔧 Installation & Compilation

1. Clone the repository:
```bash
git clone https://github.com/yourusername/system-info-tool.git
