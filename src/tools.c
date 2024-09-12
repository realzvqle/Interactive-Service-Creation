#include "tools.h"






VOID ShowFormattedMessageBox(DWORD errorCode)
{
    LPVOID lpMsgBuf;

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        errorCode,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf,
        0, NULL);

    MessageBox(
        NULL,
        (LPCTSTR)lpMsgBuf,
        TEXT("Error"),
        MB_OK | MB_ICONERROR);

    LocalFree(lpMsgBuf);
}


BOOL check_if_perms(){
    OFSTRUCT st;
    HFILE file = OpenFile("C:\\Windows\\System32\\idk.sys", &st, OF_CREATE);
    if(file == HFILE_ERROR){
        return FALSE;
    }
    else {
        CloseHandle((HANDLE)file);
        DeleteFileW(L"C:\\Windows\\System32\\idk.sys");
        return TRUE;
    }
}