# Microsoft Developer Studio Project File - Name="test.performance.stlsoft.string.string_registry" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=test.performance.stlsoft.string.string_registry - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "test.performance.stlsoft.string.string_registry.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "test.performance.stlsoft.string.string_registry.mak" CFG="test.performance.stlsoft.string.string_registry - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "test.performance.stlsoft.string.string_registry - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "test.performance.stlsoft.string.string_registry - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "test.performance.stlsoft.string.string_registry - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "$(STLSOFT_1_10)/include" /I "$(STLSOFT)/include" /I "$(FASTFORMAT_ROOT)/include" /I "$(RECLS_ROOT)/include" /I "$(PANTHEIOS_ROOT)/include" /I "$(PANTHEIOS_EXTRAS_DIAGUTIL_ROOT)/include" /I "$(PANTHEIOS_EXTRAS_MAIN_ROOT)/include" /I "$(UNIXEM)/include" /D "WIN32" /D "NDEBUG" /D "STRICT" /D "_CONSOLE" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 wininet.lib ws2_32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /version:0.1 /subsystem:console /map /machine:I386 /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(RECLS_ROOT)/lib" /libpath:"$(PANTHEIOS_ROOT)/lib" /libpath:"$(UNIXEM)/lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "test.performance.stlsoft.string.string_registry - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /I "$(STLSOFT_1_10)/include" /I "$(STLSOFT)/include" /I "$(FASTFORMAT_ROOT)/include" /I "$(RECLS_ROOT)/include" /I "$(PANTHEIOS_ROOT)/include" /I "$(PANTHEIOS_EXTRAS_DIAGUTIL_ROOT)/include" /I "$(PANTHEIOS_EXTRAS_MAIN_ROOT)/include" /I "$(UNIXEM)/include" /D "WIN32" /D "_DEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 wininet.lib ws2_32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /version:0.1 /subsystem:console /map /debug /machine:I386 /out:"Debug/test.performance.stlsoft.string.string_registry.debug.exe" /pdbtype:sept /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(RECLS_ROOT)/lib" /libpath:"$(PANTHEIOS_ROOT)/lib" /libpath:"$(UNIXEM)/lib"
# SUBTRACT LINK32 /pdb:none

!ENDIF

# Begin Target

# Name "test.performance.stlsoft.string.string_registry - Win32 Release"
# Name "test.performance.stlsoft.string.string_registry - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\implicit_link.cpp
# End Source File
# Begin Source File

SOURCE=..\test.performance.stlsoft.string.string_registry.cpp
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

SOURCE="$(STLSOFT)\include\stlsoft\memory\allocator_features.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\memory\allocator_selector.hpp"
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

SOURCE="$(STLSOFT)\include\stlsoft\string\copy_functions.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\quality\cover.h"
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

SOURCE="$(STLSOFT_1_10)\include\stlsoft\exception\exceptions.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string\fwd.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\conversion\integer_to_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_bool_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_character_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_floating_point_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_fundamental_type.hpp"
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

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_void_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std\iterator_generators.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std\iterator_helper.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std\library_discriminator.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\limit_traits.h"
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

SOURCE="$(STLSOFT)\include\stlsoft\memory\new_allocator.hpp"
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

SOURCE="$(STLSOFT_1_10)\include\stlsoft\view\transforming\random_access_transforming_view_base.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\smartptr\ref_ptr.hpp"
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

SOURCE="$(STLSOFT)\include\stlsoft\smartptr\shared_ptr.hpp"
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

SOURCE="$(STLSOFT)\include\stlsoft\util\static_initialisers.hpp"
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

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\string\string_registry.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\string\string_slice.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\string_tokeniser.hpp"
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

SOURCE="$(STLSOFT)\include\stlsoft\iterators\transform_iterator.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\stlsoft\conversion\truncation_cast.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\conversion\truncation_test.hpp"
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

SOURCE="$(STLSOFT_1_10)\include\platformstl\filesystem\file_lines.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\filesystem\file_path_buffer.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\filesystem\filesystem_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\performance\performance_counter.hpp"
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

