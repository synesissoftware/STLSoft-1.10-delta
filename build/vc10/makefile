############################################################################
# File:     build/vc10/makefile
#
# Purpose:  Makefile for STLSoft 1.10 for Visual C++ 10.0
#
############################################################################


############################################################################
# Environment

!ifndef STLSOFT
!error STLSOFT must be defined
!endif # !STLSOFT

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
 build.component.atlstl\
 build.component.comstl\
 build.component.platformstl\
 build.component.stlsoft\
 build.component.winstl\
 \

build.unit:	\
 build.unit.atlstl\
 build.unit.comstl\
 build.unit.platformstl\
 build.unit.stlsoft\
 build.unit.winstl\
 \

build.performance:	\
 build.performance.atlstl\
 build.performance.comstl\
 build.performance.platformstl\
 build.performance.stlsoft\
 build.performance.winstl\
 \

build.scratch:	\
 build.scratch.atlstl\
 build.scratch.comstl\
 build.scratch.platformstl\
 build.scratch.stlsoft\
 build.scratch.winstl\
 \

build.component.atlstl:	check.bin.dir \
 \

build.component.comstl:	check.bin.dir \
 ..\..\bin\test.component.comstl.collections.collection_sequence.vc10.exe\
 \

build.component.platformstl:	check.bin.dir \
 ..\..\bin\test.component.platformstl.filesystem.file_lines.vc10.exe\
 ..\..\bin\test.component.platformstl.filesystem.filesystem_traits.1.vc10.exe\
 ..\..\bin\test.component.platformstl.filesystem.properties_file.vc10.exe\
 ..\..\bin\test.component.platformstl.filesystem.readdir_sequence.vc10.exe\
 ..\..\bin\test.component.platformstl.performance.performance_counter.vc10.exe\
 \

build.component.stlsoft:	check.bin.dir \
 ..\..\bin\test.component.stlsoft.iterator.FILE_iterator.vc10.exe\
 \

build.component.winstl:	check.bin.dir \
 ..\..\bin\test.component.winstl.filesystem.findfile_sequence.vc10.exe\
 ..\..\bin\test.component.winstl.filesystem.hrw_file_lines.vc10.exe\
 ..\..\bin\test.component.winstl.filesystem.memory_map_functions.C.vc10.exe\
 ..\..\bin\test.component.winstl.filesystem.memory_map_functions.vc10.exe\
 ..\..\bin\test.component.winstl.filesystem.memory_mapped_file_view_handle.vc10.exe\
 ..\..\bin\test.component.winstl.filesystem.readonly_memory_mapped_file.vc10.exe\
 ..\..\bin\test.component.winstl.synch.semaphore.vc10.exe\
 ..\..\bin\test.component.winstl.system.console_functions.vc10.exe\
 ..\..\bin\test.component.winstl.system.environment_variable.vc10.exe\
 ..\..\bin\test.component.winstl.system.system_directory.vc10.exe\
 ..\..\bin\test.component.winstl.system.temporary_directory.vc10.exe\
 ..\..\bin\test.component.winstl.system.windows_directory.vc10.exe\
 \

build.performance.atlstl:	check.bin.dir \
 \

build.performance.comstl:	check.bin.dir \
 \

build.performance.platformstl:	check.bin.dir \
 ..\..\bin\test.component.platformstl.performance.performance_counter.vc10.exe\
 \

build.performance.stlsoft:	check.bin.dir \
 ..\..\bin\test.performance.stlsoft.conversion.truncation_test.vc10.exe\
 \

build.performance.winstl:	check.bin.dir \
 ..\..\bin\test.scratch.winstl.performance.threadtimes_counter.vc10.exe\
 \

build.scratch.atlstl:	check.bin.dir \
 \

build.scratch.comstl:	check.bin.dir \
 ..\..\bin\test.scratch.comstl.conversion.interface_cast.vc10.exe\
 ..\..\bin\test.scratch.comstl.conversion.method_cast.vc10.exe\
 \

build.scratch.platformstl:	check.bin.dir \
 \

build.scratch.stlsoft:	check.bin.dir \
 ..\..\bin\test.scratch.stlsoft.error.error_desc.vc10.exe\
 ..\..\bin\test.scratch.stlsoft.iterator.associative_select_iterator.vc10.exe\
 ..\..\bin\test.scratch.stlsoft.smartptr.scoped_handle.vc10.exe\
 ..\..\bin\test.scratch.stlsoft.util.rand.vc10.exe\
 \

build.scratch.winstl:	check.bin.dir \
 ..\..\bin\test.scratch.winstl.performance.threadtimes_counter.vc10.exe\
 \

build.unit.atlstl:	check.bin.dir \
 ..\..\bin\test.unit.atlstl.automation.property_method_helpers.vc10.exe\
 \

build.unit.comstl:	check.bin.dir \
 ..\..\bin\test.unit.comstl.shims.access.string.GUID.vc10.exe\
 ..\..\bin\test.unit.comstl.shims.access.string.VARIANT.vc10.exe\
 ..\..\bin\test.unit.comstl.string.BSTR_functions.C.vc10.exe\
 ..\..\bin\test.unit.comstl.string.BSTR_functions.vc10.exe\
 ..\..\bin\test.unit.comstl.util.GUID_functions.vc10.exe\
 ..\..\bin\test.unit.comstl.util.variant.vc10.exe\
 ..\..\bin\test.unit.comstl.util.VARIANT_functions.vc10.exe\
 \

build.unit.platformstl:	check.bin.dir \
 ..\..\bin\test.unit.platformstl.system.str_set.vc10.exe\
 \

build.unit.stlsoft:	check.bin.dir \
 ..\..\bin\test.unit.stlsoft.algorithm.literal_copy.vc10.exe\
 ..\..\bin\test.unit.stlsoft.algorithm.pod.vc10.exe\
 ..\..\bin\test.unit.stlsoft.collection.edge_case_index_sequence.vc10.exe\
 ..\..\bin\test.unit.stlsoft.container.fixed_arrays.vc10.exe\
 ..\..\bin\test.unit.stlsoft.container.frequency_map.vc10.exe\
 ..\..\bin\test.unit.stlsoft.container.initialised_array.vc10.exe\
 ..\..\bin\test.unit.stlsoft.container.layered_map.vc10.exe\
 ..\..\bin\test.unit.stlsoft.container.partially_initialised_array.vc10.exe\
 ..\..\bin\test.unit.stlsoft.container.pod_vector.vc10.exe\
 ..\..\bin\test.unit.stlsoft.conversion.integer_to_array.vc10.exe\
 ..\..\bin\test.unit.stlsoft.conversion.integer_to_hex_string.vc10.exe\
 ..\..\bin\test.unit.stlsoft.conversion.string_to_integer.vc10.exe\
 ..\..\bin\test.unit.stlsoft.conversion.truncation_test.vc10.exe\
 ..\..\bin\test.unit.stlsoft.conversion.union_cast.vc10.exe\
 ..\..\bin\test.unit.stlsoft.error.error_desc.vc10.exe\
 ..\..\bin\test.unit.stlsoft.exception.exception_string.vc10.exe\
 ..\..\bin\test.unit.stlsoft.filesystem.read_line.vc10.exe\
 ..\..\bin\test.unit.stlsoft.functional.bit_operations.vc10.exe\
 ..\..\bin\test.unit.stlsoft.iterator.associative_eraser_iterator.vc10.exe\
 ..\..\bin\test.unit.stlsoft.iterator.associative_select_iterator.vc10.exe\
 ..\..\bin\test.unit.stlsoft.iterator.eraser_iterator.vc10.exe\
 ..\..\bin\test.unit.stlsoft.iterator.filter_iterator.vc10.exe\
 ..\..\bin\test.unit.stlsoft.iterator.preferential_insert_iterator.vc10.exe\
 ..\..\bin\test.unit.stlsoft.iterator.sorted_eraser_iterator.vc10.exe\
 ..\..\bin\test.unit.stlsoft.iterator.string_concatenator_iterator.vc10.exe\
 ..\..\bin\test.unit.stlsoft.iterator.transform_iterator.vc10.exe\
 ..\..\bin\test.unit.stlsoft.iterator.unsorted_eraser_iterator.vc10.exe\
 ..\..\bin\test.unit.stlsoft.memory.auto_buffer.vc10.exe\
 ..\..\bin\test.unit.stlsoft.meta.is_printf_type.vc10.exe\
 ..\..\bin\test.unit.stlsoft.shims.access.string.std.time.vc10.exe\
 ..\..\bin\test.unit.stlsoft.smartptr.scoped_handle.vc10.exe\
 ..\..\bin\test.unit.stlsoft.smartptr.scoped_method.vc10.exe\
 ..\..\bin\test.unit.stlsoft.smartptr.scoped_ptr.vc10.exe\
 ..\..\bin\test.unit.stlsoft.smartptr.shared_ptr.vc10.exe\
 ..\..\bin\test.unit.stlsoft.string.replace_functions.vc10.exe\
 ..\..\bin\test.unit.stlsoft.string.shim_string.vc10.exe\
 ..\..\bin\test.unit.stlsoft.string.simple_string.vc10.exe\
 ..\..\bin\test.unit.stlsoft.string.slice_functions.vc10.exe\
 ..\..\bin\test.unit.stlsoft.string.split_functions.vc10.exe\
 ..\..\bin\test.unit.stlsoft.string.static_string.vc10.exe\
 ..\..\bin\test.unit.stlsoft.string.string_registry.vc10.exe\
 ..\..\bin\test.unit.stlsoft.string.string_slice.vc10.exe\
 ..\..\bin\test.unit.stlsoft.string.string_tokeniser.vc10.exe\
 ..\..\bin\test.unit.stlsoft.string.string_view.vc10.exe\
 ..\..\bin\test.unit.stlsoft.string.tokeniser_functions.vc10.exe\
 ..\..\bin\test.unit.stlsoft.tr1.smartptr.scoped_ptr.vc10.exe\
 ..\..\bin\test.unit.stlsoft.util.bit_functions.vc10.exe\
 ..\..\bin\test.unit.stlsoft.util.exception_string_creator.vc10.exe\
 ..\..\bin\test.unit.stlsoft.util.has_bom.vc10.exe\
 ..\..\bin\test.unit.stlsoft.util.minmax.vc10.exe\
 ..\..\bin\test.unit.stlsoft.util.must_init.vc10.exe\
 ..\..\bin\test.unit.stlsoft.util.rand.vc10.exe\
 ..\..\bin\test.unit.stlsoft.util.string_switch.vc10.exe\
 \

