# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 4.0

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\cmake-4.0.2-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = C:\cmake-4.0.2-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Code\LogSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Code\LogSystem\build

# Include any dependencies generated for this target.
include CMakeFiles/my_LogSystem.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/my_LogSystem.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/my_LogSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_LogSystem.dir/flags.make

CMakeFiles/my_LogSystem.dir/codegen:
.PHONY : CMakeFiles/my_LogSystem.dir/codegen

CMakeFiles/my_LogSystem.dir/src/LogQueue.cpp.obj: CMakeFiles/my_LogSystem.dir/flags.make
CMakeFiles/my_LogSystem.dir/src/LogQueue.cpp.obj: CMakeFiles/my_LogSystem.dir/includes_CXX.rsp
CMakeFiles/my_LogSystem.dir/src/LogQueue.cpp.obj: C:/Code/LogSystem/src/LogQueue.cpp
CMakeFiles/my_LogSystem.dir/src/LogQueue.cpp.obj: CMakeFiles/my_LogSystem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Code\LogSystem\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_LogSystem.dir/src/LogQueue.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my_LogSystem.dir/src/LogQueue.cpp.obj -MF CMakeFiles\my_LogSystem.dir\src\LogQueue.cpp.obj.d -o CMakeFiles\my_LogSystem.dir\src\LogQueue.cpp.obj -c C:\Code\LogSystem\src\LogQueue.cpp

CMakeFiles/my_LogSystem.dir/src/LogQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/my_LogSystem.dir/src/LogQueue.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Code\LogSystem\src\LogQueue.cpp > CMakeFiles\my_LogSystem.dir\src\LogQueue.cpp.i

CMakeFiles/my_LogSystem.dir/src/LogQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/my_LogSystem.dir/src/LogQueue.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Code\LogSystem\src\LogQueue.cpp -o CMakeFiles\my_LogSystem.dir\src\LogQueue.cpp.s

CMakeFiles/my_LogSystem.dir/src/Logger.cpp.obj: CMakeFiles/my_LogSystem.dir/flags.make
CMakeFiles/my_LogSystem.dir/src/Logger.cpp.obj: CMakeFiles/my_LogSystem.dir/includes_CXX.rsp
CMakeFiles/my_LogSystem.dir/src/Logger.cpp.obj: C:/Code/LogSystem/src/Logger.cpp
CMakeFiles/my_LogSystem.dir/src/Logger.cpp.obj: CMakeFiles/my_LogSystem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Code\LogSystem\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/my_LogSystem.dir/src/Logger.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my_LogSystem.dir/src/Logger.cpp.obj -MF CMakeFiles\my_LogSystem.dir\src\Logger.cpp.obj.d -o CMakeFiles\my_LogSystem.dir\src\Logger.cpp.obj -c C:\Code\LogSystem\src\Logger.cpp

CMakeFiles/my_LogSystem.dir/src/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/my_LogSystem.dir/src/Logger.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Code\LogSystem\src\Logger.cpp > CMakeFiles\my_LogSystem.dir\src\Logger.cpp.i

CMakeFiles/my_LogSystem.dir/src/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/my_LogSystem.dir/src/Logger.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Code\LogSystem\src\Logger.cpp -o CMakeFiles\my_LogSystem.dir\src\Logger.cpp.s

CMakeFiles/my_LogSystem.dir/src/main.cpp.obj: CMakeFiles/my_LogSystem.dir/flags.make
CMakeFiles/my_LogSystem.dir/src/main.cpp.obj: CMakeFiles/my_LogSystem.dir/includes_CXX.rsp
CMakeFiles/my_LogSystem.dir/src/main.cpp.obj: C:/Code/LogSystem/src/main.cpp
CMakeFiles/my_LogSystem.dir/src/main.cpp.obj: CMakeFiles/my_LogSystem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Code\LogSystem\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/my_LogSystem.dir/src/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my_LogSystem.dir/src/main.cpp.obj -MF CMakeFiles\my_LogSystem.dir\src\main.cpp.obj.d -o CMakeFiles\my_LogSystem.dir\src\main.cpp.obj -c C:\Code\LogSystem\src\main.cpp

CMakeFiles/my_LogSystem.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/my_LogSystem.dir/src/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Code\LogSystem\src\main.cpp > CMakeFiles\my_LogSystem.dir\src\main.cpp.i

CMakeFiles/my_LogSystem.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/my_LogSystem.dir/src/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Code\LogSystem\src\main.cpp -o CMakeFiles\my_LogSystem.dir\src\main.cpp.s

# Object files for target my_LogSystem
my_LogSystem_OBJECTS = \
"CMakeFiles/my_LogSystem.dir/src/LogQueue.cpp.obj" \
"CMakeFiles/my_LogSystem.dir/src/Logger.cpp.obj" \
"CMakeFiles/my_LogSystem.dir/src/main.cpp.obj"

# External object files for target my_LogSystem
my_LogSystem_EXTERNAL_OBJECTS =

C:/Code/LogSystem/bin/my_LogSystem.exe: CMakeFiles/my_LogSystem.dir/src/LogQueue.cpp.obj
C:/Code/LogSystem/bin/my_LogSystem.exe: CMakeFiles/my_LogSystem.dir/src/Logger.cpp.obj
C:/Code/LogSystem/bin/my_LogSystem.exe: CMakeFiles/my_LogSystem.dir/src/main.cpp.obj
C:/Code/LogSystem/bin/my_LogSystem.exe: CMakeFiles/my_LogSystem.dir/build.make
C:/Code/LogSystem/bin/my_LogSystem.exe: CMakeFiles/my_LogSystem.dir/linkLibs.rsp
C:/Code/LogSystem/bin/my_LogSystem.exe: CMakeFiles/my_LogSystem.dir/objects1.rsp
C:/Code/LogSystem/bin/my_LogSystem.exe: CMakeFiles/my_LogSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Code\LogSystem\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable C:\Code\LogSystem\bin\my_LogSystem.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\my_LogSystem.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_LogSystem.dir/build: C:/Code/LogSystem/bin/my_LogSystem.exe
.PHONY : CMakeFiles/my_LogSystem.dir/build

CMakeFiles/my_LogSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\my_LogSystem.dir\cmake_clean.cmake
.PHONY : CMakeFiles/my_LogSystem.dir/clean

CMakeFiles/my_LogSystem.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Code\LogSystem C:\Code\LogSystem C:\Code\LogSystem\build C:\Code\LogSystem\build C:\Code\LogSystem\build\CMakeFiles\my_LogSystem.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/my_LogSystem.dir/depend