SOURCE="$(STLSOFT)\include\winstl\filesystem\file_path_buffer.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\filesystem\filesystem_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\winstl\filesystem\memory_map_functions.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\winstl\filesystem\handles\memory_mapped_file_view_handle.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\performance\performance_counter.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\memory\processheap_allocator.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT_1_10)\include\winstl\filesystem\readonly_memory_mapped_file.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\synch\spin_mutex.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\system\system_traits.hpp"
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

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\fastformat.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\fastformat.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\ff.hpp"
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

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\sinks\ostream.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\internal\shim_macros.h"
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
# End Group
# Begin Group "Pantheios Header Files"

# PROP Default_Filter ""
# Begin Group "Pantheios::Extras"

# PROP Default_Filter ""
# Begin Group "Pantheios::Extras::DiagUtil"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(PANTHEIOS_EXTRAS_DIAGUTIL_ROOT)\include\pantheios\extras\diagutil\internal\common.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_EXTRAS_DIAGUTIL_ROOT)\include\pantheios\extras\diagutil\internal\common.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_EXTRAS_DIAGUTIL_ROOT)\include\pantheios\extras\diagutil.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_EXTRAS_DIAGUTIL_ROOT)\include\pantheios\extras\diagutil\main_leak_trace.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_EXTRAS_DIAGUTIL_ROOT)\include\pantheios\extras\diagutil\main_leak_trace.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_EXTRAS_DIAGUTIL_ROOT)\include\pantheios\extras\diagutil\internal\stlsoft.h"
# End Source File
# End Group
# Begin Group "Pantheios::Extras::Main"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(PANTHEIOS_EXTRAS_MAIN_ROOT)\include\pantheios\extras\main\internal\common.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_EXTRAS_MAIN_ROOT)\include\pantheios\extras\main\internal\common.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_EXTRAS_MAIN_ROOT)\include\pantheios\extras\main\invoke.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_EXTRAS_MAIN_ROOT)\include\pantheios\extras\main.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_EXTRAS_MAIN_ROOT)\include\pantheios\extras\main\internal\stlsoft.h"
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\util\backends\arguments.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\backend.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\backends\be.N.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\implicit_link\be.N.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\backends\bec.console.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\implicit_link\bec.console.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\backends\bec.WindowsConsole.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\implicit_link\bec.WindowsConsole.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\backends\bec.WindowsDebugger.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\implicit_link\bec.WindowsDebugger.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\backends\bec.WindowsSyslog.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\implicit_link\bec.WindowsSyslog.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\quality\contract.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\implicit_link\core.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\implicit_link\fe.simple.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\inserters\fmt.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\frontend.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\implicit_link\implicit_link_base_.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\internal\initialiser.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\inserters\integer.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\severity\levels.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\internal\generated\log_dispatch_functions.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\internal\generated\log_dispatch_functions.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\internal\generated\log_functions.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\internal\generated\log_functions.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\internal\generated\log_sev_functions.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\pan.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\pantheios.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\pantheios.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\frontends\stock.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\internal\stock_levels.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\internal\string_encoding.h"
# End Source File
# End Group
# Begin Group "recls Header Files"

# PROP Default_Filter ""
# Begin Group "recls/C++"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\cpp\common.hpp"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\cpp\directory_parts.hpp"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\cpp\entry.hpp"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\cpp\exceptions.hpp"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\cpp\ftp_search_sequence.hpp"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\cpp\root_sequence.hpp"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\cpp\search_sequence.hpp"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\cpp\traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\cpp\util.hpp"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\cpp\windows.hpp"
# End Source File
# End Group
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\internal\compiler.h"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\internal\compiler_msvc.h"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\ftp.h"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\implicit_link.h"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\internal\language.h"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\internal\platform.h"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\internal\platform_types.h"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\recls.h"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\recls.hpp"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\internal\recls_filesize.h"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\internal\recls_time.h"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\internal\retcodes.h"
# End Source File
# Begin Source File

SOURCE="$(RECLS_ROOT)\include\recls\internal\safestr.h"
# End Source File
# End Group
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
