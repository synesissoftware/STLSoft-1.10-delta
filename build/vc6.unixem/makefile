############################################################################
# File:     build/vc6.unixem/makefile
#
# Purpose:  Makefile for STLSoft 1.10 for Visual C++ 6.0 (UNIXem)
#
############################################################################


############################################################################
# Environment

!ifndef STLSOFT
!error STLSOFT must be defined
!endif # !STLSOFT

!ifndef UNIXEM
!error UNIXEM must be defined
!endif # !UNIXEM

!ifndef XTESTS_C_ROOT
!error XTESTS_C_ROOT must be defined
!endif # !XTESTS_C_ROOT

############################################################################
# Macros

TEST_VERBOSITY		=	2

INCL_STLSOFT_1_10	=	../../include
INCL_STLSOFT		=	$(STLSOFT)/include
INCL_XTESTS			=	$(XTESTS_C_ROOT)/include
LIB_XTESTS			=	$(XTESTS_C_ROOT)/lib
INCL_UNIXEM			=	$(UNIXEM)/include
LIB_UNIXEM			=	$(UNIXEM)/lib

STLSOFT_INCLUDES	=	-I$(INCL_STLSOFT_1_10) -I$(INCL_STLSOFT)

############################################################################
# Externally-specifiable Targets

default:	build

clean:
	@if exist *.obj del /f *.obj

help:
	@echo "make [build | clean | compile | help | test]"

build:	\
 build.unit\
 build.component\
 \

build.all:	\
 build.unit\
 build.component\
 build.performance\
 build.scratch\
\

build.component:	\
 build.component.platformstl\
 build.component.stlsoft\
 build.component.unixstl\
 \

build.unit:	\
 build.unit.platformstl\
 build.unit.stlsoft\
 build.unit.unixstl\
 \

build.performance:	\
 build.performance.platformstl\
 build.performance.stlsoft\
 build.performance.unixstl\
 \

build.scratch:	\
 build.scratch.platformstl\
 build.scratch.stlsoft\
 build.scratch.unixstl\
 \

build.component.platformstl:	check.bin.dir \
 ..\..\bin\test.component.platformstl.filesystem.file_lines.vc6.unixem.exe\
 ..\..\bin\test.component.platformstl.filesystem.filesystem_traits.1.vc6.unixem.exe\
 ..\..\bin\test.component.platformstl.filesystem.properties_file.vc6.unixem.exe\
 ..\..\bin\test.component.platformstl.filesystem.readdir_sequence.vc6.unixem.exe\
 ..\..\bin\test.component.platformstl.performance.performance_counter.vc6.unixem.exe\
 \

build.component.stlsoft:	check.bin.dir \
 ..\..\bin\test.component.stlsoft.iterator.FILE_iterator.vc6.unixem.exe\
 \

build.component.unixstl:	check.bin.dir \
 ..\..\bin\test.component.unixstl.dl.module.vc6.unixem.exe\
 ..\..\bin\test.component.unixstl.filesystem.memory_map_functions.C.vc6.unixem.exe\
 ..\..\bin\test.component.unixstl.filesystem.memory_map_functions.vc6.unixem.exe\
 \

build.performance.platformstl:	check.bin.dir \
 ..\..\bin\test.component.platformstl.performance.performance_counter.vc6.unixem.exe\
 \

build.performance.stlsoft:	check.bin.dir \
 ..\..\bin\test.performance.stlsoft.conversion.truncation_test.vc6.unixem.exe\
 \

build.performance.unixstl:	check.bin.dir \
 \

build.scratch.platformstl:	check.bin.dir \
 \

build.scratch.stlsoft:	check.bin.dir \
 ..\..\bin\test.scratch.stlsoft.error.error_desc.vc6.unixem.exe\
 ..\..\bin\test.scratch.stlsoft.iterator.associative_select_iterator.vc6.unixem.exe\
 ..\..\bin\test.scratch.stlsoft.smartptr.scoped_handle.vc6.unixem.exe\
 ..\..\bin\test.scratch.stlsoft.util.rand.vc6.unixem.exe\
 \

build.scratch.unixstl:	check.bin.dir \
 \

build.unit.platformstl:	check.bin.dir \
 ..\..\bin\test.unit.platformstl.system.str_set.vc6.unixem.exe\
 \

build.unit.stlsoft:	check.bin.dir \
 ..\..\bin\test.unit.stlsoft.algorithm.literal_copy.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.algorithm.pod.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.collection.edge_case_index_sequence.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.container.fixed_arrays.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.container.frequency_map.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.container.initialised_array.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.container.layered_map.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.container.partially_initialised_array.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.container.pod_vector.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.conversion.integer_to_array.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.conversion.integer_to_hex_string.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.conversion.string_to_integer.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.conversion.truncation_test.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.conversion.union_cast.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.error.error_desc.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.exception.exception_string.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.filesystem.read_line.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.functional.bit_operations.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.iterator.associative_eraser_iterator.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.iterator.associative_select_iterator.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.iterator.eraser_iterator.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.iterator.sorted_eraser_iterator.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.iterator.string_concatenator_iterator.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.iterator.transform_iterator.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.iterator.unsorted_eraser_iterator.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.memory.auto_buffer.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.meta.is_printf_type.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.shims.access.string.std.time.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.smartptr.scoped_handle.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.smartptr.scoped_method.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.smartptr.scoped_ptr.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.smartptr.shared_ptr.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.string.replace_functions.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.string.shim_string.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.string.simple_string.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.string.slice_functions.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.string.split_functions.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.string.static_string.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.string.string_registry.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.string.string_slice.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.string.string_tokeniser.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.string.string_view.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.string.tokeniser_functions.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.tr1.smartptr.scoped_ptr.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.util.bit_functions.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.util.exception_string_creator.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.util.has_bom.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.util.minmax.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.util.must_init.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.util.rand.vc6.unixem.exe\
 ..\..\bin\test.unit.stlsoft.util.string_switch.vc6.unixem.exe\
 \

