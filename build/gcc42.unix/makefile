############################################################################
# File:     build/gcc42.unix/makefile
#
# Purpose:  Makefile for STLSoft 1.10 for GCC 4.2 (UNIX)
#
############################################################################


############################################################################
# Environment

ifndef STLSOFT
$(error STLSOFT must be defined)
endif # !STLSOFT

ifndef XTESTS_C_ROOT
$(error XTESTS_C_ROOT must be defined)
endif # !XTESTS_C_ROOT

############################################################################
# Macros

TEST_VERBOSITY		=	2

INCL_STLSOFT_1_10	=	../../include
INCL_STLSOFT		=	$(STLSOFT)/include
INCL_XTESTS			=	$(XTESTS_C_ROOT)/include
LIB_XTESTS			=	$(XTESTS_C_ROOT)/lib

STLSOFT_INCLUDES	=	-I$(INCL_STLSOFT_1_10) -I$(INCL_STLSOFT)

############################################################################
# Externally-specifiable Targets

default:	build

clean:
	@rm -f *.obj

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
 ..\..\bin\test.component.platformstl.filesystem.file_lines.gcc42.exe\
 ..\..\bin\test.component.platformstl.filesystem.filesystem_traits.1.gcc42.exe\
 ..\..\bin\test.component.platformstl.filesystem.properties_file.gcc42.exe\
 ..\..\bin\test.component.platformstl.filesystem.readdir_sequence.gcc42.exe\
 ..\..\bin\test.component.platformstl.performance.performance_counter.gcc42.exe\
 \

build.component.stlsoft:	check.bin.dir \
 ..\..\bin\test.component.stlsoft.iterator.FILE_iterator.gcc42.exe\
 \

build.component.unixstl:	check.bin.dir \
 ..\..\bin\test.component.unixstl.dl.module.gcc42.exe\
 ..\..\bin\test.component.unixstl.filesystem.memory_map_functions.C.gcc42.exe\
 ..\..\bin\test.component.unixstl.filesystem.memory_map_functions.gcc42.exe\
 \

build.performance.platformstl:	check.bin.dir \
 ..\..\bin\test.component.platformstl.performance.performance_counter.gcc42.exe\
 \

build.performance.stlsoft:	check.bin.dir \
 ..\..\bin\test.performance.stlsoft.conversion.truncation_test.gcc42.exe\
 \

build.performance.unixstl:	check.bin.dir \
 \

build.scratch.platformstl:	check.bin.dir \
 \

build.scratch.stlsoft:	check.bin.dir \
 ..\..\bin\test.scratch.stlsoft.error.error_desc.gcc42.exe\
 ..\..\bin\test.scratch.stlsoft.iterator.associative_select_iterator.gcc42.exe\
 ..\..\bin\test.scratch.stlsoft.smartptr.scoped_handle.gcc42.exe\
 ..\..\bin\test.scratch.stlsoft.util.rand.gcc42.exe\
 \

build.scratch.unixstl:	check.bin.dir \
 \

build.unit.platformstl:	check.bin.dir \
 ..\..\bin\test.unit.platformstl.system.str_set.gcc42.exe\
 \

build.unit.stlsoft:	check.bin.dir \
 ..\..\bin\test.unit.stlsoft.algorithm.literal_copy.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.algorithm.pod.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.collection.edge_case_index_sequence.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.container.fixed_arrays.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.container.frequency_map.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.container.initialised_array.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.container.layered_map.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.container.partially_initialised_array.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.container.pod_vector.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.conversion.integer_to_array.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.conversion.integer_to_hex_string.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.conversion.string_to_integer.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.conversion.truncation_test.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.conversion.union_cast.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.error.error_desc.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.exception.exception_string.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.filesystem.read_line.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.functional.bit_operations.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.iterator.associative_eraser_iterator.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.iterator.associative_select_iterator.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.iterator.eraser_iterator.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.iterator.filter_iterator.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.iterator.preferential_insert_iterator.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.iterator.sorted_eraser_iterator.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.iterator.string_concatenator_iterator.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.iterator.transform_iterator.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.iterator.unsorted_eraser_iterator.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.memory.auto_buffer.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.meta.is_printf_type.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.shims.access.string.std.time.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.smartptr.scoped_handle.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.smartptr.scoped_method.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.smartptr.scoped_ptr.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.smartptr.shared_ptr.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.string.replace_functions.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.string.shim_string.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.string.simple_string.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.string.slice_functions.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.string.split_functions.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.string.static_string.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.string.string_registry.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.string.string_slice.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.string.string_tokeniser.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.string.string_view.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.string.tokeniser_functions.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.tr1.smartptr.scoped_ptr.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.util.bit_functions.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.util.exception_string_creator.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.util.has_bom.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.util.minmax.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.util.must_init.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.util.rand.gcc42.exe\
 ..\..\bin\test.unit.stlsoft.util.string_switch.gcc42.exe\
 \