build.unit.winstl:	check.bin.dir \
 ..\..\bin\test.unit.winstl.filesystem.filesystem_traits.1.vc10.exe\
 ..\..\bin\test.unit.winstl.filesystem.filesystem_traits.2.vc10.exe\
 ..\..\bin\test.unit.winstl.filesystem.findvolume_sequence.vc10.exe\
 ..\..\bin\test.unit.winstl.filesystem.memory_mapped_file.vc10.exe\
 ..\..\bin\test.unit.winstl.filesystem.path.vc10.exe\
 ..\..\bin\test.unit.winstl.filesystem.path_functions.vc10.exe\
 ..\..\bin\test.unit.winstl.registry.reg_delete_tree.vc10.exe\
 ..\..\bin\test.unit.winstl.registry.reg_value.vc10.exe\
 ..\..\bin\test.unit.winstl.synch.w4mo.vc10.exe\
 ..\..\bin\test.unit.winstl.system.commandline_parser.vc10.exe\
 ..\..\bin\test.unit.winstl.system.searchpath_sequence.vc10.exe\
 ..\..\bin\test.unit.winstl.system.system_traits.1.vc10.exe\
 ..\..\bin\test.unit.winstl.system.system_traits.2.vc10.exe\
 \


test:	\
 build.unit\
 build.component\
 test.unit\
 test.component\
 \

test.component:	\
 test.component.atlstl\
 test.component.comstl\
 test.component.platformstl\
 test.component.stlsoft\
 test.component.winstl\
 \

test.unit:	\
 test.unit.atlstl\
 test.unit.comstl\
 test.unit.platformstl\
 test.unit.stlsoft\
 test.unit.winstl\
 \

test.performance:	\
 test.performance.atlstl\
 test.performance.comstl\
 test.performance.platformstl\
 test.performance.stlsoft\
 test.performance.winstl\
 \

test.scratch:	\
 test.scratch.atlstl\
 test.scratch.comstl\
 test.scratch.platformstl\
 test.scratch.stlsoft\
 test.scratch.winstl\
 \

test.all:	\
 build.all\
 test.unit\
 test.component\
 test.performance\
 test.scratch\
 \

test.component.atlstl:	build.component.atlstl
	@echo Running component tests for atlstl

test.component.comstl:	build.component.comstl
	@echo Running component tests for comstl
	..\..\bin\test.component.comstl.collections.collection_sequence.vc10.exe --verbosity=$(TEST_VERBOSITY)

test.component.platformstl:	build.component.platformstl
	@echo Running component tests for platformstl
	..\..\bin\test.component.platformstl.filesystem.file_lines.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.platformstl.filesystem.filesystem_traits.1.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.platformstl.filesystem.properties_file.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.platformstl.filesystem.readdir_sequence.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.platformstl.performance.performance_counter.vc10.exe --verbosity=$(TEST_VERBOSITY)

test.component.stlsoft:	build.component.stlsoft
	@echo Running component tests for stlsoft
	..\..\bin\test.component.stlsoft.iterator.FILE_iterator.vc10.exe --verbosity=$(TEST_VERBOSITY)

test.component.winstl:	build.component.winstl
	@echo Running component tests for winstl
	..\..\bin\test.component.winstl.filesystem.findfile_sequence.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.winstl.filesystem.hrw_file_lines.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.winstl.filesystem.memory_map_functions.C.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.winstl.filesystem.memory_map_functions.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.winstl.filesystem.memory_mapped_file_view_handle.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.winstl.filesystem.readonly_memory_mapped_file.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.winstl.synch.semaphore.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.winstl.system.console_functions.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.winstl.system.environment_variable.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.winstl.system.system_directory.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.winstl.system.temporary_directory.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.component.winstl.system.windows_directory.vc10.exe --verbosity=$(TEST_VERBOSITY)

test.performance.atlstl:	build.performance.atlstl
	@echo Running performance tests for atlstl

test.performance.comstl:	build.performance.comstl
	@echo Running performance tests for comstl

test.performance.platformstl:	build.performance.platformstl
	@echo Running performance tests for platformstl
	..\..\bin\test.component.platformstl.performance.performance_counter.vc10.exe --verbosity=$(TEST_VERBOSITY)

test.performance.stlsoft:	build.performance.stlsoft
	@echo Running performance tests for stlsoft
	..\..\bin\test.performance.stlsoft.conversion.truncation_test.vc10.exe --verbosity=$(TEST_VERBOSITY)

test.performance.winstl:	build.performance.winstl
	@echo Running performance tests for winstl
	..\..\bin\test.scratch.winstl.performance.threadtimes_counter.vc10.exe --verbosity=$(TEST_VERBOSITY)

test.scratch.atlstl:	build.scratch.atlstl
	@echo Running scratch tests for atlstl

test.scratch.comstl:	build.scratch.comstl
	@echo Running scratch tests for comstl
	..\..\bin\test.scratch.comstl.conversion.interface_cast.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.scratch.comstl.conversion.method_cast.vc10.exe --verbosity=$(TEST_VERBOSITY)

test.scratch.platformstl:	build.scratch.platformstl
	@echo Running scratch tests for platformstl

test.scratch.stlsoft:	build.scratch.stlsoft
	@echo Running scratch tests for stlsoft
	..\..\bin\test.scratch.stlsoft.error.error_desc.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.scratch.stlsoft.iterator.associative_select_iterator.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.scratch.stlsoft.smartptr.scoped_handle.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.scratch.stlsoft.util.rand.vc10.exe --verbosity=$(TEST_VERBOSITY)

test.scratch.winstl:	build.scratch.winstl
	@echo Running scratch tests for winstl
	..\..\bin\test.scratch.winstl.performance.threadtimes_counter.vc10.exe --verbosity=$(TEST_VERBOSITY)

test.unit.atlstl:	build.unit.atlstl
	@echo Running unit tests for atlstl
	..\..\bin\test.unit.atlstl.automation.property_method_helpers.vc10.exe --verbosity=$(TEST_VERBOSITY)

