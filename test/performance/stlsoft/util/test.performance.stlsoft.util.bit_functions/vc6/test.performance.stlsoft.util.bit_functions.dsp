# Microsoft Developer Studio Project File - Name="test.performance.stlsoft.util.bit_functions" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=test.performance.stlsoft.util.bit_functions - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "test.performance.stlsoft.util.bit_functions.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "test.performance.stlsoft.util.bit_functions.mak" CFG="test.performance.stlsoft.util.bit_functions - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "test.performance.stlsoft.util.bit_functions - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "test.performance.stlsoft.util.bit_functions - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "test.performance.stlsoft.util.bit_functions - Win32 Release"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "$(STLSOFT)/include" /I "$(FASTFORMAT_ROOT)/include" /I "$(PANTHEIOS_ROOT)/include" /I "$(UNIXEM)/include" /D "WIN32" /D "NDEBUG" /D "STRICT" /D "_CONSOLE" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib advapi32.lib  ws2_32.lib  user32.lib  /nologo /version:0.1 /subsystem:console /map /machine:I386 /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(PANTHEIOS_ROOT)/lib" /libpath:"$(UNIXEM)/lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "test.performance.stlsoft.util.bit_functions - Win32 Debug"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /I "$(STLSOFT)/include" /I "$(FASTFORMAT_ROOT)/include" /I "$(PANTHEIOS_ROOT)/include" /I "$(UNIXEM)/include" /D "WIN32" /D "_DEBUG" /D "STRICT" /D "_CONSOLE" /YX /FD /GZ  /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib advapi32.lib  ws2_32.lib  user32.lib  /nologo /version:0.1 /subsystem:console /map /debug /machine:I386 /out:"Debug/test.performance.stlsoft.util.bit_functions.debug.exe" /pdbtype:sept /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(PANTHEIOS_ROOT)/lib" /libpath:"$(UNIXEM)/lib"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "test.performance.stlsoft.util.bit_functions - Win32 Release"
# Name "test.performance.stlsoft.util.bit_functions - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\implicit_link.cpp
# End Source File
# Begin Source File

SOURCE=..\test.performance.stlsoft.util.bit_functions.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