build.unit.unixstl:	check.bin.dir \
 ..\..\bin\test.unit.unixstl.filesystem.memory_mapped_file.gcc42.exe\
 ..\..\bin\test.unit.unixstl.filesystem.path.gcc42.exe\
 ..\..\bin\test.unit.unixstl.filesystem.readlines.gcc42.exe\
 ..\..\bin\test.unit.unixstl.system.system_traits.2.gcc42.exe\
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
	..\..\bin\test.component.platformstl.filesystem.file_lines.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.platformstl.filesystem.filesystem_traits.1.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.platformstl.filesystem.properties_file.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.platformstl.filesystem.readdir_sequence.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.platformstl.performance.performance_counter.gcc42.exe --verbosity=$(TEST_VERBOSITY)

test.component.stlsoft:	build.component.stlsoft
	@echo Running component tests for stlsoft
	..\..\bin\test.component.stlsoft.iterator.FILE_iterator.gcc42.exe --verbosity=$(TEST_VERBOSITY)

test.component.unixstl:	build.component.unixstl
	@echo Running component tests for unixstl
	..\..\bin\test.component.unixstl.dl.module.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.unixstl.filesystem.memory_map_functions.C.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.unixstl.filesystem.memory_map_functions.gcc42.exe --verbosity=$(TEST_VERBOSITY)

test.performance.platformstl:	build.performance.platformstl
	@echo Running performance tests for platformstl
	..\..\bin\test.component.platformstl.performance.performance_counter.gcc42.exe --verbosity=$(TEST_VERBOSITY)

test.performance.stlsoft:	build.performance.stlsoft
	@echo Running performance tests for stlsoft
	..\..\bin\test.performance.stlsoft.conversion.truncation_test.gcc42.exe --verbosity=$(TEST_VERBOSITY)

test.performance.unixstl:	build.performance.unixstl
	@echo Running performance tests for unixstl

test.scratch.platformstl:	build.scratch.platformstl
	@echo Running scratch tests for platformstl

test.scratch.stlsoft:	build.scratch.stlsoft
	@echo Running scratch tests for stlsoft
	..\..\bin\test.scratch.stlsoft.error.error_desc.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.scratch.stlsoft.iterator.associative_select_iterator.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.scratch.stlsoft.smartptr.scoped_handle.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.scratch.stlsoft.util.rand.gcc42.exe --verbosity=$(TEST_VERBOSITY)

test.scratch.unixstl:	build.scratch.unixstl
	@echo Running scratch tests for unixstl

test.unit.platformstl:	build.unit.platformstl
	@echo Running unit tests for platformstl
	..\..\bin\test.unit.platformstl.system.str_set.gcc42.exe --verbosity=$(TEST_VERBOSITY)

test.unit.stlsoft:	build.unit.stlsoft
	@echo Running unit tests for stlsoft
	..\..\bin\test.unit.stlsoft.algorithm.literal_copy.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.algorithm.pod.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.collection.edge_case_index_sequence.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.fixed_arrays.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.frequency_map.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.initialised_array.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.layered_map.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.partially_initialised_array.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.pod_vector.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.conversion.integer_to_array.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.conversion.integer_to_hex_string.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.conversion.string_to_integer.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.conversion.truncation_test.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.conversion.union_cast.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.error.error_desc.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.exception.exception_string.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.filesystem.read_line.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.functional.bit_operations.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.associative_eraser_iterator.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.associative_select_iterator.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.eraser_iterator.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.filter_iterator.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.preferential_insert_iterator.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.sorted_eraser_iterator.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.string_concatenator_iterator.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.transform_iterator.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.unsorted_eraser_iterator.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.memory.auto_buffer.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.meta.is_printf_type.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.shims.access.string.std.time.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.smartptr.scoped_handle.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.smartptr.scoped_method.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.smartptr.scoped_ptr.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.smartptr.shared_ptr.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.replace_functions.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.shim_string.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.simple_string.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.slice_functions.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.split_functions.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.static_string.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.string_registry.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.string_slice.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.string_tokeniser.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.string_view.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.tokeniser_functions.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.tr1.smartptr.scoped_ptr.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.bit_functions.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.exception_string_creator.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.has_bom.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.minmax.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.must_init.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.rand.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.string_switch.gcc42.exe --verbosity=$(TEST_VERBOSITY)

test.unit.unixstl:	build.unit.unixstl
	@echo Running unit tests for unixstl
	..\..\bin\test.unit.unixstl.filesystem.memory_mapped_file.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.unixstl.filesystem.path.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.unixstl.filesystem.readlines.gcc42.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.unixstl.system.system_traits.2.gcc42.exe --verbosity=$(TEST_VERBOSITY)

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

..\..\bin\test.component.platformstl.filesystem.file_lines.gcc42.exe:	.\test.component.platformstl.filesystem.file_lines.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.component.platformstl.filesystem.file_lines.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.component.platformstl.filesystem.file_lines.obj:	..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.file_lines\test.component.platformstl.filesystem.file_lines.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.file_lines\test.component.platformstl.filesystem.file_lines.cpp

..\..\bin\test.component.platformstl.filesystem.filesystem_traits.1.gcc42.exe:	.\test.component.platformstl.filesystem.filesystem_traits.1.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.component.platformstl.filesystem.filesystem_traits.1.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.component.platformstl.filesystem.filesystem_traits.1.obj:	..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.filesystem_traits.1\test.component.platformstl.filesystem.filesystem_traits.1.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.filesystem_traits.1\test.component.platformstl.filesystem.filesystem_traits.1.cpp