build.unit.unixstl:	check.bin.dir \
 ..\..\bin\test.unit.unixstl.filesystem.memory_mapped_file.vc6.unixem.exe\
 ..\..\bin\test.unit.unixstl.filesystem.path.vc6.unixem.exe\
 ..\..\bin\test.unit.unixstl.filesystem.readlines.vc6.unixem.exe\
 ..\..\bin\test.unit.unixstl.system.system_traits.2.vc6.unixem.exe\
 \


test:	\
 build.unit\
 build.component\
 test.unit\
 test.component\
 \

test.component:	\
 test.component.platformstl\
 test.component.stlsoft\
 test.component.unixstl\
 \

test.unit:	\
 test.unit.platformstl\
 test.unit.stlsoft\
 test.unit.unixstl\
 \

test.performance:	\
 test.performance.platformstl\
 test.performance.stlsoft\
 test.performance.unixstl\
 \

test.scratch:	\
 test.scratch.platformstl\
 test.scratch.stlsoft\
 test.scratch.unixstl\
 \

test.all:	\
 build.all\
 test.unit\
 test.component\
 test.performance\
 test.scratch\
 \

test.component.platformstl:	build.component.platformstl
	@echo Running component tests for platformstl
	..\..\bin\test.component.platformstl.filesystem.file_lines.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.platformstl.filesystem.filesystem_traits.1.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.platformstl.filesystem.properties_file.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.platformstl.filesystem.readdir_sequence.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.platformstl.performance.performance_counter.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)

test.component.stlsoft:	build.component.stlsoft
	@echo Running component tests for stlsoft
	..\..\bin\test.component.stlsoft.iterator.FILE_iterator.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)

test.component.unixstl:	build.component.unixstl
	@echo Running component tests for unixstl
	..\..\bin\test.component.unixstl.dl.module.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.unixstl.filesystem.memory_map_functions.C.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.unixstl.filesystem.memory_map_functions.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)

test.performance.platformstl:	build.performance.platformstl
	@echo Running performance tests for platformstl
	..\..\bin\test.component.platformstl.performance.performance_counter.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)

test.performance.stlsoft:	build.performance.stlsoft
	@echo Running performance tests for stlsoft
	..\..\bin\test.performance.stlsoft.conversion.truncation_test.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)

test.performance.unixstl:	build.performance.unixstl
	@echo Running performance tests for unixstl

test.scratch.platformstl:	build.scratch.platformstl
	@echo Running scratch tests for platformstl

test.scratch.stlsoft:	build.scratch.stlsoft
	@echo Running scratch tests for stlsoft
	..\..\bin\test.scratch.stlsoft.error.error_desc.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.scratch.stlsoft.iterator.associative_select_iterator.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.scratch.stlsoft.smartptr.scoped_handle.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.scratch.stlsoft.util.rand.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)

test.scratch.unixstl:	build.scratch.unixstl
	@echo Running scratch tests for unixstl

test.unit.platformstl:	build.unit.platformstl
	@echo Running unit tests for platformstl
	..\..\bin\test.unit.platformstl.system.str_set.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)

test.unit.stlsoft:	build.unit.stlsoft
	@echo Running unit tests for stlsoft
	..\..\bin\test.unit.stlsoft.algorithm.literal_copy.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.algorithm.pod.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.collection.edge_case_index_sequence.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.fixed_arrays.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.frequency_map.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.initialised_array.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.layered_map.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.partially_initialised_array.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.pod_vector.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.conversion.integer_to_array.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.conversion.integer_to_hex_string.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.conversion.string_to_integer.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.conversion.truncation_test.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.conversion.union_cast.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.error.error_desc.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.exception.exception_string.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.filesystem.read_line.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.functional.bit_operations.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.associative_eraser_iterator.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.associative_select_iterator.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.eraser_iterator.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.sorted_eraser_iterator.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.string_concatenator_iterator.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.transform_iterator.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.unsorted_eraser_iterator.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.memory.auto_buffer.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.meta.is_printf_type.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.shims.access.string.std.time.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.smartptr.scoped_handle.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.smartptr.scoped_method.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.smartptr.scoped_ptr.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.smartptr.shared_ptr.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.replace_functions.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.shim_string.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.simple_string.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.slice_functions.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.split_functions.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.static_string.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.string_registry.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.string_slice.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.string_tokeniser.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.string_view.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.tokeniser_functions.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.tr1.smartptr.scoped_ptr.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.bit_functions.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.exception_string_creator.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.has_bom.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.minmax.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.must_init.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.rand.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.string_switch.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)