test.unit.comstl:	build.unit.comstl
	@echo Running unit tests for comstl
	..\..\bin\test.unit.comstl.shims.access.string.GUID.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.comstl.shims.access.string.VARIANT.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.comstl.string.BSTR_functions.C.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.comstl.string.BSTR_functions.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.comstl.util.GUID_functions.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.comstl.util.variant.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.comstl.util.VARIANT_functions.vc10.exe --verbosity=$(TEST_VERBOSITY)

test.unit.platformstl:	build.unit.platformstl
	@echo Running unit tests for platformstl
	..\..\bin\test.unit.platformstl.system.str_set.vc10.exe --verbosity=$(TEST_VERBOSITY)

test.unit.stlsoft:	build.unit.stlsoft
	@echo Running unit tests for stlsoft
	..\..\bin\test.unit.stlsoft.algorithm.literal_copy.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.algorithm.pod.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.collection.edge_case_index_sequence.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.fixed_arrays.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.frequency_map.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.initialised_array.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.layered_map.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.partially_initialised_array.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.container.pod_vector.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.conversion.integer_to_array.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.conversion.integer_to_hex_string.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.conversion.string_to_integer.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.conversion.truncation_test.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.conversion.union_cast.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.error.error_desc.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.exception.exception_string.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.filesystem.read_line.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.functional.bit_operations.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.associative_eraser_iterator.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.associative_select_iterator.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.eraser_iterator.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.filter_iterator.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.preferential_insert_iterator.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.sorted_eraser_iterator.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.string_concatenator_iterator.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.transform_iterator.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.iterator.unsorted_eraser_iterator.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.memory.auto_buffer.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.meta.is_printf_type.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.shims.access.string.std.time.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.smartptr.scoped_handle.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.smartptr.scoped_method.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.smartptr.scoped_ptr.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.smartptr.shared_ptr.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.replace_functions.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.shim_string.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.simple_string.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.slice_functions.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.split_functions.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.static_string.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.string_registry.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.string_slice.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.string_tokeniser.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.string_view.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.string.tokeniser_functions.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.tr1.smartptr.scoped_ptr.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.bit_functions.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.exception_string_creator.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.has_bom.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.minmax.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.must_init.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.rand.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.stlsoft.util.string_switch.vc10.exe --verbosity=$(TEST_VERBOSITY)

test.unit.winstl:	build.unit.winstl
	@echo Running unit tests for winstl
	..\..\bin\test.unit.winstl.filesystem.filesystem_traits.1.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.winstl.filesystem.filesystem_traits.2.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.winstl.filesystem.findvolume_sequence.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.winstl.filesystem.memory_mapped_file.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.winstl.filesystem.path.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.winstl.filesystem.path_functions.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.winstl.registry.reg_delete_tree.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.winstl.registry.reg_value.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.winstl.synch.w4mo.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.winstl.system.commandline_parser.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.winstl.system.searchpath_sequence.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.winstl.system.system_traits.1.vc10.exe --verbosity=$(TEST_VERBOSITY)
	..\..\bin\test.unit.winstl.system.system_traits.2.vc10.exe --verbosity=$(TEST_VERBOSITY)

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
# atlstl:

..\..\bin\test.unit.atlstl.automation.property_method_helpers.vc10.exe:	.\test.unit.atlstl.automation.property_method_helpers.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.atlstl.automation.property_method_helpers.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib uuid.lib
.\test.unit.atlstl.automation.property_method_helpers.obj:	..\..\test\unit\atlstl\automation\test.unit.atlstl.automation.property_method_helpers\test.unit.atlstl.automation.property_method_helpers.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\atlstl\automation\test.unit.atlstl.automation.property_method_helpers\test.unit.atlstl.automation.property_method_helpers.cpp


############################################################################
# Internal Targets

########################################
# comstl:

..\..\bin\test.component.comstl.collections.collection_sequence.vc10.exe:	.\test.component.comstl.collections.collection_sequence.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.comstl.collections.collection_sequence.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib uuid.lib
.\test.component.comstl.collections.collection_sequence.obj:	..\..\test\component\comstl\collections\test.component.comstl.collections.collection_sequence\test.component.comstl.collections.collection_sequence.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\comstl\collections\test.component.comstl.collections.collection_sequence\test.component.comstl.collections.collection_sequence.cpp

..\..\bin\test.scratch.comstl.conversion.interface_cast.vc10.exe:	.\test.scratch.comstl.conversion.interface_cast.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.scratch.comstl.conversion.interface_cast.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib uuid.lib
.\test.scratch.comstl.conversion.interface_cast.obj:	..\..\test\scratch\comstl\conversion\test.scratch.comstl.conversion.interface_cast\test.scratch.comstl.conversion.interface_cast.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\scratch\comstl\conversion\test.scratch.comstl.conversion.interface_cast\test.scratch.comstl.conversion.interface_cast.cpp

..\..\bin\test.scratch.comstl.conversion.method_cast.vc10.exe:	.\test.scratch.comstl.conversion.method_cast.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.scratch.comstl.conversion.method_cast.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib uuid.lib
.\test.scratch.comstl.conversion.method_cast.obj:	..\..\test\scratch\comstl\conversion\test.scratch.comstl.conversion.method_cast\test.scratch.comstl.conversion.method_cast.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\scratch\comstl\conversion\test.scratch.comstl.conversion.method_cast\test.scratch.comstl.conversion.method_cast.cpp

..\..\bin\test.unit.comstl.shims.access.string.GUID.vc10.exe:	.\test.unit.comstl.shims.access.string.GUID.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.comstl.shims.access.string.GUID.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib uuid.lib
.\test.unit.comstl.shims.access.string.GUID.obj:	..\..\test\unit\comstl\shims\access\string\test.unit.comstl.shims.access.string.guid\test.unit.comstl.shims.access.string.GUID.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\comstl\shims\access\string\test.unit.comstl.shims.access.string.guid\test.unit.comstl.shims.access.string.GUID.cpp

..\..\bin\test.unit.comstl.shims.access.string.VARIANT.vc10.exe:	.\test.unit.comstl.shims.access.string.VARIANT.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.comstl.shims.access.string.VARIANT.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib uuid.lib
.\test.unit.comstl.shims.access.string.VARIANT.obj:	..\..\test\unit\comstl\shims\access\string\test.unit.comstl.shims.access.string.variant\test.unit.comstl.shims.access.string.VARIANT.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\comstl\shims\access\string\test.unit.comstl.shims.access.string.variant\test.unit.comstl.shims.access.string.VARIANT.cpp

..\..\bin\test.unit.comstl.string.BSTR_functions.C.vc10.exe:	.\test.unit.comstl.string.BSTR_functions.C.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.comstl.string.BSTR_functions.C.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib uuid.lib
.\test.unit.comstl.string.BSTR_functions.C.obj:	..\..\test\unit\comstl\string\test.unit.comstl.string.BSTR_functions.C\test.unit.comstl.string.BSTR_functions.C.c
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\comstl\string\test.unit.comstl.string.BSTR_functions.C\test.unit.comstl.string.BSTR_functions.C.c

..\..\bin\test.unit.comstl.string.BSTR_functions.vc10.exe:	.\test.unit.comstl.string.BSTR_functions.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.comstl.string.BSTR_functions.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib uuid.lib
.\test.unit.comstl.string.BSTR_functions.obj:	..\..\test\unit\comstl\string\test.unit.comstl.string.BSTR_functions\test.unit.comstl.string.BSTR_functions.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\comstl\string\test.unit.comstl.string.BSTR_functions\test.unit.comstl.string.BSTR_functions.cpp

..\..\bin\test.unit.comstl.util.GUID_functions.vc10.exe:	.\test.unit.comstl.util.GUID_functions.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.comstl.util.GUID_functions.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib uuid.lib
.\test.unit.comstl.util.GUID_functions.obj:	..\..\test\unit\comstl\util\test.unit.comstl.util.GUID_functions\test.unit.comstl.util.GUID_functions.c
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\comstl\util\test.unit.comstl.util.GUID_functions\test.unit.comstl.util.GUID_functions.c

..\..\bin\test.unit.comstl.util.variant.vc10.exe:	.\test.unit.comstl.util.variant.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.comstl.util.variant.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib uuid.lib
.\test.unit.comstl.util.variant.obj:	..\..\test\unit\comstl\util\test.unit.comstl.util.variant\test.unit.comstl.util.variant.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\comstl\util\test.unit.comstl.util.variant\test.unit.comstl.util.variant.cpp