..\..\bin\test.component.platformstl.filesystem.properties_file.gcc42.exe:	.\test.component.platformstl.filesystem.properties_file.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.component.platformstl.filesystem.properties_file.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.component.platformstl.filesystem.properties_file.obj:	..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.properties_file\test.component.platformstl.filesystem.properties_file.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.properties_file\test.component.platformstl.filesystem.properties_file.cpp

..\..\bin\test.component.platformstl.filesystem.readdir_sequence.gcc42.exe:	.\test.component.platformstl.filesystem.readdir_sequence.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.component.platformstl.filesystem.readdir_sequence.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.component.platformstl.filesystem.readdir_sequence.obj:	..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.readdir_sequence\test.component.platformstl.filesystem.readdir_sequence.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.readdir_sequence\test.component.platformstl.filesystem.readdir_sequence.cpp

..\..\bin\test.component.platformstl.performance.performance_counter.gcc42.exe:	.\test.component.platformstl.performance.performance_counter.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.component.platformstl.performance.performance_counter.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.component.platformstl.performance.performance_counter.obj:	..\..\test\component\platformstl\performance\test.component.platformstl.performance.performance_counter\test.component.platformstl.performance.performance_counter.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\component\platformstl\performance\test.component.platformstl.performance.performance_counter\test.component.platformstl.performance.performance_counter.cpp

..\..\bin\test.unit.platformstl.system.str_set.gcc42.exe:	.\test.unit.platformstl.system.str_set.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.platformstl.system.str_set.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.platformstl.system.str_set.obj:	..\..\test\unit\platformstl\system\test.unit.platformstl.system.str_set\test.unit.platformstl.system.str_set.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\platformstl\system\test.unit.platformstl.system.str_set\test.unit.platformstl.system.str_set.cpp


############################################################################
# Internal Targets

########################################
# stlsoft:

..\..\bin\test.component.stlsoft.iterator.FILE_iterator.gcc42.exe:	.\test.component.stlsoft.iterator.FILE_iterator.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.component.stlsoft.iterator.FILE_iterator.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.component.stlsoft.iterator.FILE_iterator.obj:	..\..\test\component\stlsoft\iterator\test.component.stlsoft.iterator.FILE_iterator\test.component.stlsoft.iterator.FILE_iterator.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\component\stlsoft\iterator\test.component.stlsoft.iterator.FILE_iterator\test.component.stlsoft.iterator.FILE_iterator.cpp

..\..\bin\test.performance.stlsoft.conversion.truncation_test.gcc42.exe:	.\test.performance.stlsoft.conversion.truncation_test.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.performance.stlsoft.conversion.truncation_test.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.performance.stlsoft.conversion.truncation_test.obj:	..\..\test\performance\stlsoft\conversion\test.performance.stlsoft.conversion.truncation_test\test.performance.stlsoft.conversion.truncation_test.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\performance\stlsoft\conversion\test.performance.stlsoft.conversion.truncation_test\test.performance.stlsoft.conversion.truncation_test.cpp

..\..\bin\test.scratch.stlsoft.error.error_desc.gcc42.exe:	.\test.scratch.stlsoft.error.error_desc.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.scratch.stlsoft.error.error_desc.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.scratch.stlsoft.error.error_desc.obj:	..\..\test\scratch\stlsoft\error\test.scratch.stlsoft.error.error_desc\test.scratch.stlsoft.error.error_desc.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\scratch\stlsoft\error\test.scratch.stlsoft.error.error_desc\test.scratch.stlsoft.error.error_desc.cpp

..\..\bin\test.scratch.stlsoft.iterator.associative_select_iterator.gcc42.exe:	.\test.scratch.stlsoft.iterator.associative_select_iterator.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.scratch.stlsoft.iterator.associative_select_iterator.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.scratch.stlsoft.iterator.associative_select_iterator.obj:	..\..\test\scratch\stlsoft\iterator\test.scratch.stlsoft.iterator.associative_select_iterator\test.scratch.stlsoft.iterator.associative_select_iterator.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\scratch\stlsoft\iterator\test.scratch.stlsoft.iterator.associative_select_iterator\test.scratch.stlsoft.iterator.associative_select_iterator.cpp

..\..\bin\test.scratch.stlsoft.smartptr.scoped_handle.gcc42.exe:	.\test.scratch.stlsoft.smartptr.scoped_handle.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.scratch.stlsoft.smartptr.scoped_handle.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.scratch.stlsoft.smartptr.scoped_handle.obj:	..\..\test\scratch\stlsoft\smartptr\test.scratch.stlsoft.smartptr.scoped_handle\test.scratch.stlsoft.smartptr.scoped_handle.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\scratch\stlsoft\smartptr\test.scratch.stlsoft.smartptr.scoped_handle\test.scratch.stlsoft.smartptr.scoped_handle.cpp

