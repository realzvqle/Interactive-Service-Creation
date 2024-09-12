#include "createservice.h"
#include "tools.h"
#include <synchapi.h>
#include <winbase.h>
#include <winsvc.h>





VOID create_service(WCHAR* executable){
    HANDLE hSC = OpenSCManagerW(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if(!hSC){
        ShowFormattedMessageBox(GetLastError());
        ExitProcess(-1);
    }
    HANDLE hService = CreateServiceW(hSC, 
              L"isdetect", 
              L"Interactive Service Detection", 
              SC_MANAGER_ALL_ACCESS, 
              SERVICE_WIN32_OWN_PROCESS | SERVICE_INTERACTIVE_PROCESS, 
              SERVICE_DEMAND_START, 
              SERVICE_ERROR_SEVERE, 
              executable, 
              NULL, NULL, NULL, NULL, NULL);
    if(!hService){
        ShowFormattedMessageBox(GetLastError());
        CloseHandle(hSC);
        ExitProcess(-1);
    }

    StartService(hService, 0, NULL);
    WaitForSingleObject(hService, INFINITE);
    DeleteService(hService);
    CloseHandle(hSC);
}