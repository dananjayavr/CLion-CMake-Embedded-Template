cmake_minimum_required(VERSION 3.30)
project(embedded_gdb_clion C)

# Enable CMake support for ASM and C languages
enable_language(C ASM)
set(CMAKE_C_STANDARD 23)

if(TARGET)
    add_executable(embedded_gdb_clion
            main.c
            syscalls.c
            sysmem.c
            system_stm32f4xx.c
            startup_stm32f401xe.s
    )
endif ()

if(SIMULATOR)
    add_executable(embedded_gdb_clion
            main.c
    )
endif ()

target_include_directories(embedded_gdb_clion PRIVATE CMSIS)

target_compile_definitions(embedded_gdb_clion PUBLIC
        STM32F401xE
        $<$<CONFIG:Debug>:DEBUG>
)