..\..\bin\test.scratch.stlsoft.util.rand.gcc42.exe:	.\test.scratch.stlsoft.util.rand.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.scratch.stlsoft.util.rand.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.scratch.stlsoft.util.rand.obj:	..\..\test\scratch\stlsoft\util\test.scratch.stlsoft.util.rand\test.scratch.stlsoft.util.rand.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\scratch\stlsoft\util\test.scratch.stlsoft.util.rand\test.scratch.stlsoft.util.rand.cpp

..\..\bin\test.unit.stlsoft.algorithm.literal_copy.gcc42.exe:	.\test.unit.stlsoft.algorithm.literal_copy.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.algorithm.literal_copy.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.algorithm.literal_copy.obj:	..\..\test\unit\stlsoft\algorithm\test.unit.stlsoft.algorithm.literal_copy\test.unit.stlsoft.algorithm.literal_copy.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\algorithm\test.unit.stlsoft.algorithm.literal_copy\test.unit.stlsoft.algorithm.literal_copy.cpp

..\..\bin\test.unit.stlsoft.algorithm.pod.gcc42.exe:	.\test.unit.stlsoft.algorithm.pod.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.algorithm.pod.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.algorithm.pod.obj:	..\..\test\unit\stlsoft\algorithm\test.unit.stlsoft.algorithm.pod\test.unit.stlsoft.algorithm.pod.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\algorithm\test.unit.stlsoft.algorithm.pod\test.unit.stlsoft.algorithm.pod.cpp

..\..\bin\test.unit.stlsoft.collection.edge_case_index_sequence.gcc42.exe:	.\test.unit.stlsoft.collection.edge_case_index_sequence.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.collection.edge_case_index_sequence.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.collection.edge_case_index_sequence.obj:	..\..\test\unit\stlsoft\collection\test.unit.stlsoft.collection.edge_case_index_sequence\test.unit.stlsoft.collection.edge_case_index_sequence.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\collection\test.unit.stlsoft.collection.edge_case_index_sequence\test.unit.stlsoft.collection.edge_case_index_sequence.cpp

..\..\bin\test.unit.stlsoft.container.fixed_arrays.gcc42.exe:	.\test.unit.stlsoft.container.fixed_arrays.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.container.fixed_arrays.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.container.fixed_arrays.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.fixed_arrays\test.unit.stlsoft.container.fixed_arrays.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.fixed_arrays\test.unit.stlsoft.container.fixed_arrays.cpp

..\..\bin\test.unit.stlsoft.container.frequency_map.gcc42.exe:	.\test.unit.stlsoft.container.frequency_map.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.container.frequency_map.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.container.frequency_map.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.frequency_map\test.unit.stlsoft.container.frequency_map.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.frequency_map\test.unit.stlsoft.container.frequency_map.cpp

..\..\bin\test.unit.stlsoft.container.initialised_array.gcc42.exe:	.\test.unit.stlsoft.container.initialised_array.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.container.initialised_array.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.container.initialised_array.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.initialised_array\test.unit.stlsoft.container.initialised_array.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.initialised_array\test.unit.stlsoft.container.initialised_array.cpp

..\..\bin\test.unit.stlsoft.container.layered_map.gcc42.exe:	.\test.unit.stlsoft.container.layered_map.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.container.layered_map.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.container.layered_map.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.layered_map\test.unit.stlsoft.container.layered_map.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.layered_map\test.unit.stlsoft.container.layered_map.cpp

..\..\bin\test.unit.stlsoft.container.partially_initialised_array.gcc42.exe:	.\test.unit.stlsoft.container.partially_initialised_array.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.container.partially_initialised_array.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.container.partially_initialised_array.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.partially_initialised_array\test.unit.stlsoft.container.partially_initialised_array.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.partially_initialised_array\test.unit.stlsoft.container.partially_initialised_array.cpp

..\..\bin\test.unit.stlsoft.container.pod_vector.gcc42.exe:	.\test.unit.stlsoft.container.pod_vector.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.container.pod_vector.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.container.pod_vector.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.pod_vector\test.unit.stlsoft.container.pod_vector.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.pod_vector\test.unit.stlsoft.container.pod_vector.cpp

..\..\bin\test.unit.stlsoft.conversion.integer_to_array.gcc42.exe:	.\test.unit.stlsoft.conversion.integer_to_array.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.conversion.integer_to_array.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.conversion.integer_to_array.obj:	..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.integer_to_array\test.unit.stlsoft.conversion.integer_to_array.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.integer_to_array\test.unit.stlsoft.conversion.integer_to_array.cpp

..\..\bin\test.unit.stlsoft.conversion.integer_to_hex_string.gcc42.exe:	.\test.unit.stlsoft.conversion.integer_to_hex_string.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.conversion.integer_to_hex_string.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.conversion.integer_to_hex_string.obj:	..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.integer_to_hex_string\test.unit.stlsoft.conversion.integer_to_hex_string.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.integer_to_hex_string\test.unit.stlsoft.conversion.integer_to_hex_string.cpp

..\..\bin\test.unit.stlsoft.conversion.string_to_integer.gcc42.exe:	.\test.unit.stlsoft.conversion.string_to_integer.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.conversion.string_to_integer.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.conversion.string_to_integer.obj:	..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.string_to_integer\test.unit.stlsoft.conversion.string_to_integer.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.string_to_integer\test.unit.stlsoft.conversion.string_to_integer.cpp

