#include "kernelUtil.h"

extern "C" void _start(BootInfo* bootInfo){

    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = kernelInfo.pageTableManager;

    GlobalRenderer->Print("Kernel Initialized Successfully");
    GlobalRenderer->Next();
    GlobalRenderer->Print("Type help for a list of commands");
    GlobalRenderer->Next();
    GlobalRenderer->Print("ZuimOS:> ");

    while(true);
}