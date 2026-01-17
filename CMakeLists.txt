cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(my_project C CXX ASM)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# volume component

add_library(volume
    components/volume/volume.c
)

# Make the header visible to users of the library
target_include_directories(volume PUBLIC
    components/volume
)

target_link_libraries(volume
    pico_stdlib
    hardware_adc
)

# display component 

add_library(display
    components/display/display.c
)

target_include_directories(display PUBLIC
    components/display
)

target_link_libraries(display
    pico_stdlib
    hardware_gpio
)

# main

add_executable(main
    main.c
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(main 
    pico_stdlib 
    hardware_adc 
    volume
    display
)

# enable usb output, disable uart output
pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(main)