..\..\bin\test.unit.stlsoft.conversion.truncation_test.gcc42.exe:	.\test.unit.stlsoft.conversion.truncation_test.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.conversion.truncation_test.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.conversion.truncation_test.obj:	..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.truncation_test\test.unit.stlsoft.conversion.truncation_test.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.truncation_test\test.unit.stlsoft.conversion.truncation_test.cpp

..\..\bin\test.unit.stlsoft.conversion.union_cast.gcc42.exe:	.\test.unit.stlsoft.conversion.union_cast.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.conversion.union_cast.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.conversion.union_cast.obj:	..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.union_cast\test.unit.stlsoft.conversion.union_cast.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.union_cast\test.unit.stlsoft.conversion.union_cast.cpp

..\..\bin\test.unit.stlsoft.error.error_desc.gcc42.exe:	.\test.unit.stlsoft.error.error_desc.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.error.error_desc.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.error.error_desc.obj:	..\..\test\unit\stlsoft\error\test.unit.stlsoft.error.error_desc\test.unit.stlsoft.error.error_desc.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\error\test.unit.stlsoft.error.error_desc\test.unit.stlsoft.error.error_desc.cpp

..\..\bin\test.unit.stlsoft.exception.exception_string.gcc42.exe:	.\test.unit.stlsoft.exception.exception_string.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.exception.exception_string.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.exception.exception_string.obj:	..\..\test\unit\stlsoft\exception\test.unit.stlsoft.exception.exception_string\test.unit.stlsoft.exception.exception_string.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\exception\test.unit.stlsoft.exception.exception_string\test.unit.stlsoft.exception.exception_string.cpp

..\..\bin\test.unit.stlsoft.filesystem.read_line.gcc42.exe:	.\test.unit.stlsoft.filesystem.read_line.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.filesystem.read_line.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.filesystem.read_line.obj:	..\..\test\unit\stlsoft\filesystem\test.unit.stlsoft.filesystem.read_line\test.unit.stlsoft.filesystem.read_line.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\filesystem\test.unit.stlsoft.filesystem.read_line\test.unit.stlsoft.filesystem.read_line.cpp

..\..\bin\test.unit.stlsoft.functional.bit_operations.gcc42.exe:	.\test.unit.stlsoft.functional.bit_operations.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.functional.bit_operations.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.functional.bit_operations.obj:	..\..\test\unit\stlsoft\functional\test.unit.stlsoft.functional.bit_operations\test.unit.stlsoft.functional.bit_operations.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\functional\test.unit.stlsoft.functional.bit_operations\test.unit.stlsoft.functional.bit_operations.cpp

..\..\bin\test.unit.stlsoft.iterator.associative_eraser_iterator.gcc42.exe:	.\test.unit.stlsoft.iterator.associative_eraser_iterator.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.iterator.associative_eraser_iterator.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.iterator.associative_eraser_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.associative_eraser_iterator\test.unit.stlsoft.iterator.associative_eraser_iterator.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.associative_eraser_iterator\test.unit.stlsoft.iterator.associative_eraser_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.associative_select_iterator.gcc42.exe:	.\test.unit.stlsoft.iterator.associative_select_iterator.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.iterator.associative_select_iterator.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.iterator.associative_select_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.associative_select_iterator\test.unit.stlsoft.iterator.associative_select_iterator.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.associative_select_iterator\test.unit.stlsoft.iterator.associative_select_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.eraser_iterator.gcc42.exe:	.\test.unit.stlsoft.iterator.eraser_iterator.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.iterator.eraser_iterator.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.iterator.eraser_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.eraser_iterator\test.unit.stlsoft.iterator.eraser_iterator.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.eraser_iterator\test.unit.stlsoft.iterator.eraser_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.filter_iterator.gcc42.exe:	.\test.unit.stlsoft.iterator.filter_iterator.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.iterator.filter_iterator.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.iterator.filter_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.filter_iterator\test.unit.stlsoft.iterator.filter_iterator.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.filter_iterator\test.unit.stlsoft.iterator.filter_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.preferential_insert_iterator.gcc42.exe:	.\test.unit.stlsoft.iterator.preferential_insert_iterator.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.iterator.preferential_insert_iterator.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.iterator.preferential_insert_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.preferential_insert_iterator\test.unit.stlsoft.iterator.preferential_insert_iterator.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.preferential_insert_iterator\test.unit.stlsoft.iterator.preferential_insert_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.sorted_eraser_iterator.gcc42.exe:	.\test.unit.stlsoft.iterator.sorted_eraser_iterator.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.iterator.sorted_eraser_iterator.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.iterator.sorted_eraser_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.sorted_eraser_iterator\test.unit.stlsoft.iterator.sorted_eraser_iterator.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.sorted_eraser_iterator\test.unit.stlsoft.iterator.sorted_eraser_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.string_concatenator_iterator.gcc42.exe:	.\test.unit.stlsoft.iterator.string_concatenator_iterator.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.iterator.string_concatenator_iterator.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.iterator.string_concatenator_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.string_concatenator_iterator\test.unit.stlsoft.iterator.string_concatenator_iterator.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.string_concatenator_iterator\test.unit.stlsoft.iterator.string_concatenator_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.transform_iterator.gcc42.exe:	.\test.unit.stlsoft.iterator.transform_iterator.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.iterator.transform_iterator.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.iterator.transform_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.transform_iterator\test.unit.stlsoft.iterator.transform_iterator.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.transform_iterator\test.unit.stlsoft.iterator.transform_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.unsorted_eraser_iterator.gcc42.exe:	.\test.unit.stlsoft.iterator.unsorted_eraser_iterator.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.iterator.unsorted_eraser_iterator.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.iterator.unsorted_eraser_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.unsorted_eraser_iterator\test.unit.stlsoft.iterator.unsorted_eraser_iterator.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.unsorted_eraser_iterator\test.unit.stlsoft.iterator.unsorted_eraser_iterator.cpp

