cmake_minimum_required(VERSION 3.22)

# Setup project
project(LwLibPROJECT)

if(NOT PROJECT_IS_TOP_LEVEL)
    add_subdirectory(lwgps)
else()
    enable_testing()
    add_executable(${PROJECT_NAME})
    target_sources(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/dev/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/test_code.c
        ${CMAKE_CURRENT_LIST_DIR}/test/test_time.c
    )
    target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/dev
    )

    # Add subdir with lwgps and link to project
    set(LWGPS_OPTS_FILE ${CMAKE_CURRENT_LIST_DIR}/dev/lwgps_opts.h)
    add_subdirectory(lwgps)
    target_link_libraries(${PROJECT_NAME} PUBLIC lwgps)

    # Add compile options to the library, which will propagate options to executable through public link
    target_compile_definitions(lwgps PUBLIC WIN32 _DEBUG CONSOLE LWGPS_DEV)
    target_compile_options(lwgps PUBLIC -Wall -Wextra -Wpedantic)

    # Add test
    add_test(NAME Test COMMAND $<TARGET_FILE:${CMAKE_PROJECT_NAME}>)
endif()
