# Microsoft Developer Studio Project File - Name="test.component.winstl.filesystem.resizable_memory_mapped_file" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=test.component.winstl.filesystem.resizable_memory_mapped_file - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "test.component.winstl.filesystem.resizable_memory_mapped_file.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "test.component.winstl.filesystem.resizable_memory_mapped_file.mak" CFG="test.component.winstl.filesystem.resizable_memory_mapped_file - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "test.component.winstl.filesystem.resizable_memory_mapped_file - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "test.component.winstl.filesystem.resizable_memory_mapped_file - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "test.component.winstl.filesystem.resizable_memory_mapped_file - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /c
# ADD CPP /nologo /W3 /WX /GR /GX /O2 /I "$(XTESTS_C_ROOT)/include" /I "$(FASTFORMAT_ROOT)/include" /I "$(STLSOFT_PLUS_1_10)/include" /I "$(STLSOFT_1_10)/include" /I "$(STLSOFT_PLUS)/include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_CONSOLE" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386 /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "test.component.winstl.filesystem.resizable_memory_mapped_file - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /WX /Gm /GR /GX /Zi /Od /I "$(XTESTS_C_ROOT)/include" /I "$(FASTFORMAT_ROOT)/include" /I "$(STLSOFT_PLUS_1_10)/include" /I "$(STLSOFT_1_10)/include" /I "$(STLSOFT_PLUS)/include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_CONSOLE" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib"

!ENDIF

# Begin Target

# Name "test.component.winstl.filesystem.resizable_memory_mapped_file - Win32 Release"
# Name "test.component.winstl.filesystem.resizable_memory_mapped_file - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\implicit_link.cpp
# End Source File
# Begin Source File

SOURCE=..\test.component.winstl.filesystem.resizable_memory_mapped_file.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "STLSoft Header Files"

# PROP Default_Filter ""
# Begin Group "STLSoft"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\memory\allocator_base.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\memory\allocator_features.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\memory\util\allocator_features.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\memory\allocator_selector.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\memory\util\allocator_selector.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\algorithms\std\alt.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\memory\auto_buffer.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string\std\basic_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\algorithms\bounded.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string\std\c_string.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\capabilities.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\case_functions.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\char_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\collections\util\collections.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\synch\concepts.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\constraints.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\quality\contract.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\error\conversion_error.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\quality\cover.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\ctype_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string\std\exception.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\util\exception_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\error\exceptions.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string\fwd.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\head_version.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\conversion\integer_to_string\integer_to_decimal_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\conversion\integer_to_string\integer_to_hexadecimal_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\conversion\integer_to_string\integer_to_octal_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\conversion\integer_to_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\conversion\integer_to_string\integer_to_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\limits\integral_format_width_limits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\limits\integral_limits.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\limits\integral_limits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\traits\integral_printf_format_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_integral_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_pointer_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_same_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_signed_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std\iterator_generators.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std\iterator_helper.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\internal\lead_version.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std\library_discriminator.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\util\limit_traits.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\util\meta_.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\minmax.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\cccap\msvc.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\n_types.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\cccap\obsolete.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\error\os_exception.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\algorithms\pod.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\error\project_exception.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\smartptr\ref_ptr.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\synch\refcount_policies\refcount_policy_single_threaded.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\safestr.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\conversion\sap_cast.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\smartptr\scoped_handle.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\select_first_type_if.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\string\shim_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\sign_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\string\simple_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\size_of.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\size_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\synch\spin_policies.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std_swap.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\stlsoft.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\stlsoft_1_10.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\shims\access\string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\string\string_slice.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\string\string_slice.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\string_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\string_traits_fwd.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\string\string_view.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\error\throw_policies.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string\std\time.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\shims\access\string\std\type_info.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\yesno.hpp"
# End Source File
# End Group
# Begin Group "PlatformSTL"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\synch\atomic_functions.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\synch\atomic_types.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\error\exceptions.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\platformstl.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\platformstl.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\platformstl\platformstl_1_10.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\platformstl\synch\refcount_policies\refcount_policy_multi_threaded.hpp"
# End Source File
# End Group
# Begin Group "WinSTL"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\synch\atomic_functions.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\synch\atomic_types.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\error\error_functions.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\error\exceptions.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\winstl\filesystem\file_creation_functions.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\winstl\filesystem\memory_map_functions.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\winstl\diagnostics\output_debug_line.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\winstl\filesystem\resizable_memory_mapped_file.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\synch\spin_mutex.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\winstl.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\winstl\winstl_1_10.h"
# End Source File
# End Group
# End Group
# Begin Group "FastFormat Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\internal\generated\api_functions.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\quality\contract.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\quality\cover.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\exceptions.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\shims\conversion\filter_type\fast_integers.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\internal\fastformat.c++.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\fastformat.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\fastformat.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\ff.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\sinks\FILE.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\shims\action\fmt_slices\generic_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\internal\generated\helper_functions.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\util\sinks\helpers.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\implicit_link.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\internal\initialiser.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\internal\inserters\int_typedefs.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\inserters\integer.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\sinks\ostream.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\sinks\OutputDebugString.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\shims\access\string\parse_code.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\shims\access\string\replacement_code.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\internal\shim_macros.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\util\string\snprintf.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\format\standard_flags.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\internal\stlsoft.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\internal\string_encoding.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\shims\access\string\string_slice.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\inserters\to_x.hpp"
# End Source File
# End Group
# Begin Group "xTests Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(XTESTS_C_ROOT)\include\xtests\implicit_link.h"
# End Source File
# Begin Source File

SOURCE="$(XTESTS_C_ROOT)\include\xtests\util\temp_file.hpp"
# End Source File
# Begin Source File

SOURCE="$(XTESTS_C_ROOT)\include\xtests\xtests.h"
# End Source File
# End Group
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