test.unit.unixstl:	build.unit.unixstl
	@echo Running unit tests for unixstl
	..\..\bin\test.unit.unixstl.filesystem.memory_mapped_file.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.unixstl.filesystem.path.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.unixstl.filesystem.readlines.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.unixstl.system.system_traits.2.vc6.unixem.exe --verbosity=$(TEST_VERBOSITY)

 \

############################################################################
# Helper Targets

check.lib.dir:              makefile
	@-if not exist ..\..\lib\NUL mkdir ..\..\lib

check.bin.dir:              makefile
	@-if not exist ..\..\bin\NUL mkdir ..\..\bin



############################################################################
# Internal Targets

########################################
# platformstl:

..\..\bin\test.component.platformstl.filesystem.file_lines.vc6.unixem.exe:	.\test.component.platformstl.filesystem.file_lines.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.component.platformstl.filesystem.file_lines.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.component.platformstl.filesystem.file_lines.obj:	..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.file_lines\test.component.platformstl.filesystem.file_lines.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.file_lines\test.component.platformstl.filesystem.file_lines.cpp

..\..\bin\test.component.platformstl.filesystem.filesystem_traits.1.vc6.unixem.exe:	.\test.component.platformstl.filesystem.filesystem_traits.1.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.component.platformstl.filesystem.filesystem_traits.1.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.component.platformstl.filesystem.filesystem_traits.1.obj:	..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.filesystem_traits.1\test.component.platformstl.filesystem.filesystem_traits.1.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.filesystem_traits.1\test.component.platformstl.filesystem.filesystem_traits.1.cpp

..\..\bin\test.component.platformstl.filesystem.properties_file.vc6.unixem.exe:	.\test.component.platformstl.filesystem.properties_file.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.component.platformstl.filesystem.properties_file.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.component.platformstl.filesystem.properties_file.obj:	..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.properties_file\test.component.platformstl.filesystem.properties_file.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.properties_file\test.component.platformstl.filesystem.properties_file.cpp

..\..\bin\test.component.platformstl.filesystem.readdir_sequence.vc6.unixem.exe:	.\test.component.platformstl.filesystem.readdir_sequence.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.component.platformstl.filesystem.readdir_sequence.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.component.platformstl.filesystem.readdir_sequence.obj:	..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.readdir_sequence\test.component.platformstl.filesystem.readdir_sequence.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.readdir_sequence\test.component.platformstl.filesystem.readdir_sequence.cpp

..\..\bin\test.component.platformstl.performance.performance_counter.vc6.unixem.exe:	.\test.component.platformstl.performance.performance_counter.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.component.platformstl.performance.performance_counter.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.component.platformstl.performance.performance_counter.obj:	..\..\test\component\platformstl\performance\test.component.platformstl.performance.performance_counter\test.component.platformstl.performance.performance_counter.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\platformstl\performance\test.component.platformstl.performance.performance_counter\test.component.platformstl.performance.performance_counter.cpp

..\..\bin\test.unit.platformstl.system.str_set.vc6.unixem.exe:	.\test.unit.platformstl.system.str_set.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.platformstl.system.str_set.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.platformstl.system.str_set.obj:	..\..\test\unit\platformstl\system\test.unit.platformstl.system.str_set\test.unit.platformstl.system.str_set.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\platformstl\system\test.unit.platformstl.system.str_set\test.unit.platformstl.system.str_set.cpp


############################################################################
# Internal Targets

########################################
# stlsoft:

..\..\bin\test.component.stlsoft.iterator.FILE_iterator.vc6.unixem.exe:	.\test.component.stlsoft.iterator.FILE_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.component.stlsoft.iterator.FILE_iterator.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.component.stlsoft.iterator.FILE_iterator.obj:	..\..\test\component\stlsoft\iterator\test.component.stlsoft.iterator.FILE_iterator\test.component.stlsoft.iterator.FILE_iterator.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\stlsoft\iterator\test.component.stlsoft.iterator.FILE_iterator\test.component.stlsoft.iterator.FILE_iterator.cpp

..\..\bin\test.performance.stlsoft.conversion.truncation_test.vc6.unixem.exe:	.\test.performance.stlsoft.conversion.truncation_test.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.performance.stlsoft.conversion.truncation_test.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.performance.stlsoft.conversion.truncation_test.obj:	..\..\test\performance\stlsoft\conversion\test.performance.stlsoft.conversion.truncation_test\test.performance.stlsoft.conversion.truncation_test.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\performance\stlsoft\conversion\test.performance.stlsoft.conversion.truncation_test\test.performance.stlsoft.conversion.truncation_test.cpp

..\..\bin\test.scratch.stlsoft.error.error_desc.vc6.unixem.exe:	.\test.scratch.stlsoft.error.error_desc.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.scratch.stlsoft.error.error_desc.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.scratch.stlsoft.error.error_desc.obj:	..\..\test\scratch\stlsoft\error\test.scratch.stlsoft.error.error_desc\test.scratch.stlsoft.error.error_desc.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\scratch\stlsoft\error\test.scratch.stlsoft.error.error_desc\test.scratch.stlsoft.error.error_desc.cpp

..\..\bin\test.scratch.stlsoft.iterator.associative_select_iterator.vc6.unixem.exe:	.\test.scratch.stlsoft.iterator.associative_select_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.scratch.stlsoft.iterator.associative_select_iterator.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.scratch.stlsoft.iterator.associative_select_iterator.obj:	..\..\test\scratch\stlsoft\iterator\test.scratch.stlsoft.iterator.associative_select_iterator\test.scratch.stlsoft.iterator.associative_select_iterator.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\scratch\stlsoft\iterator\test.scratch.stlsoft.iterator.associative_select_iterator\test.scratch.stlsoft.iterator.associative_select_iterator.cpp