..\..\bin\test.unit.comstl.util.VARIANT_functions.vc10.exe:	.\test.unit.comstl.util.VARIANT_functions.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.comstl.util.VARIANT_functions.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib uuid.lib
.\test.unit.comstl.util.VARIANT_functions.obj:	..\..\test\unit\comstl\util\test.unit.comstl.util.VARIANT_functions\test.unit.comstl.util.VARIANT_functions.c
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\comstl\util\test.unit.comstl.util.VARIANT_functions\test.unit.comstl.util.VARIANT_functions.c


############################################################################
# Internal Targets

########################################
# platformstl:

..\..\bin\test.component.platformstl.filesystem.file_lines.vc10.exe:	.\test.component.platformstl.filesystem.file_lines.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.platformstl.filesystem.file_lines.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.component.platformstl.filesystem.file_lines.obj:	..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.file_lines\test.component.platformstl.filesystem.file_lines.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.file_lines\test.component.platformstl.filesystem.file_lines.cpp

..\..\bin\test.component.platformstl.filesystem.filesystem_traits.1.vc10.exe:	.\test.component.platformstl.filesystem.filesystem_traits.1.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.platformstl.filesystem.filesystem_traits.1.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.component.platformstl.filesystem.filesystem_traits.1.obj:	..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.filesystem_traits.1\test.component.platformstl.filesystem.filesystem_traits.1.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.filesystem_traits.1\test.component.platformstl.filesystem.filesystem_traits.1.cpp

..\..\bin\test.component.platformstl.filesystem.properties_file.vc10.exe:	.\test.component.platformstl.filesystem.properties_file.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.platformstl.filesystem.properties_file.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.component.platformstl.filesystem.properties_file.obj:	..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.properties_file\test.component.platformstl.filesystem.properties_file.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.properties_file\test.component.platformstl.filesystem.properties_file.cpp

..\..\bin\test.component.platformstl.filesystem.readdir_sequence.vc10.exe:	.\test.component.platformstl.filesystem.readdir_sequence.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.platformstl.filesystem.readdir_sequence.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.component.platformstl.filesystem.readdir_sequence.obj:	..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.readdir_sequence\test.component.platformstl.filesystem.readdir_sequence.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\platformstl\filesystem\test.component.platformstl.filesystem.readdir_sequence\test.component.platformstl.filesystem.readdir_sequence.cpp

..\..\bin\test.component.platformstl.performance.performance_counter.vc10.exe:	.\test.component.platformstl.performance.performance_counter.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.platformstl.performance.performance_counter.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.component.platformstl.performance.performance_counter.obj:	..\..\test\component\platformstl\performance\test.component.platformstl.performance.performance_counter\test.component.platformstl.performance.performance_counter.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\platformstl\performance\test.component.platformstl.performance.performance_counter\test.component.platformstl.performance.performance_counter.cpp

..\..\bin\test.unit.platformstl.system.str_set.vc10.exe:	.\test.unit.platformstl.system.str_set.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.platformstl.system.str_set.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.platformstl.system.str_set.obj:	..\..\test\unit\platformstl\system\test.unit.platformstl.system.str_set\test.unit.platformstl.system.str_set.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\platformstl\system\test.unit.platformstl.system.str_set\test.unit.platformstl.system.str_set.cpp


############################################################################
# Internal Targets

########################################
# stlsoft:

..\..\bin\test.component.stlsoft.iterator.FILE_iterator.vc10.exe:	.\test.component.stlsoft.iterator.FILE_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.stlsoft.iterator.FILE_iterator.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.component.stlsoft.iterator.FILE_iterator.obj:	..\..\test\component\stlsoft\iterator\test.component.stlsoft.iterator.FILE_iterator\test.component.stlsoft.iterator.FILE_iterator.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\stlsoft\iterator\test.component.stlsoft.iterator.FILE_iterator\test.component.stlsoft.iterator.FILE_iterator.cpp

..\..\bin\test.performance.stlsoft.conversion.truncation_test.vc10.exe:	.\test.performance.stlsoft.conversion.truncation_test.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.performance.stlsoft.conversion.truncation_test.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.performance.stlsoft.conversion.truncation_test.obj:	..\..\test\performance\stlsoft\conversion\test.performance.stlsoft.conversion.truncation_test\test.performance.stlsoft.conversion.truncation_test.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\performance\stlsoft\conversion\test.performance.stlsoft.conversion.truncation_test\test.performance.stlsoft.conversion.truncation_test.cpp

..\..\bin\test.scratch.stlsoft.error.error_desc.vc10.exe:	.\test.scratch.stlsoft.error.error_desc.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.scratch.stlsoft.error.error_desc.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.scratch.stlsoft.error.error_desc.obj:	..\..\test\scratch\stlsoft\error\test.scratch.stlsoft.error.error_desc\test.scratch.stlsoft.error.error_desc.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\scratch\stlsoft\error\test.scratch.stlsoft.error.error_desc\test.scratch.stlsoft.error.error_desc.cpp

..\..\bin\test.scratch.stlsoft.iterator.associative_select_iterator.vc10.exe:	.\test.scratch.stlsoft.iterator.associative_select_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.scratch.stlsoft.iterator.associative_select_iterator.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.scratch.stlsoft.iterator.associative_select_iterator.obj:	..\..\test\scratch\stlsoft\iterator\test.scratch.stlsoft.iterator.associative_select_iterator\test.scratch.stlsoft.iterator.associative_select_iterator.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\scratch\stlsoft\iterator\test.scratch.stlsoft.iterator.associative_select_iterator\test.scratch.stlsoft.iterator.associative_select_iterator.cpp

..\..\bin\test.scratch.stlsoft.smartptr.scoped_handle.vc10.exe:	.\test.scratch.stlsoft.smartptr.scoped_handle.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.scratch.stlsoft.smartptr.scoped_handle.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.scratch.stlsoft.smartptr.scoped_handle.obj:	..\..\test\scratch\stlsoft\smartptr\test.scratch.stlsoft.smartptr.scoped_handle\test.scratch.stlsoft.smartptr.scoped_handle.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\scratch\stlsoft\smartptr\test.scratch.stlsoft.smartptr.scoped_handle\test.scratch.stlsoft.smartptr.scoped_handle.cpp

..\..\bin\test.scratch.stlsoft.util.rand.vc10.exe:	.\test.scratch.stlsoft.util.rand.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.scratch.stlsoft.util.rand.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.scratch.stlsoft.util.rand.obj:	..\..\test\scratch\stlsoft\util\test.scratch.stlsoft.util.rand\test.scratch.stlsoft.util.rand.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\scratch\stlsoft\util\test.scratch.stlsoft.util.rand\test.scratch.stlsoft.util.rand.cpp

..\..\bin\test.unit.stlsoft.algorithm.literal_copy.vc10.exe:	.\test.unit.stlsoft.algorithm.literal_copy.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.algorithm.literal_copy.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.algorithm.literal_copy.obj:	..\..\test\unit\stlsoft\algorithm\test.unit.stlsoft.algorithm.literal_copy\test.unit.stlsoft.algorithm.literal_copy.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\algorithm\test.unit.stlsoft.algorithm.literal_copy\test.unit.stlsoft.algorithm.literal_copy.cpp

..\..\bin\test.unit.stlsoft.algorithm.pod.vc10.exe:	.\test.unit.stlsoft.algorithm.pod.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.algorithm.pod.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.algorithm.pod.obj:	..\..\test\unit\stlsoft\algorithm\test.unit.stlsoft.algorithm.pod\test.unit.stlsoft.algorithm.pod.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\algorithm\test.unit.stlsoft.algorithm.pod\test.unit.stlsoft.algorithm.pod.cpp

..\..\bin\test.unit.stlsoft.collection.edge_case_index_sequence.vc10.exe:	.\test.unit.stlsoft.collection.edge_case_index_sequence.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.collection.edge_case_index_sequence.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.collection.edge_case_index_sequence.obj:	..\..\test\unit\stlsoft\collection\test.unit.stlsoft.collection.edge_case_index_sequence\test.unit.stlsoft.collection.edge_case_index_sequence.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\collection\test.unit.stlsoft.collection.edge_case_index_sequence\test.unit.stlsoft.collection.edge_case_index_sequence.cpp

..\..\bin\test.unit.stlsoft.container.fixed_arrays.vc10.exe:	.\test.unit.stlsoft.container.fixed_arrays.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.container.fixed_arrays.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.container.fixed_arrays.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.fixed_arrays\test.unit.stlsoft.container.fixed_arrays.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.fixed_arrays\test.unit.stlsoft.container.fixed_arrays.cpp