..\..\bin\test.unit.stlsoft.memory.auto_buffer.gcc42.exe:	.\test.unit.stlsoft.memory.auto_buffer.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.memory.auto_buffer.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.memory.auto_buffer.obj:	..\..\test\unit\stlsoft\memory\test.unit.stlsoft.memory.auto_buffer\test.unit.stlsoft.memory.auto_buffer.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\memory\test.unit.stlsoft.memory.auto_buffer\test.unit.stlsoft.memory.auto_buffer.cpp

..\..\bin\test.unit.stlsoft.meta.is_printf_type.gcc42.exe:	.\test.unit.stlsoft.meta.is_printf_type.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.meta.is_printf_type.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.meta.is_printf_type.obj:	..\..\test\unit\stlsoft\meta\test.unit.stlsoft.meta.is_printf_type\test.unit.stlsoft.meta.is_printf_type.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\meta\test.unit.stlsoft.meta.is_printf_type\test.unit.stlsoft.meta.is_printf_type.cpp

..\..\bin\test.unit.stlsoft.shims.access.string.std.time.gcc42.exe:	.\test.unit.stlsoft.shims.access.string.std.time.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.shims.access.string.std.time.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.shims.access.string.std.time.obj:	..\..\test\unit\stlsoft\shims\access\string\test.unit.stlsoft.shims.access.string.std.time\test.unit.stlsoft.shims.access.string.std.time.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\shims\access\string\test.unit.stlsoft.shims.access.string.std.time\test.unit.stlsoft.shims.access.string.std.time.cpp

..\..\bin\test.unit.stlsoft.smartptr.scoped_handle.gcc42.exe:	.\test.unit.stlsoft.smartptr.scoped_handle.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.smartptr.scoped_handle.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.smartptr.scoped_handle.obj:	..\..\test\unit\stlsoft\smartptr\scoped_handle\test.unit.stlsoft.smartptr.scoped_handle\test.unit.stlsoft.smartptr.scoped_handle.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\smartptr\scoped_handle\test.unit.stlsoft.smartptr.scoped_handle\test.unit.stlsoft.smartptr.scoped_handle.cpp

..\..\bin\test.unit.stlsoft.smartptr.scoped_method.gcc42.exe:	.\test.unit.stlsoft.smartptr.scoped_method.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.smartptr.scoped_method.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.smartptr.scoped_method.obj:	..\..\test\unit\stlsoft\smartptr\scoped_method\test.unit.stlsoft.smartptr.scoped_method\test.unit.stlsoft.smartptr.scoped_method.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\smartptr\scoped_method\test.unit.stlsoft.smartptr.scoped_method\test.unit.stlsoft.smartptr.scoped_method.cpp

..\..\bin\test.unit.stlsoft.smartptr.scoped_ptr.gcc42.exe:	.\test.unit.stlsoft.smartptr.scoped_ptr.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.smartptr.scoped_ptr.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.smartptr.scoped_ptr.obj:	..\..\test\unit\stlsoft\smartptr\scoped_ptr\test.unit.stlsoft.smartptr.scoped_ptr\test.unit.stlsoft.smartptr.scoped_ptr.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\smartptr\scoped_ptr\test.unit.stlsoft.smartptr.scoped_ptr\test.unit.stlsoft.smartptr.scoped_ptr.cpp

..\..\bin\test.unit.stlsoft.smartptr.shared_ptr.gcc42.exe:	.\test.unit.stlsoft.smartptr.shared_ptr.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.smartptr.shared_ptr.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.smartptr.shared_ptr.obj:	..\..\test\unit\stlsoft\smartptr\shared_ptr\test.unit.stlsoft.smartptr.shared_ptr\test.unit.stlsoft.smartptr.shared_ptr.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\smartptr\shared_ptr\test.unit.stlsoft.smartptr.shared_ptr\test.unit.stlsoft.smartptr.shared_ptr.cpp

..\..\bin\test.unit.stlsoft.string.replace_functions.gcc42.exe:	.\test.unit.stlsoft.string.replace_functions.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.string.replace_functions.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.string.replace_functions.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.replace_functions\test.unit.stlsoft.string.replace_functions.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.replace_functions\test.unit.stlsoft.string.replace_functions.cpp