..\..\bin\test.scratch.stlsoft.smartptr.scoped_handle.vc6.unixem.exe:	.\test.scratch.stlsoft.smartptr.scoped_handle.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.scratch.stlsoft.smartptr.scoped_handle.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.scratch.stlsoft.smartptr.scoped_handle.obj:	..\..\test\scratch\stlsoft\smartptr\test.scratch.stlsoft.smartptr.scoped_handle\test.scratch.stlsoft.smartptr.scoped_handle.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\scratch\stlsoft\smartptr\test.scratch.stlsoft.smartptr.scoped_handle\test.scratch.stlsoft.smartptr.scoped_handle.cpp

..\..\bin\test.scratch.stlsoft.util.rand.vc6.unixem.exe:	.\test.scratch.stlsoft.util.rand.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.scratch.stlsoft.util.rand.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.scratch.stlsoft.util.rand.obj:	..\..\test\scratch\stlsoft\util\test.scratch.stlsoft.util.rand\test.scratch.stlsoft.util.rand.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\scratch\stlsoft\util\test.scratch.stlsoft.util.rand\test.scratch.stlsoft.util.rand.cpp

..\..\bin\test.unit.stlsoft.algorithm.literal_copy.vc6.unixem.exe:	.\test.unit.stlsoft.algorithm.literal_copy.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.algorithm.literal_copy.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.algorithm.literal_copy.obj:	..\..\test\unit\stlsoft\algorithm\test.unit.stlsoft.algorithm.literal_copy\test.unit.stlsoft.algorithm.literal_copy.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\algorithm\test.unit.stlsoft.algorithm.literal_copy\test.unit.stlsoft.algorithm.literal_copy.cpp

..\..\bin\test.unit.stlsoft.algorithm.pod.vc6.unixem.exe:	.\test.unit.stlsoft.algorithm.pod.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.algorithm.pod.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.algorithm.pod.obj:	..\..\test\unit\stlsoft\algorithm\test.unit.stlsoft.algorithm.pod\test.unit.stlsoft.algorithm.pod.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\algorithm\test.unit.stlsoft.algorithm.pod\test.unit.stlsoft.algorithm.pod.cpp

..\..\bin\test.unit.stlsoft.collection.edge_case_index_sequence.vc6.unixem.exe:	.\test.unit.stlsoft.collection.edge_case_index_sequence.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.collection.edge_case_index_sequence.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.collection.edge_case_index_sequence.obj:	..\..\test\unit\stlsoft\collection\test.unit.stlsoft.collection.edge_case_index_sequence\test.unit.stlsoft.collection.edge_case_index_sequence.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\collection\test.unit.stlsoft.collection.edge_case_index_sequence\test.unit.stlsoft.collection.edge_case_index_sequence.cpp

..\..\bin\test.unit.stlsoft.container.fixed_arrays.vc6.unixem.exe:	.\test.unit.stlsoft.container.fixed_arrays.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.container.fixed_arrays.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.container.fixed_arrays.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.fixed_arrays\test.unit.stlsoft.container.fixed_arrays.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.fixed_arrays\test.unit.stlsoft.container.fixed_arrays.cpp

..\..\bin\test.unit.stlsoft.container.frequency_map.vc6.unixem.exe:	.\test.unit.stlsoft.container.frequency_map.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.container.frequency_map.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.container.frequency_map.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.frequency_map\test.unit.stlsoft.container.frequency_map.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.frequency_map\test.unit.stlsoft.container.frequency_map.cpp

..\..\bin\test.unit.stlsoft.container.initialised_array.vc6.unixem.exe:	.\test.unit.stlsoft.container.initialised_array.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.container.initialised_array.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.container.initialised_array.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.initialised_array\test.unit.stlsoft.container.initialised_array.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.initialised_array\test.unit.stlsoft.container.initialised_array.cpp

..\..\bin\test.unit.stlsoft.container.layered_map.vc6.unixem.exe:	.\test.unit.stlsoft.container.layered_map.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.container.layered_map.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.container.layered_map.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.layered_map\test.unit.stlsoft.container.layered_map.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.layered_map\test.unit.stlsoft.container.layered_map.cpp

..\..\bin\test.unit.stlsoft.container.partially_initialised_array.vc6.unixem.exe:	.\test.unit.stlsoft.container.partially_initialised_array.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.container.partially_initialised_array.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.container.partially_initialised_array.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.partially_initialised_array\test.unit.stlsoft.container.partially_initialised_array.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.partially_initialised_array\test.unit.stlsoft.container.partially_initialised_array.cpp

..\..\bin\test.unit.stlsoft.container.pod_vector.vc6.unixem.exe:	.\test.unit.stlsoft.container.pod_vector.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.container.pod_vector.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.container.pod_vector.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.pod_vector\test.unit.stlsoft.container.pod_vector.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.pod_vector\test.unit.stlsoft.container.pod_vector.cpp