..\..\bin\test.unit.stlsoft.container.frequency_map.vc10.exe:	.\test.unit.stlsoft.container.frequency_map.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.container.frequency_map.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.container.frequency_map.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.frequency_map\test.unit.stlsoft.container.frequency_map.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.frequency_map\test.unit.stlsoft.container.frequency_map.cpp

..\..\bin\test.unit.stlsoft.container.initialised_array.vc10.exe:	.\test.unit.stlsoft.container.initialised_array.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.container.initialised_array.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.container.initialised_array.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.initialised_array\test.unit.stlsoft.container.initialised_array.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.initialised_array\test.unit.stlsoft.container.initialised_array.cpp

..\..\bin\test.unit.stlsoft.container.layered_map.vc10.exe:	.\test.unit.stlsoft.container.layered_map.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.container.layered_map.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.container.layered_map.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.layered_map\test.unit.stlsoft.container.layered_map.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.layered_map\test.unit.stlsoft.container.layered_map.cpp

..\..\bin\test.unit.stlsoft.container.partially_initialised_array.vc10.exe:	.\test.unit.stlsoft.container.partially_initialised_array.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.container.partially_initialised_array.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.container.partially_initialised_array.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.partially_initialised_array\test.unit.stlsoft.container.partially_initialised_array.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.partially_initialised_array\test.unit.stlsoft.container.partially_initialised_array.cpp

..\..\bin\test.unit.stlsoft.container.pod_vector.vc10.exe:	.\test.unit.stlsoft.container.pod_vector.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.container.pod_vector.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.container.pod_vector.obj:	..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.pod_vector\test.unit.stlsoft.container.pod_vector.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\container\test.unit.stlsoft.container.pod_vector\test.unit.stlsoft.container.pod_vector.cpp

..\..\bin\test.unit.stlsoft.conversion.integer_to_array.vc10.exe:	.\test.unit.stlsoft.conversion.integer_to_array.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.conversion.integer_to_array.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.conversion.integer_to_array.obj:	..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.integer_to_array\test.unit.stlsoft.conversion.integer_to_array.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.integer_to_array\test.unit.stlsoft.conversion.integer_to_array.cpp

..\..\bin\test.unit.stlsoft.conversion.integer_to_hex_string.vc10.exe:	.\test.unit.stlsoft.conversion.integer_to_hex_string.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.conversion.integer_to_hex_string.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.conversion.integer_to_hex_string.obj:	..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.integer_to_hex_string\test.unit.stlsoft.conversion.integer_to_hex_string.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.integer_to_hex_string\test.unit.stlsoft.conversion.integer_to_hex_string.cpp

..\..\bin\test.unit.stlsoft.conversion.string_to_integer.vc10.exe:	.\test.unit.stlsoft.conversion.string_to_integer.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.conversion.string_to_integer.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.conversion.string_to_integer.obj:	..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.string_to_integer\test.unit.stlsoft.conversion.string_to_integer.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.string_to_integer\test.unit.stlsoft.conversion.string_to_integer.cpp

..\..\bin\test.unit.stlsoft.conversion.truncation_test.vc10.exe:	.\test.unit.stlsoft.conversion.truncation_test.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.conversion.truncation_test.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.conversion.truncation_test.obj:	..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.truncation_test\test.unit.stlsoft.conversion.truncation_test.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.truncation_test\test.unit.stlsoft.conversion.truncation_test.cpp

..\..\bin\test.unit.stlsoft.conversion.union_cast.vc10.exe:	.\test.unit.stlsoft.conversion.union_cast.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.conversion.union_cast.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.conversion.union_cast.obj:	..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.union_cast\test.unit.stlsoft.conversion.union_cast.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\conversion\test.unit.stlsoft.conversion.union_cast\test.unit.stlsoft.conversion.union_cast.cpp

..\..\bin\test.unit.stlsoft.error.error_desc.vc10.exe:	.\test.unit.stlsoft.error.error_desc.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.error.error_desc.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.error.error_desc.obj:	..\..\test\unit\stlsoft\error\test.unit.stlsoft.error.error_desc\test.unit.stlsoft.error.error_desc.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\error\test.unit.stlsoft.error.error_desc\test.unit.stlsoft.error.error_desc.cpp

..\..\bin\test.unit.stlsoft.exception.exception_string.vc10.exe:	.\test.unit.stlsoft.exception.exception_string.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.exception.exception_string.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.exception.exception_string.obj:	..\..\test\unit\stlsoft\exception\test.unit.stlsoft.exception.exception_string\test.unit.stlsoft.exception.exception_string.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\exception\test.unit.stlsoft.exception.exception_string\test.unit.stlsoft.exception.exception_string.cpp

..\..\bin\test.unit.stlsoft.filesystem.read_line.vc10.exe:	.\test.unit.stlsoft.filesystem.read_line.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.filesystem.read_line.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.filesystem.read_line.obj:	..\..\test\unit\stlsoft\filesystem\test.unit.stlsoft.filesystem.read_line\test.unit.stlsoft.filesystem.read_line.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\filesystem\test.unit.stlsoft.filesystem.read_line\test.unit.stlsoft.filesystem.read_line.cpp

..\..\bin\test.unit.stlsoft.functional.bit_operations.vc10.exe:	.\test.unit.stlsoft.functional.bit_operations.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.functional.bit_operations.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.functional.bit_operations.obj:	..\..\test\unit\stlsoft\functional\test.unit.stlsoft.functional.bit_operations\test.unit.stlsoft.functional.bit_operations.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\functional\test.unit.stlsoft.functional.bit_operations\test.unit.stlsoft.functional.bit_operations.cpp

..\..\bin\test.unit.stlsoft.iterator.associative_eraser_iterator.vc10.exe:	.\test.unit.stlsoft.iterator.associative_eraser_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.iterator.associative_eraser_iterator.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.iterator.associative_eraser_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.associative_eraser_iterator\test.unit.stlsoft.iterator.associative_eraser_iterator.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.associative_eraser_iterator\test.unit.stlsoft.iterator.associative_eraser_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.associative_select_iterator.vc10.exe:	.\test.unit.stlsoft.iterator.associative_select_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.iterator.associative_select_iterator.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.iterator.associative_select_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.associative_select_iterator\test.unit.stlsoft.iterator.associative_select_iterator.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.associative_select_iterator\test.unit.stlsoft.iterator.associative_select_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.eraser_iterator.vc10.exe:	.\test.unit.stlsoft.iterator.eraser_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.iterator.eraser_iterator.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.iterator.eraser_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.eraser_iterator\test.unit.stlsoft.iterator.eraser_iterator.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.eraser_iterator\test.unit.stlsoft.iterator.eraser_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.filter_iterator.vc10.exe:	.\test.unit.stlsoft.iterator.filter_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.iterator.filter_iterator.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.iterator.filter_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.filter_iterator\test.unit.stlsoft.iterator.filter_iterator.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.filter_iterator\test.unit.stlsoft.iterator.filter_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.preferential_insert_iterator.vc10.exe:	.\test.unit.stlsoft.iterator.preferential_insert_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.iterator.preferential_insert_iterator.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.iterator.preferential_insert_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.preferential_insert_iterator\test.unit.stlsoft.iterator.preferential_insert_iterator.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.preferential_insert_iterator\test.unit.stlsoft.iterator.preferential_insert_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.sorted_eraser_iterator.vc10.exe:	.\test.unit.stlsoft.iterator.sorted_eraser_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.iterator.sorted_eraser_iterator.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.iterator.sorted_eraser_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.sorted_eraser_iterator\test.unit.stlsoft.iterator.sorted_eraser_iterator.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.sorted_eraser_iterator\test.unit.stlsoft.iterator.sorted_eraser_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.string_concatenator_iterator.vc10.exe:	.\test.unit.stlsoft.iterator.string_concatenator_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.iterator.string_concatenator_iterator.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.iterator.string_concatenator_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.string_concatenator_iterator\test.unit.stlsoft.iterator.string_concatenator_iterator.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.string_concatenator_iterator\test.unit.stlsoft.iterator.string_concatenator_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.transform_iterator.vc10.exe:	.\test.unit.stlsoft.iterator.transform_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.iterator.transform_iterator.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.iterator.transform_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.transform_iterator\test.unit.stlsoft.iterator.transform_iterator.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.transform_iterator\test.unit.stlsoft.iterator.transform_iterator.cpp

