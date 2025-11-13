#include<iostream>
#include <windows.h>

int getPhysicalCoreCount() {
    DWORD len = 0;
    GetLogicalProcessorInformation(NULL, &len); // получаем нужный размер буфера

    SYSTEM_LOGICAL_PROCESSOR_INFORMATION* buffer = (SYSTEM_LOGICAL_PROCESSOR_INFORMATION*)malloc(len);
    if (buffer == NULL) return -1;

    if (!GetLogicalProcessorInformation(buffer, &len)) {
        free(buffer);
        return -1;
    }

    int physicalCoreCount = 0;
    DWORD count = len / sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);

    for (DWORD i = 0; i < count; ++i) {
        if (buffer[i].Relationship == RelationProcessorCore) {
            physicalCoreCount++;
        }
    }

    free(buffer);
    return physicalCoreCount;
}


int main ()
{

    SYSTEM_INFO sysInfo;
        MEMORYSTATUSEX memInfo;

    GetSystemInfo(&sysInfo);

    std::cout << "processor architecture : " ;
        if (sysInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64) 
            {
                std::cout << "x64 (64-bit)\n"; }

        else if (sysInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL) 
        {
        std::cout << "x86 (32-bit)\n"; } 

        else 
        std::cout << "404\n";

        int PhysicalCoreCount = getPhysicalCoreCount();

        std::cout << "PhysicalCoreCount :" << PhysicalCoreCount << std::endl;

        std::cout << "number of logical cores : " << sysInfo.dwNumberOfProcessors << std::endl;

        memInfo.dwLength = sizeof(memInfo);

        GlobalMemoryStatusEx(&memInfo);
            std::cout << "RAM : " << memInfo.ullTotalPhys / (1024 * 1024) << " MB\n";

    system("pause");

     return 0;
}