..\..\bin\test.unit.stlsoft.conversion.integer_to_array.vc6.unixem.exe:	.\test.unit.stlsoft.conversion.integer_to_array.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.conversion.integer_to_array.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.conversion.integer_to_array.obj:	..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.integer_to_array\test.unit.stlsoft.conversion.integer_to_array.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.integer_to_array\test.unit.stlsoft.conversion.integer_to_array.cpp

..\..\bin\test.unit.stlsoft.conversion.integer_to_hex_string.vc6.unixem.exe:	.\test.unit.stlsoft.conversion.integer_to_hex_string.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.conversion.integer_to_hex_string.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.conversion.integer_to_hex_string.obj:	..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.integer_to_hex_string\test.unit.stlsoft.conversion.integer_to_hex_string.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.integer_to_hex_string\test.unit.stlsoft.conversion.integer_to_hex_string.cpp

..\..\bin\test.unit.stlsoft.conversion.string_to_integer.vc6.unixem.exe:	.\test.unit.stlsoft.conversion.string_to_integer.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.conversion.string_to_integer.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.conversion.string_to_integer.obj:	..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.string_to_integer\test.unit.stlsoft.conversion.string_to_integer.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.string_to_integer\test.unit.stlsoft.conversion.string_to_integer.cpp

..\..\bin\test.unit.stlsoft.conversion.truncation_test.vc6.unixem.exe:	.\test.unit.stlsoft.conversion.truncation_test.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.conversion.truncation_test.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.conversion.truncation_test.obj:	..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.truncation_test\test.unit.stlsoft.conversion.truncation_test.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.truncation_test\test.unit.stlsoft.conversion.truncation_test.cpp

..\..\bin\test.unit.stlsoft.conversion.union_cast.vc6.unixem.exe:	.\test.unit.stlsoft.conversion.union_cast.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.conversion.union_cast.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.conversion.union_cast.obj:	..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.union_cast\test.unit.stlsoft.conversion.union_cast.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.union_cast\test.unit.stlsoft.conversion.union_cast.cpp

..\..\bin\test.unit.stlsoft.error.error_desc.vc6.unixem.exe:	.\test.unit.stlsoft.error.error_desc.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.error.error_desc.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.error.error_desc.obj:	..\..\test\unit\stlsoft\error\test.unit.stlsoft.error.error_desc\test.unit.stlsoft.error.error_desc.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\error\test.unit.stlsoft.error.error_desc\test.unit.stlsoft.error.error_desc.cpp

..\..\bin\test.unit.stlsoft.exception.exception_string.vc6.unixem.exe:	.\test.unit.stlsoft.exception.exception_string.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.exception.exception_string.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.exception.exception_string.obj:	..\..\test\unit\stlsoft\exception\test.unit.stlsoft.exception.exception_string\test.unit.stlsoft.exception.exception_string.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\exception\test.unit.stlsoft.exception.exception_string\test.unit.stlsoft.exception.exception_string.cpp

..\..\bin\test.unit.stlsoft.filesystem.read_line.vc6.unixem.exe:	.\test.unit.stlsoft.filesystem.read_line.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.filesystem.read_line.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.filesystem.read_line.obj:	..\..\test\unit\stlsoft\filesystem\test.unit.stlsoft.filesystem.read_line\test.unit.stlsoft.filesystem.read_line.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\filesystem\test.unit.stlsoft.filesystem.read_line\test.unit.stlsoft.filesystem.read_line.cpp

..\..\bin\test.unit.stlsoft.functional.bit_operations.vc6.unixem.exe:	.\test.unit.stlsoft.functional.bit_operations.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.functional.bit_operations.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.functional.bit_operations.obj:	..\..\test\unit\stlsoft\functional\test.unit.stlsoft.functional.bit_operations\test.unit.stlsoft.functional.bit_operations.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\functional\test.unit.stlsoft.functional.bit_operations\test.unit.stlsoft.functional.bit_operations.cpp

..\..\bin\test.unit.stlsoft.iterator.associative_eraser_iterator.vc6.unixem.exe:	.\test.unit.stlsoft.iterator.associative_eraser_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.iterator.associative_eraser_iterator.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.iterator.associative_eraser_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.associative_eraser_iterator\test.unit.stlsoft.iterator.associative_eraser_iterator.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.associative_eraser_iterator\test.unit.stlsoft.iterator.associative_eraser_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.associative_select_iterator.vc6.unixem.exe:	.\test.unit.stlsoft.iterator.associative_select_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.iterator.associative_select_iterator.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.iterator.associative_select_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.associative_select_iterator\test.unit.stlsoft.iterator.associative_select_iterator.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.associative_select_iterator\test.unit.stlsoft.iterator.associative_select_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.eraser_iterator.vc6.unixem.exe:	.\test.unit.stlsoft.iterator.eraser_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.iterator.eraser_iterator.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.iterator.eraser_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.eraser_iterator\test.unit.stlsoft.iterator.eraser_iterator.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.eraser_iterator\test.unit.stlsoft.iterator.eraser_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.sorted_eraser_iterator.vc6.unixem.exe:	.\test.unit.stlsoft.iterator.sorted_eraser_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.iterator.sorted_eraser_iterator.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.iterator.sorted_eraser_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.sorted_eraser_iterator\test.unit.stlsoft.iterator.sorted_eraser_iterator.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.sorted_eraser_iterator\test.unit.stlsoft.iterator.sorted_eraser_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.string_concatenator_iterator.vc6.unixem.exe:	.\test.unit.stlsoft.iterator.string_concatenator_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.iterator.string_concatenator_iterator.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.iterator.string_concatenator_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.string_concatenator_iterator\test.unit.stlsoft.iterator.string_concatenator_iterator.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.string_concatenator_iterator\test.unit.stlsoft.iterator.string_concatenator_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.transform_iterator.vc6.unixem.exe:	.\test.unit.stlsoft.iterator.transform_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.iterator.transform_iterator.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.iterator.transform_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.transform_iterator\test.unit.stlsoft.iterator.transform_iterator.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.transform_iterator\test.unit.stlsoft.iterator.transform_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.unsorted_eraser_iterator.vc6.unixem.exe:	.\test.unit.stlsoft.iterator.unsorted_eraser_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.iterator.unsorted_eraser_iterator.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.iterator.unsorted_eraser_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.unsorted_eraser_iterator\test.unit.stlsoft.iterator.unsorted_eraser_iterator.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.unsorted_eraser_iterator\test.unit.stlsoft.iterator.unsorted_eraser_iterator.cpp

