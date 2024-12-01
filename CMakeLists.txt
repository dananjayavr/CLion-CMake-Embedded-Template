cmake_minimum_required(VERSION 3.29)
project(embedded_gdb_clion C)

# Enable CMake support for ASM and C languages
enable_language(C ASM)
set(CMAKE_C_STANDARD 23)

if(TARGET)
    add_executable(embedded_gdb_clion
            main.c
            app/arm.c
            STM32/syscalls.c
            STM32/sysmem.c
            STM32/system_stm32f4xx.c
            STM32/startup_stm32f401xe.s
    )
endif ()

if(SIMULATOR)
    add_executable(embedded_gdb_clion
            main.c
            app/x86.c
    )
endif ()

if(DOCKER)
    target_compile_definitions(embedded_gdb_clion PUBLIC DOCKER)
endif ()

target_include_directories(embedded_gdb_clion PRIVATE STM32/CMSIS)

target_compile_definitions(embedded_gdb_clion PUBLIC
        STM32F401xE
        $<$<CONFIG:Debug>:DEBUG>
)