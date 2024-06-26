#
set(library_sources
    ${CMAKE_CURRENT_LIST_DIR}/coverage.cpp
    ${CMAKE_CURRENT_LIST_DIR}/cpu_freq.cpp
    ${CMAKE_CURRENT_LIST_DIR}/kokkosp.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ompt.cpp
    ${CMAKE_CURRENT_LIST_DIR}/perf.cpp
    ${CMAKE_CURRENT_LIST_DIR}/process_sampler.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ptl.cpp
    ${CMAKE_CURRENT_LIST_DIR}/runtime.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sampling.cpp
    ${CMAKE_CURRENT_LIST_DIR}/thread_deleter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/thread_info.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tracing.cpp)

set(library_headers
    ${CMAKE_CURRENT_LIST_DIR}/coverage.hpp
    ${CMAKE_CURRENT_LIST_DIR}/cpu_freq.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ompt.hpp
    ${CMAKE_CURRENT_LIST_DIR}/process_sampler.hpp
    ${CMAKE_CURRENT_LIST_DIR}/perf.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ptl.hpp
    ${CMAKE_CURRENT_LIST_DIR}/rcclp.hpp
    ${CMAKE_CURRENT_LIST_DIR}/rocm.hpp
    ${CMAKE_CURRENT_LIST_DIR}/rocm_smi.hpp
    ${CMAKE_CURRENT_LIST_DIR}/rocprofiler.hpp
    ${CMAKE_CURRENT_LIST_DIR}/roctracer.hpp
    ${CMAKE_CURRENT_LIST_DIR}/runtime.hpp
    ${CMAKE_CURRENT_LIST_DIR}/sampling.hpp
    ${CMAKE_CURRENT_LIST_DIR}/thread_data.hpp
    ${CMAKE_CURRENT_LIST_DIR}/thread_deleter.hpp
    ${CMAKE_CURRENT_LIST_DIR}/thread_info.hpp
    ${CMAKE_CURRENT_LIST_DIR}/tracing.hpp)

target_sources(omnitrace-object-library PRIVATE ${library_sources} ${library_headers})

if(OMNITRACE_USE_ROCTRACER OR OMNITRACE_USE_ROCPROFILER)
    target_sources(omnitrace-object-library PRIVATE ${CMAKE_CURRENT_LIST_DIR}/rocm.cpp)
endif()

if(OMNITRACE_USE_ROCTRACER)
    target_sources(omnitrace-object-library
                   PRIVATE ${CMAKE_CURRENT_LIST_DIR}/roctracer.cpp)
endif()

if(OMNITRACE_USE_RCCL)
    target_sources(omnitrace-object-library PRIVATE ${CMAKE_CURRENT_LIST_DIR}/rcclp.cpp)
endif()

if(OMNITRACE_USE_ROCPROFILER)
    target_sources(
        omnitrace-object-library PRIVATE ${CMAKE_CURRENT_LIST_DIR}/rocprofiler.cpp
                                         ${CMAKE_CURRENT_LIST_DIR}/rocprofiler.hpp)
endif()

if(OMNITRACE_USE_ROCM_SMI)
    target_sources(omnitrace-object-library
                   PRIVATE ${CMAKE_CURRENT_LIST_DIR}/rocm_smi.cpp)
endif()

add_subdirectory(causal)
add_subdirectory(components)
add_subdirectory(coverage)
add_subdirectory(rocm)
add_subdirectory(tracing)

set(ndebug_sources
    ${CMAKE_CURRENT_LIST_DIR}/components/mpi_gotcha.cpp
    ${CMAKE_CURRENT_LIST_DIR}/components/backtrace_metrics.cpp
    ${CMAKE_CURRENT_LIST_DIR}/rcclp.cpp
    ${CMAKE_CURRENT_LIST_DIR}/kokkosp.cpp
    ${CMAKE_CURRENT_LIST_DIR}/rocm_smi.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ompt.cpp)

set_source_files_properties(
    ${ndebug_sources} DIRECTORY ${PROJECT_SOURCE_DIR}/source/lib/omnitrace
    PROPERTIES COMPILE_DEFINITIONS NDEBUG COMPILE_OPTIONS "-g0;-O3")
