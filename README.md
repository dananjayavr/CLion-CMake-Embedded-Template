### Basic multi-arch (ARMv7M / x86) project template 

- Project is tested with a NUCLEO-F401RE board

- Create a project as usual (C executable)

- Select the Run | New Embedded Configuration action in the main menu.
  - Choose J-Link (or any other debugger I guess)
    - For J-Link: choose the J-Link path (ex. C:\Program Files\SEGGER\JLink_V796f)
    - For ST-Link: choose where STM32CubeIDE is installed
  - Choose target and leave everything to its default settings
  - Update the Configuration name if necessary (instead of unnamed)

- Copy gcc-arm-none-eabi.cmake file from a CMake reference project from CubeMX

- In Settings -> Build,Execution,Deployment -> CMake :
  - add the toolchain file from the previous step: -DCMAKE_TOOLCHAIN_FILE=gcc-arm-none-eabi.cmake 
  - Also add -DTARGET:BOOL=ON. This is so I can selectively add sources from my CMakeLists.txt
  - I also renamed the 'Profile' to a more intuitive name (ex. TARGET) instead of Debug

- At this point, I was able to compile the project (main.c untouched from the default generated one),
  once I included all the dependencies (linker file, startup.s, etc.)

- Now you should be able to debug the main.c file
  - J-Link: it works out of the box
  - ST-Link (non-OpenOCD one) should also work out of the box. Make sure that STM32CubeProgrammer is able to successfully
    connect to the device. I had an issue which was solved by going to Device Manager and choosing the up-to-date Driver
    https://stackoverflow.com/questions/44703157/no-st-link-detected-error-message-when-trying-to-connect-with-st-link-utility
    You might also want to add a breakpoint at main.
  
- To add x86 support, I created a new 'Profile' called SIMULATOR

- Naturally, not toolchain file has to be provided. Instead, add -DSIMULATOR:BOOL=ON. This is so I can selectively
  add source files from my CMakeLists.txt

- To be able to run this, go to Run/Debug Configurations and add a default CMake Application (above the Embedded GDB Server)
  - It might create two targets (both unnamed I think), delete one and leave the options default

- You should be able to compile and run (Make sure to choose the 'SIMULATOR' profile)

### Sources 

- https://www.jetbrains.com/clion/features/embedded-dev.html
- https://www.jetbrains.com/help/clion/embedded-gdb-server.html
- https://www.jetbrains.com/help/clion/how-to-create-toolchain-in-clion.html#cmake-toolchain
- CMake template from JetBrains : https://gist.github.com/elmot/3b4f0e9f8b23864fdf8bb509c329d051 (although I a use custom one)
- Oldish article: https://blog.jetbrains.com/clion/2016/06/clion-for-embedded-development/ (OpenOCD and CubeMX)