..\..\bin\test.unit.stlsoft.iterator.unsorted_eraser_iterator.vc10.exe:	.\test.unit.stlsoft.iterator.unsorted_eraser_iterator.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.iterator.unsorted_eraser_iterator.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.iterator.unsorted_eraser_iterator.obj:	..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.unsorted_eraser_iterator\test.unit.stlsoft.iterator.unsorted_eraser_iterator.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\iterator\test.unit.stlsoft.iterator.unsorted_eraser_iterator\test.unit.stlsoft.iterator.unsorted_eraser_iterator.cpp

..\..\bin\test.unit.stlsoft.memory.auto_buffer.vc10.exe:	.\test.unit.stlsoft.memory.auto_buffer.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.memory.auto_buffer.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.memory.auto_buffer.obj:	..\..\test\unit\stlsoft\memory\test.unit.stlsoft.memory.auto_buffer\test.unit.stlsoft.memory.auto_buffer.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\memory\test.unit.stlsoft.memory.auto_buffer\test.unit.stlsoft.memory.auto_buffer.cpp

..\..\bin\test.unit.stlsoft.meta.is_printf_type.vc10.exe:	.\test.unit.stlsoft.meta.is_printf_type.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.meta.is_printf_type.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.meta.is_printf_type.obj:	..\..\test\unit\stlsoft\meta\test.unit.stlsoft.meta.is_printf_type\test.unit.stlsoft.meta.is_printf_type.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\meta\test.unit.stlsoft.meta.is_printf_type\test.unit.stlsoft.meta.is_printf_type.cpp

..\..\bin\test.unit.stlsoft.shims.access.string.std.time.vc10.exe:	.\test.unit.stlsoft.shims.access.string.std.time.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.shims.access.string.std.time.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.shims.access.string.std.time.obj:	..\..\test\unit\stlsoft\shims\access\string\test.unit.stlsoft.shims.access.string.std.time\test.unit.stlsoft.shims.access.string.std.time.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\shims\access\string\test.unit.stlsoft.shims.access.string.std.time\test.unit.stlsoft.shims.access.string.std.time.cpp

..\..\bin\test.unit.stlsoft.smartptr.scoped_handle.vc10.exe:	.\test.unit.stlsoft.smartptr.scoped_handle.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.smartptr.scoped_handle.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.smartptr.scoped_handle.obj:	..\..\test\unit\stlsoft\smartptr\scoped_handle\test.unit.stlsoft.smartptr.scoped_handle\test.unit.stlsoft.smartptr.scoped_handle.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\smartptr\scoped_handle\test.unit.stlsoft.smartptr.scoped_handle\test.unit.stlsoft.smartptr.scoped_handle.cpp

..\..\bin\test.unit.stlsoft.smartptr.scoped_method.vc10.exe:	.\test.unit.stlsoft.smartptr.scoped_method.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.smartptr.scoped_method.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.smartptr.scoped_method.obj:	..\..\test\unit\stlsoft\smartptr\scoped_method\test.unit.stlsoft.smartptr.scoped_method\test.unit.stlsoft.smartptr.scoped_method.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\smartptr\scoped_method\test.unit.stlsoft.smartptr.scoped_method\test.unit.stlsoft.smartptr.scoped_method.cpp

..\..\bin\test.unit.stlsoft.smartptr.scoped_ptr.vc10.exe:	.\test.unit.stlsoft.smartptr.scoped_ptr.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.smartptr.scoped_ptr.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.smartptr.scoped_ptr.obj:	..\..\test\unit\stlsoft\smartptr\scoped_ptr\test.unit.stlsoft.smartptr.scoped_ptr\test.unit.stlsoft.smartptr.scoped_ptr.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\smartptr\scoped_ptr\test.unit.stlsoft.smartptr.scoped_ptr\test.unit.stlsoft.smartptr.scoped_ptr.cpp

..\..\bin\test.unit.stlsoft.smartptr.shared_ptr.vc10.exe:	.\test.unit.stlsoft.smartptr.shared_ptr.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.smartptr.shared_ptr.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.smartptr.shared_ptr.obj:	..\..\test\unit\stlsoft\smartptr\shared_ptr\test.unit.stlsoft.smartptr.shared_ptr\test.unit.stlsoft.smartptr.shared_ptr.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\smartptr\shared_ptr\test.unit.stlsoft.smartptr.shared_ptr\test.unit.stlsoft.smartptr.shared_ptr.cpp

..\..\bin\test.unit.stlsoft.string.replace_functions.vc10.exe:	.\test.unit.stlsoft.string.replace_functions.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.string.replace_functions.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.replace_functions.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.replace_functions\test.unit.stlsoft.string.replace_functions.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.replace_functions\test.unit.stlsoft.string.replace_functions.cpp

..\..\bin\test.unit.stlsoft.string.shim_string.vc10.exe:	.\test.unit.stlsoft.string.shim_string.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.string.shim_string.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.shim_string.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.shim_string\test.unit.stlsoft.string.shim_string.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.shim_string\test.unit.stlsoft.string.shim_string.cpp

..\..\bin\test.unit.stlsoft.string.simple_string.vc10.exe:	.\test.unit.stlsoft.string.simple_string.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.string.simple_string.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.simple_string.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.simple_string\test.unit.stlsoft.string.simple_string.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.simple_string\test.unit.stlsoft.string.simple_string.cpp

..\..\bin\test.unit.stlsoft.string.slice_functions.vc10.exe:	.\test.unit.stlsoft.string.slice_functions.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.string.slice_functions.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.slice_functions.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.slice_functions\test.unit.stlsoft.string.slice_functions.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.slice_functions\test.unit.stlsoft.string.slice_functions.cpp

..\..\bin\test.unit.stlsoft.string.split_functions.vc10.exe:	.\test.unit.stlsoft.string.split_functions.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.string.split_functions.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.split_functions.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.split_functions\test.unit.stlsoft.string.split_functions.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.split_functions\test.unit.stlsoft.string.split_functions.cpp

..\..\bin\test.unit.stlsoft.string.static_string.vc10.exe:	.\test.unit.stlsoft.string.static_string.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.string.static_string.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.static_string.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.static_string\test.unit.stlsoft.string.static_string.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.static_string\test.unit.stlsoft.string.static_string.cpp

..\..\bin\test.unit.stlsoft.string.string_registry.vc10.exe:	.\test.unit.stlsoft.string.string_registry.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.string.string_registry.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.string_registry.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_registry\test.unit.stlsoft.string.string_registry.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_registry\test.unit.stlsoft.string.string_registry.cpp

..\..\bin\test.unit.stlsoft.string.string_slice.vc10.exe:	.\test.unit.stlsoft.string.string_slice.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.string.string_slice.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.string_slice.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_slice\test.unit.stlsoft.string.string_slice.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_slice\test.unit.stlsoft.string.string_slice.cpp

..\..\bin\test.unit.stlsoft.string.string_tokeniser.vc10.exe:	.\test.unit.stlsoft.string.string_tokeniser.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.string.string_tokeniser.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.string_tokeniser.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_tokeniser\test.unit.stlsoft.string.string_tokeniser.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_tokeniser\test.unit.stlsoft.string.string_tokeniser.cpp

..\..\bin\test.unit.stlsoft.string.string_view.vc10.exe:	.\test.unit.stlsoft.string.string_view.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.string.string_view.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.string_view.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_view\test.unit.stlsoft.string.string_view.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.string_view\test.unit.stlsoft.string.string_view.cpp

..\..\bin\test.unit.stlsoft.string.tokeniser_functions.vc10.exe:	.\test.unit.stlsoft.string.tokeniser_functions.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.string.tokeniser_functions.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.string.tokeniser_functions.obj:	..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.tokeniser_functions\test.unit.stlsoft.string.tokeniser_functions.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\string\test.unit.stlsoft.string.tokeniser_functions\test.unit.stlsoft.string.tokeniser_functions.cpp

..\..\bin\test.unit.stlsoft.tr1.smartptr.scoped_ptr.vc10.exe:	.\test.unit.stlsoft.tr1.smartptr.scoped_ptr.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.tr1.smartptr.scoped_ptr.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.tr1.smartptr.scoped_ptr.obj:	..\..\test\unit\stlsoft\tr1\smartptr\scoped_ptr\test.unit.stlsoft.tr1.smartptr.scoped_ptr\test.unit.stlsoft.tr1.smartptr.scoped_ptr.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\tr1\smartptr\scoped_ptr\test.unit.stlsoft.tr1.smartptr.scoped_ptr\test.unit.stlsoft.tr1.smartptr.scoped_ptr.cpp