..\..\bin\test.unit.stlsoft.memory.auto_buffer.vc6.unixem.exe:	.\test.unit.stlsoft.memory.auto_buffer.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.memory.auto_buffer.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.memory.auto_buffer.obj:	..\..\test\unit\stlsoft\memory\test.unit.stlsoft.memory.auto_buffer\test.unit.stlsoft.memory.auto_buffer.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\memory\test.unit.stlsoft.memory.auto_buffer\test.unit.stlsoft.memory.auto_buffer.cpp

..\..\bin\test.unit.stlsoft.meta.is_printf_type.vc6.unixem.exe:	.\test.unit.stlsoft.meta.is_printf_type.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.meta.is_printf_type.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.meta.is_printf_type.obj:	..\..\test\unit\stlsoft\meta\test.unit.stlsoft.meta.is_printf_type\test.unit.stlsoft.meta.is_printf_type.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\meta\test.unit.stlsoft.meta.is_printf_type\test.unit.stlsoft.meta.is_printf_type.cpp

..\..\bin\test.unit.stlsoft.shims.access.string.std.time.vc6.unixem.exe:	.\test.unit.stlsoft.shims.access.string.std.time.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.shims.access.string.std.time.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.shims.access.string.std.time.obj:	..\..\test\unit\stlsoft\shims\access\string\test.unit.stlsoft.shims.access.string.std.time\test.unit.stlsoft.shims.access.string.std.time.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\shims\access\string\test.unit.stlsoft.shims.access.string.std.time\test.unit.stlsoft.shims.access.string.std.time.cpp

..\..\bin\test.unit.stlsoft.smartptr.scoped_handle.vc6.unixem.exe:	.\test.unit.stlsoft.smartptr.scoped_handle.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.smartptr.scoped_handle.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.smartptr.scoped_handle.obj:	..\..\test\unit\stlsoft\smartptr\scoped_handle\test.unit.stlsoft.smartptr.scoped_handle\test.unit.stlsoft.smartptr.scoped_handle.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\smartptr\scoped_handle\test.unit.stlsoft.smartptr.scoped_handle\test.unit.stlsoft.smartptr.scoped_handle.cpp

..\..\bin\test.unit.stlsoft.smartptr.scoped_method.vc6.unixem.exe:	.\test.unit.stlsoft.smartptr.scoped_method.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.smartptr.scoped_method.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.smartptr.scoped_method.obj:	..\..\test\unit\stlsoft\smartptr\scoped_method\test.unit.stlsoft.smartptr.scoped_method\test.unit.stlsoft.smartptr.scoped_method.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\smartptr\scoped_method\test.unit.stlsoft.smartptr.scoped_method\test.unit.stlsoft.smartptr.scoped_method.cpp

..\..\bin\test.unit.stlsoft.smartptr.scoped_ptr.vc6.unixem.exe:	.\test.unit.stlsoft.smartptr.scoped_ptr.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.smartptr.scoped_ptr.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.smartptr.scoped_ptr.obj:	..\..\test\unit\stlsoft\smartptr\scoped_ptr\test.unit.stlsoft.smartptr.scoped_ptr\test.unit.stlsoft.smartptr.scoped_ptr.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\smartptr\scoped_ptr\test.unit.stlsoft.smartptr.scoped_ptr\test.unit.stlsoft.smartptr.scoped_ptr.cpp

..\..\bin\test.unit.stlsoft.smartptr.shared_ptr.vc6.unixem.exe:	.\test.unit.stlsoft.smartptr.shared_ptr.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.smartptr.shared_ptr.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.smartptr.shared_ptr.obj:	..\..\test\unit\stlsoft\smartptr\shared_ptr\test.unit.stlsoft.smartptr.shared_ptr\test.unit.stlsoft.smartptr.shared_ptr.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\smartptr\shared_ptr\test.unit.stlsoft.smartptr.shared_ptr\test.unit.stlsoft.smartptr.shared_ptr.cpp

..\..\bin\test.unit.stlsoft.string.replace_functions.vc6.unixem.exe:	.\test.unit.stlsoft.string.replace_functions.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.string.replace_functions.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.replace_functions.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.replace_functions\test.unit.stlsoft.string.replace_functions.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.replace_functions\test.unit.stlsoft.string.replace_functions.cpp

