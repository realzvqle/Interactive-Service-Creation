# Interactive Services Creator
Creates an Interactive Service Process in Session 0

Syntax:
```
usage: isdetect [instruction] [args (optional)]
Example: isdetect --enable => enables the interactive service detection
isdetect --run taskmgr.exe => starts a service that puts taskmgr.exe in the interactive service detection
```

Won't work on Windows 10 and Above because they removed the Interactive Service Detection

if you're under windows 10, make sure to have "Interactive Services Detection" enabled

Compile using NMAKE and x64 Native Build Tools for VS2022