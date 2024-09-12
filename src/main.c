#include "setup.h"
#include "createservice.h"
#include "tools.h"
#include <processthreadsapi.h>






INT wmain(int argc, WCHAR* argv[]){
    if(argc < 2){
        wprintf(L"usage: isdetect [instruction] [args (optional)]\n\n"
                        L"Example: isdetect --enable => enables the interactive service detection\n"
                        L"isdetect --run taskmgr.exe => starts a service that puts cmd.exe in the interactive service detection\n");
        ExitProcess(1);
    }
    if(!check_if_perms()){
        wprintf(L"please run this as administrator\n");
        ExitProcess(1);
    }

    if(wcscmp(argv[1], L"--enable") == 0) setup_system_for_service();
    else if(wcscmp(argv[1], L"--run") == 0) create_service(argv[2]);
    else wprintf(L"incorrect command\n");
    ExitProcess(0);
}

