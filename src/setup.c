#include "setup.h"
#include <processthreadsapi.h>
#include <shellapi.h>
#include <winuser.h>




extern NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);




VOID setup_system_for_service(){
    wprintf(L"Enabling Interactive Services Detection..\n");
    ShellExecuteW(NULL, L"runas", L"reg.exe", L"ADD HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Windows /v NoInteractiveServices /t REG_DWORD /d 0 /f", NULL, SW_HIDE);
    ShellExecuteW(NULL, L"runas", L"sc.exe", L"config ui0detect start= auto", NULL, SW_HIDE);
    wprintf(L"Starting Interactive Services Detection..\n");
    ShellExecuteW(NULL, L"runas", L"sc.exe", L"start ui0detect", NULL, SW_HIDE);
    int result = MessageBoxW(NULL, L"Do you want to restart your machine?", L"ISDETECT.EXE", MB_YESNO);
    if(result == IDYES){
        BOOLEAN result;
        RtlAdjustPrivilege(19L, TRUE, FALSE, &result);
        ExitWindowsEx(EWX_REBOOT, EWX_FORCE);
        ExitProcess(0);
    }
    else ExitProcess(0);
}