..\..\bin\test.unit.stlsoft.string.shim_string.gcc42.exe:	.\test.unit.stlsoft.string.shim_string.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.string.shim_string.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.string.shim_string.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.shim_string\test.unit.stlsoft.string.shim_string.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.shim_string\test.unit.stlsoft.string.shim_string.cpp

..\..\bin\test.unit.stlsoft.string.simple_string.gcc42.exe:	.\test.unit.stlsoft.string.simple_string.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.string.simple_string.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.string.simple_string.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.simple_string\test.unit.stlsoft.string.simple_string.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.simple_string\test.unit.stlsoft.string.simple_string.cpp

..\..\bin\test.unit.stlsoft.string.slice_functions.gcc42.exe:	.\test.unit.stlsoft.string.slice_functions.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.string.slice_functions.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.string.slice_functions.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.slice_functions\test.unit.stlsoft.string.slice_functions.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.slice_functions\test.unit.stlsoft.string.slice_functions.cpp

..\..\bin\test.unit.stlsoft.string.split_functions.gcc42.exe:	.\test.unit.stlsoft.string.split_functions.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.string.split_functions.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.string.split_functions.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.split_functions\test.unit.stlsoft.string.split_functions.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.split_functions\test.unit.stlsoft.string.split_functions.cpp

..\..\bin\test.unit.stlsoft.string.static_string.gcc42.exe:	.\test.unit.stlsoft.string.static_string.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.string.static_string.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.string.static_string.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.static_string\test.unit.stlsoft.string.static_string.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.static_string\test.unit.stlsoft.string.static_string.cpp

..\..\bin\test.unit.stlsoft.string.string_registry.gcc42.exe:	.\test.unit.stlsoft.string.string_registry.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.string.string_registry.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.string.string_registry.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_registry\test.unit.stlsoft.string.string_registry.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_registry\test.unit.stlsoft.string.string_registry.cpp

..\..\bin\test.unit.stlsoft.string.string_slice.gcc42.exe:	.\test.unit.stlsoft.string.string_slice.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.string.string_slice.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.string.string_slice.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_slice\test.unit.stlsoft.string.string_slice.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_slice\test.unit.stlsoft.string.string_slice.cpp

..\..\bin\test.unit.stlsoft.string.string_tokeniser.gcc42.exe:	.\test.unit.stlsoft.string.string_tokeniser.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.string.string_tokeniser.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.string.string_tokeniser.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_tokeniser\test.unit.stlsoft.string.string_tokeniser.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_tokeniser\test.unit.stlsoft.string.string_tokeniser.cpp

..\..\bin\test.unit.stlsoft.string.string_view.gcc42.exe:	.\test.unit.stlsoft.string.string_view.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.string.string_view.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.string.string_view.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_view\test.unit.stlsoft.string.string_view.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_view\test.unit.stlsoft.string.string_view.cpp

..\..\bin\test.unit.stlsoft.string.tokeniser_functions.gcc42.exe:	.\test.unit.stlsoft.string.tokeniser_functions.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.string.tokeniser_functions.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.string.tokeniser_functions.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.tokeniser_functions\test.unit.stlsoft.string.tokeniser_functions.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.tokeniser_functions\test.unit.stlsoft.string.tokeniser_functions.cpp

..\..\bin\test.unit.stlsoft.tr1.smartptr.scoped_ptr.gcc42.exe:	.\test.unit.stlsoft.tr1.smartptr.scoped_ptr.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.tr1.smartptr.scoped_ptr.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.tr1.smartptr.scoped_ptr.obj:	..\..\test\unit\stlsoft\tr1\smartptr\scoped_ptr\test.unit.stlsoft.tr1.smartptr.scoped_ptr\test.unit.stlsoft.tr1.smartptr.scoped_ptr.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\tr1\smartptr\scoped_ptr\test.unit.stlsoft.tr1.smartptr.scoped_ptr\test.unit.stlsoft.tr1.smartptr.scoped_ptr.cpp

..\..\bin\test.unit.stlsoft.util.bit_functions.gcc42.exe:	.\test.unit.stlsoft.util.bit_functions.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.util.bit_functions.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.util.bit_functions.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.bit_functions\test.unit.stlsoft.util.bit_functions.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.bit_functions\test.unit.stlsoft.util.bit_functions.cpp

..\..\bin\test.unit.stlsoft.util.exception_string_creator.gcc42.exe:	.\test.unit.stlsoft.util.exception_string_creator.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.util.exception_string_creator.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.util.exception_string_creator.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.exception_string_creator\test.unit.stlsoft.util.exception_string_creator.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.exception_string_creator\test.unit.stlsoft.util.exception_string_creator.cpp

..\..\bin\test.unit.stlsoft.util.has_bom.gcc42.exe:	.\test.unit.stlsoft.util.has_bom.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.util.has_bom.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.util.has_bom.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.has_bom\test.unit.stlsoft.util.has_bom.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.has_bom\test.unit.stlsoft.util.has_bom.cpp

..\..\bin\test.unit.stlsoft.util.minmax.gcc42.exe:	.\test.unit.stlsoft.util.minmax.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.util.minmax.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.util.minmax.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.minmax\test.unit.stlsoft.util.minmax.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.minmax\test.unit.stlsoft.util.minmax.cpp