..\..\bin\test.unit.stlsoft.util.bit_functions.vc10.exe:	.\test.unit.stlsoft.util.bit_functions.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.util.bit_functions.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.util.bit_functions.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.bit_functions\test.unit.stlsoft.util.bit_functions.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.bit_functions\test.unit.stlsoft.util.bit_functions.cpp

..\..\bin\test.unit.stlsoft.util.exception_string_creator.vc10.exe:	.\test.unit.stlsoft.util.exception_string_creator.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.util.exception_string_creator.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.util.exception_string_creator.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.exception_string_creator\test.unit.stlsoft.util.exception_string_creator.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.exception_string_creator\test.unit.stlsoft.util.exception_string_creator.cpp

..\..\bin\test.unit.stlsoft.util.has_bom.vc10.exe:	.\test.unit.stlsoft.util.has_bom.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.util.has_bom.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.util.has_bom.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.has_bom\test.unit.stlsoft.util.has_bom.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.has_bom\test.unit.stlsoft.util.has_bom.cpp

..\..\bin\test.unit.stlsoft.util.minmax.vc10.exe:	.\test.unit.stlsoft.util.minmax.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.util.minmax.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.util.minmax.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.minmax\test.unit.stlsoft.util.minmax.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.minmax\test.unit.stlsoft.util.minmax.cpp

..\..\bin\test.unit.stlsoft.util.must_init.vc10.exe:	.\test.unit.stlsoft.util.must_init.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.util.must_init.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.util.must_init.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.must_init\test.unit.stlsoft.util.must_init.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.must_init\test.unit.stlsoft.util.must_init.cpp

..\..\bin\test.unit.stlsoft.util.rand.vc10.exe:	.\test.unit.stlsoft.util.rand.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.util.rand.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.util.rand.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.rand\test.unit.stlsoft.util.rand.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.rand\test.unit.stlsoft.util.rand.cpp

..\..\bin\test.unit.stlsoft.util.string_switch.vc10.exe:	.\test.unit.stlsoft.util.string_switch.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.stlsoft.util.string_switch.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib 
.\test.unit.stlsoft.util.string_switch.obj:	..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.string_switch\test.unit.stlsoft.util.string_switch.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\stlsoft\util\test.unit.stlsoft.util.string_switch\test.unit.stlsoft.util.string_switch.cpp


############################################################################
# Internal Targets

########################################
# winstl:

..\..\bin\test.component.winstl.filesystem.findfile_sequence.vc10.exe:	.\test.component.winstl.filesystem.findfile_sequence.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.winstl.filesystem.findfile_sequence.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.component.winstl.filesystem.findfile_sequence.obj:	..\..\test\component\winstl\filesystem\test.component.winstl.filesystem.findfile_sequence\test.component.winstl.filesystem.findfile_sequence.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\winstl\filesystem\test.component.winstl.filesystem.findfile_sequence\test.component.winstl.filesystem.findfile_sequence.cpp

..\..\bin\test.component.winstl.filesystem.hrw_file_lines.vc10.exe:	.\test.component.winstl.filesystem.hrw_file_lines.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.winstl.filesystem.hrw_file_lines.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.component.winstl.filesystem.hrw_file_lines.obj:	..\..\test\component\winstl\filesystem\test.component.winstl.filesystem.hrw_file_lines\test.component.winstl.filesystem.hrw_file_lines.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\winstl\filesystem\test.component.winstl.filesystem.hrw_file_lines\test.component.winstl.filesystem.hrw_file_lines.cpp

..\..\bin\test.component.winstl.filesystem.memory_map_functions.C.vc10.exe:	.\test.component.winstl.filesystem.memory_map_functions.C.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.winstl.filesystem.memory_map_functions.C.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.component.winstl.filesystem.memory_map_functions.C.obj:	..\..\test\component\winstl\filesystem\test.component.winstl.filesystem.memory_map_functions.C\test.component.winstl.filesystem.memory_map_functions.C.c
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\winstl\filesystem\test.component.winstl.filesystem.memory_map_functions.C\test.component.winstl.filesystem.memory_map_functions.C.c

..\..\bin\test.component.winstl.filesystem.memory_map_functions.vc10.exe:	.\test.component.winstl.filesystem.memory_map_functions.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.winstl.filesystem.memory_map_functions.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.component.winstl.filesystem.memory_map_functions.obj:	..\..\test\component\winstl\filesystem\test.component.winstl.filesystem.memory_map_functions\test.component.winstl.filesystem.memory_map_functions.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\winstl\filesystem\test.component.winstl.filesystem.memory_map_functions\test.component.winstl.filesystem.memory_map_functions.cpp

..\..\bin\test.component.winstl.filesystem.memory_mapped_file_view_handle.vc10.exe:	.\test.component.winstl.filesystem.memory_mapped_file_view_handle.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.winstl.filesystem.memory_mapped_file_view_handle.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.component.winstl.filesystem.memory_mapped_file_view_handle.obj:	..\..\test\component\winstl\filesystem\test.component.winstl.filesystem.memory_mapped_file_view_handle\test.component.winstl.filesystem.memory_mapped_file_view_handle.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\winstl\filesystem\test.component.winstl.filesystem.memory_mapped_file_view_handle\test.component.winstl.filesystem.memory_mapped_file_view_handle.cpp

..\..\bin\test.component.winstl.filesystem.readonly_memory_mapped_file.vc10.exe:	.\test.component.winstl.filesystem.readonly_memory_mapped_file.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.winstl.filesystem.readonly_memory_mapped_file.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.component.winstl.filesystem.readonly_memory_mapped_file.obj:	..\..\test\component\winstl\filesystem\test.component.winstl.filesystem.readonly_memory_mapped_file\test.component.winstl.filesystem.readonly_memory_mapped_file.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\winstl\filesystem\test.component.winstl.filesystem.readonly_memory_mapped_file\test.component.winstl.filesystem.readonly_memory_mapped_file.cpp

..\..\bin\test.component.winstl.synch.semaphore.vc10.exe:	.\test.component.winstl.synch.semaphore.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.winstl.synch.semaphore.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.component.winstl.synch.semaphore.obj:	..\..\test\component\winstl\synch\test.component.winstl.synch.semaphore\test.component.winstl.synch.semaphore.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\winstl\synch\test.component.winstl.synch.semaphore\test.component.winstl.synch.semaphore.cpp

..\..\bin\test.component.winstl.system.console_functions.vc10.exe:	.\test.component.winstl.system.console_functions.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.winstl.system.console_functions.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.component.winstl.system.console_functions.obj:	..\..\test\component\winstl\system\test.component.winstl.system.console_functions\test.component.winstl.system.console_functions.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\winstl\system\test.component.winstl.system.console_functions\test.component.winstl.system.console_functions.cpp

..\..\bin\test.component.winstl.system.environment_variable.vc10.exe:	.\test.component.winstl.system.environment_variable.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.winstl.system.environment_variable.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.component.winstl.system.environment_variable.obj:	..\..\test\component\winstl\system\test.component.winstl.system.environment_variable\test.component.winstl.system.environment_variable.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\winstl\system\test.component.winstl.system.environment_variable\test.component.winstl.system.environment_variable.cpp

..\..\bin\test.component.winstl.system.system_directory.vc10.exe:	.\test.component.winstl.system.system_directory.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.winstl.system.system_directory.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.component.winstl.system.system_directory.obj:	..\..\test\component\winstl\system\test.component.winstl.system.system_directory\test.component.winstl.system.system_directory.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\winstl\system\test.component.winstl.system.system_directory\test.component.winstl.system.system_directory.cpp

..\..\bin\test.component.winstl.system.temporary_directory.vc10.exe:	.\test.component.winstl.system.temporary_directory.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.winstl.system.temporary_directory.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.component.winstl.system.temporary_directory.obj:	..\..\test\component\winstl\system\test.component.winstl.system.temporary_directory\test.component.winstl.system.temporary_directory.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\winstl\system\test.component.winstl.system.temporary_directory\test.component.winstl.system.temporary_directory.cpp

