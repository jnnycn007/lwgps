cmake_minimum_required(VERSION 3.22)

if(DEFINED IDF_PATH)
    idf_component_register(
        SRCS "lwgps/src/lwgps/lwgps.c"
        INCLUDE_DIRS "lwgps/src/include"
    )
    return()
endif()

# Standalone / subdirectory build
project(LwLibPROJECT)

if(NOT PROJECT_IS_TOP_LEVEL)
    add_subdirectory(lwgps)
else()
    set(TEST_CMAKE_FILE_NAME "test_parse_sat_det/cmake.cmake")
    add_subdirectory(tests)
endif()