..\..\bin\test.unit.stlsoft.string.shim_string.vc6.unixem.exe:	.\test.unit.stlsoft.string.shim_string.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.string.shim_string.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.shim_string.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.shim_string\test.unit.stlsoft.string.shim_string.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.shim_string\test.unit.stlsoft.string.shim_string.cpp

..\..\bin\test.unit.stlsoft.string.simple_string.vc6.unixem.exe:	.\test.unit.stlsoft.string.simple_string.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.string.simple_string.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.simple_string.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.simple_string\test.unit.stlsoft.string.simple_string.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.simple_string\test.unit.stlsoft.string.simple_string.cpp

..\..\bin\test.unit.stlsoft.string.slice_functions.vc6.unixem.exe:	.\test.unit.stlsoft.string.slice_functions.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.string.slice_functions.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.slice_functions.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.slice_functions\test.unit.stlsoft.string.slice_functions.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.slice_functions\test.unit.stlsoft.string.slice_functions.cpp

..\..\bin\test.unit.stlsoft.string.split_functions.vc6.unixem.exe:	.\test.unit.stlsoft.string.split_functions.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.string.split_functions.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.split_functions.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.split_functions\test.unit.stlsoft.string.split_functions.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.split_functions\test.unit.stlsoft.string.split_functions.cpp

..\..\bin\test.unit.stlsoft.string.static_string.vc6.unixem.exe:	.\test.unit.stlsoft.string.static_string.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.string.static_string.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.static_string.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.static_string\test.unit.stlsoft.string.static_string.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.static_string\test.unit.stlsoft.string.static_string.cpp

..\..\bin\test.unit.stlsoft.string.string_registry.vc6.unixem.exe:	.\test.unit.stlsoft.string.string_registry.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.string.string_registry.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.string_registry.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_registry\test.unit.stlsoft.string.string_registry.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_registry\test.unit.stlsoft.string.string_registry.cpp

..\..\bin\test.unit.stlsoft.string.string_slice.vc6.unixem.exe:	.\test.unit.stlsoft.string.string_slice.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.string.string_slice.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.string_slice.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_slice\test.unit.stlsoft.string.string_slice.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_slice\test.unit.stlsoft.string.string_slice.cpp

..\..\bin\test.unit.stlsoft.string.string_tokeniser.vc6.unixem.exe:	.\test.unit.stlsoft.string.string_tokeniser.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.string.string_tokeniser.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.string_tokeniser.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_tokeniser\test.unit.stlsoft.string.string_tokeniser.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_tokeniser\test.unit.stlsoft.string.string_tokeniser.cpp

..\..\bin\test.unit.stlsoft.string.string_view.vc6.unixem.exe:	.\test.unit.stlsoft.string.string_view.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.string.string_view.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.string_view.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_view\test.unit.stlsoft.string.string_view.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_view\test.unit.stlsoft.string.string_view.cpp

..\..\bin\test.unit.stlsoft.string.tokeniser_functions.vc6.unixem.exe:	.\test.unit.stlsoft.string.tokeniser_functions.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.string.tokeniser_functions.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.tokeniser_functions.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.tokeniser_functions\test.unit.stlsoft.string.tokeniser_functions.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.tokeniser_functions\test.unit.stlsoft.string.tokeniser_functions.cpp

..\..\bin\test.unit.stlsoft.tr1.smartptr.scoped_ptr.vc6.unixem.exe:	.\test.unit.stlsoft.tr1.smartptr.scoped_ptr.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.tr1.smartptr.scoped_ptr.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.tr1.smartptr.scoped_ptr.obj:	..\..\test\unit\stlsoft\tr1\smartptr\scoped_ptr\test.unit.stlsoft.tr1.smartptr.scoped_ptr\test.unit.stlsoft.tr1.smartptr.scoped_ptr.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\tr1\smartptr\scoped_ptr\test.unit.stlsoft.tr1.smartptr.scoped_ptr\test.unit.stlsoft.tr1.smartptr.scoped_ptr.cpp

..\..\bin\test.unit.stlsoft.util.bit_functions.vc6.unixem.exe:	.\test.unit.stlsoft.util.bit_functions.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.util.bit_functions.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.util.bit_functions.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.bit_functions\test.unit.stlsoft.util.bit_functions.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.bit_functions\test.unit.stlsoft.util.bit_functions.cpp

..\..\bin\test.unit.stlsoft.util.exception_string_creator.vc6.unixem.exe:	.\test.unit.stlsoft.util.exception_string_creator.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.util.exception_string_creator.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.util.exception_string_creator.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.exception_string_creator\test.unit.stlsoft.util.exception_string_creator.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.exception_string_creator\test.unit.stlsoft.util.exception_string_creator.cpp

..\..\bin\test.unit.stlsoft.util.has_bom.vc6.unixem.exe:	.\test.unit.stlsoft.util.has_bom.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.util.has_bom.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.util.has_bom.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.has_bom\test.unit.stlsoft.util.has_bom.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.has_bom\test.unit.stlsoft.util.has_bom.cpp

..\..\bin\test.unit.stlsoft.util.minmax.vc6.unixem.exe:	.\test.unit.stlsoft.util.minmax.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.util.minmax.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.util.minmax.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.minmax\test.unit.stlsoft.util.minmax.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.minmax\test.unit.stlsoft.util.minmax.cpp