..\..\bin\test.component.winstl.system.windows_directory.vc10.exe:	.\test.component.winstl.system.windows_directory.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.component.winstl.system.windows_directory.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.component.winstl.system.windows_directory.obj:	..\..\test\component\winstl\system\test.component.winstl.system.windows_directory\test.component.winstl.system.windows_directory.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\component\winstl\system\test.component.winstl.system.windows_directory\test.component.winstl.system.windows_directory.cpp

..\..\bin\mmap.vc10.exe:	.\mmap.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\mmap.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\mmap.obj:	..\..\test\scratch\winstl\filesystem\mmap\mmap.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\scratch\winstl\filesystem\mmap\mmap.cpp

..\..\bin\test.scratch.winstl.performance.threadtimes_counter.vc10.exe:	.\test.scratch.winstl.performance.threadtimes_counter.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.scratch.winstl.performance.threadtimes_counter.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.scratch.winstl.performance.threadtimes_counter.obj:	..\..\test\scratch\winstl\performance\test.scratch.winstl.performance.threadtimes_counter\test.scratch.winstl.performance.threadtimes_counter.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\scratch\winstl\performance\test.scratch.winstl.performance.threadtimes_counter\test.scratch.winstl.performance.threadtimes_counter.cpp

..\..\bin\test.unit.winstl.filesystem.filesystem_traits.1.vc10.exe:	.\test.unit.winstl.filesystem.filesystem_traits.1.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.winstl.filesystem.filesystem_traits.1.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.unit.winstl.filesystem.filesystem_traits.1.obj:	..\..\test\unit\winstl\filesystem\test.unit.winstl.filesystem.filesystem_traits.1\test.unit.winstl.filesystem.filesystem_traits.1.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\winstl\filesystem\test.unit.winstl.filesystem.filesystem_traits.1\test.unit.winstl.filesystem.filesystem_traits.1.cpp

..\..\bin\test.unit.winstl.filesystem.filesystem_traits.2.vc10.exe:	.\test.unit.winstl.filesystem.filesystem_traits.2.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.winstl.filesystem.filesystem_traits.2.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.unit.winstl.filesystem.filesystem_traits.2.obj:	..\..\test\unit\winstl\filesystem\test.unit.winstl.filesystem.filesystem_traits.2\test.unit.winstl.filesystem.filesystem_traits.2.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\winstl\filesystem\test.unit.winstl.filesystem.filesystem_traits.2\test.unit.winstl.filesystem.filesystem_traits.2.cpp

..\..\bin\test.unit.winstl.filesystem.findvolume_sequence.vc10.exe:	.\test.unit.winstl.filesystem.findvolume_sequence.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.winstl.filesystem.findvolume_sequence.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.unit.winstl.filesystem.findvolume_sequence.obj:	..\..\test\unit\winstl\filesystem\test.unit.winstl.filesystem.findvolume_sequence\test.unit.winstl.filesystem.findvolume_sequence.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\winstl\filesystem\test.unit.winstl.filesystem.findvolume_sequence\test.unit.winstl.filesystem.findvolume_sequence.cpp

..\..\bin\test.unit.winstl.filesystem.memory_mapped_file.vc10.exe:	.\test.unit.winstl.filesystem.memory_mapped_file.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.winstl.filesystem.memory_mapped_file.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.unit.winstl.filesystem.memory_mapped_file.obj:	..\..\test\unit\winstl\filesystem\test.unit.winstl.filesystem.memory_mapped_file\test.unit.winstl.filesystem.memory_mapped_file.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\winstl\filesystem\test.unit.winstl.filesystem.memory_mapped_file\test.unit.winstl.filesystem.memory_mapped_file.cpp

..\..\bin\test.unit.winstl.filesystem.path.vc10.exe:	.\test.unit.winstl.filesystem.path.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.winstl.filesystem.path.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.unit.winstl.filesystem.path.obj:	..\..\test\unit\winstl\filesystem\test.unit.winstl.filesystem.path\test.unit.winstl.filesystem.path.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\winstl\filesystem\test.unit.winstl.filesystem.path\test.unit.winstl.filesystem.path.cpp

..\..\bin\test.unit.winstl.filesystem.path_functions.vc10.exe:	.\test.unit.winstl.filesystem.path_functions.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.winstl.filesystem.path_functions.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.unit.winstl.filesystem.path_functions.obj:	..\..\test\unit\winstl\filesystem\test.unit.winstl.filesystem.path_functions\test.unit.winstl.filesystem.path_functions.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\winstl\filesystem\test.unit.winstl.filesystem.path_functions\test.unit.winstl.filesystem.path_functions.cpp

..\..\bin\test.unit.winstl.registry.reg_delete_tree.vc10.exe:	.\test.unit.winstl.registry.reg_delete_tree.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.winstl.registry.reg_delete_tree.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.unit.winstl.registry.reg_delete_tree.obj:	..\..\test\unit\winstl\registry\test.unit.winstl.registry.reg_delete_tree\test.unit.winstl.registry.reg_delete_tree.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\winstl\registry\test.unit.winstl.registry.reg_delete_tree\test.unit.winstl.registry.reg_delete_tree.cpp

..\..\bin\test.unit.winstl.registry.reg_value.vc10.exe:	.\test.unit.winstl.registry.reg_value.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.winstl.registry.reg_value.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.unit.winstl.registry.reg_value.obj:	..\..\test\unit\winstl\registry\test.unit.winstl.registry.reg_value\test.unit.winstl.registry.reg_value.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\winstl\registry\test.unit.winstl.registry.reg_value\test.unit.winstl.registry.reg_value.cpp

..\..\bin\test.unit.winstl.synch.w4mo.vc10.exe:	.\test.unit.winstl.synch.w4mo.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.winstl.synch.w4mo.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.unit.winstl.synch.w4mo.obj:	..\..\test\unit\winstl\synch\test.unit.winstl.synch.w4mo\test.unit.winstl.synch.w4mo.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\winstl\synch\test.unit.winstl.synch.w4mo\test.unit.winstl.synch.w4mo.cpp

..\..\bin\test.unit.winstl.system.commandline_parser.vc10.exe:	.\test.unit.winstl.system.commandline_parser.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.winstl.system.commandline_parser.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.unit.winstl.system.commandline_parser.obj:	..\..\test\unit\winstl\system\test.unit.winstl.system.commandline_parser\test.unit.winstl.system.commandline_parser.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\winstl\system\test.unit.winstl.system.commandline_parser\test.unit.winstl.system.commandline_parser.cpp

..\..\bin\test.unit.winstl.system.searchpath_sequence.vc10.exe:	.\test.unit.winstl.system.searchpath_sequence.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.winstl.system.searchpath_sequence.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.unit.winstl.system.searchpath_sequence.obj:	..\..\test\unit\winstl\system\test.unit.winstl.system.searchpath_sequence\test.unit.winstl.system.searchpath_sequence.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\winstl\system\test.unit.winstl.system.searchpath_sequence\test.unit.winstl.system.searchpath_sequence.cpp

..\..\bin\test.unit.winstl.system.system_traits.1.vc10.exe:	.\test.unit.winstl.system.system_traits.1.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.winstl.system.system_traits.1.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.unit.winstl.system.system_traits.1.obj:	..\..\test\unit\winstl\system\test.unit.winstl.system.system_traits.1\test.unit.winstl.system.system_traits.1.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\winstl\system\test.unit.winstl.system.system_traits.1\test.unit.winstl.system.system_traits.1.cpp

..\..\bin\test.unit.winstl.system.system_traits.2.vc10.exe:	.\test.unit.winstl.system.system_traits.2.obj
	link -nologo -libpath:$(LIB_XTESTS)    -out:$@ -subsystem:console .\test.unit.winstl.system.system_traits.2.obj   xtests.0.core.vc10.mt.lib   advapi32.lib kernel32.lib user32.lib  ole32.lib oleaut32.lib shlwapi.lib uuid.lib
.\test.unit.winstl.system.system_traits.2.obj:	..\..\test\unit\winstl\system\test.unit.winstl.system.system_traits.2\test.unit.winstl.system.system_traits.2.cpp
	cl -c -nologo -MT -DWIN32   -O2 -Ox -EHsc -GR -W4 -wd4702 -WX  $(STLSOFT_INCLUDES)  -I$(INCL_XTESTS)  -Fo$@ ..\..\test\unit\winstl\system\test.unit.winstl.system.system_traits.2\test.unit.winstl.system.system_traits.2.cpp

############################################################################