..\..\bin\test.unit.stlsoft.util.must_init.gcc42.exe:	.\test.unit.stlsoft.util.must_init.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.util.must_init.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.util.must_init.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.must_init\test.unit.stlsoft.util.must_init.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.must_init\test.unit.stlsoft.util.must_init.cpp

..\..\bin\test.unit.stlsoft.util.rand.gcc42.exe:	.\test.unit.stlsoft.util.rand.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.util.rand.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.util.rand.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.rand\test.unit.stlsoft.util.rand.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.rand\test.unit.stlsoft.util.rand.cpp

..\..\bin\test.unit.stlsoft.util.string_switch.gcc42.exe:	.\test.unit.stlsoft.util.string_switch.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.stlsoft.util.string_switch.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.stlsoft.util.string_switch.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.string_switch\test.unit.stlsoft.util.string_switch.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.string_switch\test.unit.stlsoft.util.string_switch.cpp


############################################################################
# Internal Targets

########################################
# unixstl:

..\..\bin\test.component.unixstl.dl.module.gcc42.exe:	.\test.component.unixstl.dl.module.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.component.unixstl.dl.module.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.component.unixstl.dl.module.obj:	..\..\test\component\unixstl\dl\test.component.unixstl.dl.module\test.component.unixstl.dl.module.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\component\unixstl\dl\test.component.unixstl.dl.module\test.component.unixstl.dl.module.cpp

..\..\bin\test.component.unixstl.filesystem.memory_map_functions.C.gcc42.exe:	.\test.component.unixstl.filesystem.memory_map_functions.C.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.component.unixstl.filesystem.memory_map_functions.C.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.component.unixstl.filesystem.memory_map_functions.C.obj:	..\..\test\component\unixstl\filesystem\test.component.unixstl.filesystem.memory_map_functions.C\test.component.unixstl.filesystem.memory_map_functions.C.c
	gcc -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\component\unixstl\filesystem\test.component.unixstl.filesystem.memory_map_functions.C\test.component.unixstl.filesystem.memory_map_functions.C.c

..\..\bin\test.component.unixstl.filesystem.memory_map_functions.gcc42.exe:	.\test.component.unixstl.filesystem.memory_map_functions.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.component.unixstl.filesystem.memory_map_functions.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.component.unixstl.filesystem.memory_map_functions.obj:	..\..\test\component\unixstl\filesystem\test.component.unixstl.filesystem.memory_map_functions\test.component.unixstl.filesystem.memory_map_functions.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\component\unixstl\filesystem\test.component.unixstl.filesystem.memory_map_functions\test.component.unixstl.filesystem.memory_map_functions.cpp

..\..\bin\test.unit.unixstl.filesystem.memory_mapped_file.gcc42.exe:	.\test.unit.unixstl.filesystem.memory_mapped_file.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.unixstl.filesystem.memory_mapped_file.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.unixstl.filesystem.memory_mapped_file.obj:	..\..\test\unit\unixstl\filesystem\test.unit.unixstl.filesystem.memory_mapped_file\test.unit.unixstl.filesystem.memory_mapped_file.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\unixstl\filesystem\test.unit.unixstl.filesystem.memory_mapped_file\test.unit.unixstl.filesystem.memory_mapped_file.cpp

..\..\bin\test.unit.unixstl.filesystem.path.gcc42.exe:	.\test.unit.unixstl.filesystem.path.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.unixstl.filesystem.path.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.unixstl.filesystem.path.obj:	..\..\test\unit\unixstl\filesystem\test.unit.unixstl.filesystem.path\test.unit.unixstl.filesystem.path.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\unixstl\filesystem\test.unit.unixstl.filesystem.path\test.unit.unixstl.filesystem.path.cpp

..\..\bin\test.unit.unixstl.filesystem.readlines.gcc42.exe:	.\test.unit.unixstl.filesystem.readlines.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.unixstl.filesystem.readlines.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.unixstl.filesystem.readlines.obj:	..\..\test\unit\unixstl\filesystem\test.unit.unixstl.filesystem.readlines\test.unit.unixstl.filesystem.readlines.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\unixstl\filesystem\test.unit.unixstl.filesystem.readlines\test.unit.unixstl.filesystem.readlines.cpp

..\..\bin\test.unit.unixstl.system.system_traits.2.gcc42.exe:	.\test.unit.unixstl.system.system_traits.2.obj
	g++  -Wl,--library-path $(LIB_XTESTS)    -o $@  .\test.unit.unixstl.system.system_traits.2.obj   -lxtests.0.core.gcc42   -ladvapi32 -lkernel32 -luser32 
.\test.unit.unixstl.system.system_traits.2.obj:	..\..\test\unit\unixstl\system\test.unit.unixstl.system.system_traits.2\test.unit.unixstl.system.system_traits.2.cpp
	g++ -c   -DUNIX         $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -o $@ ..\..\test\unit\unixstl\system\test.unit.unixstl.system.system_traits.2\test.unit.unixstl.system.system_traits.2.cpp

############################################################################