..\..\bin\test.unit.stlsoft.util.must_init.vc6.unixem.exe:	.\test.unit.stlsoft.util.must_init.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.util.must_init.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.util.must_init.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.must_init\test.unit.stlsoft.util.must_init.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.must_init\test.unit.stlsoft.util.must_init.cpp

..\..\bin\test.unit.stlsoft.util.rand.vc6.unixem.exe:	.\test.unit.stlsoft.util.rand.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.util.rand.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.util.rand.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.rand\test.unit.stlsoft.util.rand.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.rand\test.unit.stlsoft.util.rand.cpp

..\..\bin\test.unit.stlsoft.util.string_switch.vc6.unixem.exe:	.\test.unit.stlsoft.util.string_switch.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.stlsoft.util.string_switch.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.util.string_switch.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.string_switch\test.unit.stlsoft.util.string_switch.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.string_switch\test.unit.stlsoft.util.string_switch.cpp


############################################################################
# Internal Targets

########################################
# unixstl:

..\..\bin\test.component.unixstl.dl.module.vc6.unixem.exe:	.\test.component.unixstl.dl.module.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.component.unixstl.dl.module.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.component.unixstl.dl.module.obj:	..\..\test\component\unixstl\dl\test.component.unixstl.dl.module\test.component.unixstl.dl.module.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\unixstl\dl\test.component.unixstl.dl.module\test.component.unixstl.dl.module.cpp

..\..\bin\test.component.unixstl.filesystem.memory_map_functions.C.vc6.unixem.exe:	.\test.component.unixstl.filesystem.memory_map_functions.C.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.component.unixstl.filesystem.memory_map_functions.C.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.component.unixstl.filesystem.memory_map_functions.C.obj:	..\..\test\component\unixstl\filesystem\test.component.unixstl.filesystem.memory_map_functions.C\test.component.unixstl.filesystem.memory_map_functions.C.c
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\unixstl\filesystem\test.component.unixstl.filesystem.memory_map_functions.C\test.component.unixstl.filesystem.memory_map_functions.C.c

..\..\bin\test.component.unixstl.filesystem.memory_map_functions.vc6.unixem.exe:	.\test.component.unixstl.filesystem.memory_map_functions.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.component.unixstl.filesystem.memory_map_functions.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.component.unixstl.filesystem.memory_map_functions.obj:	..\..\test\component\unixstl\filesystem\test.component.unixstl.filesystem.memory_map_functions\test.component.unixstl.filesystem.memory_map_functions.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\unixstl\filesystem\test.component.unixstl.filesystem.memory_map_functions\test.component.unixstl.filesystem.memory_map_functions.cpp

..\..\bin\test.unit.unixstl.filesystem.memory_mapped_file.vc6.unixem.exe:	.\test.unit.unixstl.filesystem.memory_mapped_file.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.unixstl.filesystem.memory_mapped_file.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.unixstl.filesystem.memory_mapped_file.obj:	..\..\test\unit\unixstl\filesystem\test.unit.unixstl.filesystem.memory_mapped_file\test.unit.unixstl.filesystem.memory_mapped_file.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\unixstl\filesystem\test.unit.unixstl.filesystem.memory_mapped_file\test.unit.unixstl.filesystem.memory_mapped_file.cpp

..\..\bin\test.unit.unixstl.filesystem.path.vc6.unixem.exe:	.\test.unit.unixstl.filesystem.path.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.unixstl.filesystem.path.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.unixstl.filesystem.path.obj:	..\..\test\unit\unixstl\filesystem\test.unit.unixstl.filesystem.path\test.unit.unixstl.filesystem.path.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\unixstl\filesystem\test.unit.unixstl.filesystem.path\test.unit.unixstl.filesystem.path.cpp

..\..\bin\test.unit.unixstl.filesystem.readlines.vc6.unixem.exe:	.\test.unit.unixstl.filesystem.readlines.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.unixstl.filesystem.readlines.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.unixstl.filesystem.readlines.obj:	..\..\test\unit\unixstl\filesystem\test.unit.unixstl.filesystem.readlines\test.unit.unixstl.filesystem.readlines.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\unixstl\filesystem\test.unit.unixstl.filesystem.readlines\test.unit.unixstl.filesystem.readlines.cpp

..\..\bin\test.unit.unixstl.system.system_traits.2.vc6.unixem.exe:	.\test.unit.unixstl.system.system_traits.2.obj
	link -nologo -libpath:$(LIB_XTESTS) -libpath:$(LIB_UNIXEM)  -libpath:$(PTHREADS_WIN32)/lib -out:$@ -subsystem:console .\test.unit.unixstl.system.system_traits.2.obj unixem.1.vc6.lib  xtests.0.core.vc6.unix.lib pthreadVC.lib  advapi32.lib kernel32.lib user32.lib 
.\test.unit.unixstl.system.system_traits.2.obj:	..\..\test\unit\unixstl\system\test.unit.unixstl.system.system_traits.2\test.unit.unixstl.system.system_traits.2.cpp
	cl -c -nologo -ML -DUNIX -D_STLSOFT_FORCE_ANY_COMPILER  -O2 -GX -GR -W3 -WX  $(STLSOFT_INCLUDES) -I$(INCL_UNIXEM) -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\unixstl\system\test.unit.unixstl.system.system_traits.2\test.unit.unixstl.system.system_traits.2.cpp

############################################################################
