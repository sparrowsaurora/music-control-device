cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(my_project C CXX ASM)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_library(volume
    components/volume/volume.c
)

# Make the header visible to users of the library
target_include_directories(volume PUBLIC
    components/volume
)

add_executable(main
    main.c
)

target_link_libraries(volume
    pico_stdlib
    hardware_adc
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(main 
    pico_stdlib 
    hardware_adc 
    volume
)

# enable usb output, disable uart output
pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(main)
