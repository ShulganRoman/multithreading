# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/romanshulgan/reps/multithreading

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/romanshulgan/reps/multithreading/out/Debug

# Include any dependencies generated for this target.
include CMakeFiles/projectTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/projectTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/projectTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projectTests.dir/flags.make

CMakeFiles/projectTests.dir/codegen:
.PHONY : CMakeFiles/projectTests.dir/codegen

CMakeFiles/projectTests.dir/tests/ChatTest.cpp.o: CMakeFiles/projectTests.dir/flags.make
CMakeFiles/projectTests.dir/tests/ChatTest.cpp.o: /Users/romanshulgan/reps/multithreading/tests/ChatTest.cpp
CMakeFiles/projectTests.dir/tests/ChatTest.cpp.o: CMakeFiles/projectTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/romanshulgan/reps/multithreading/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/projectTests.dir/tests/ChatTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projectTests.dir/tests/ChatTest.cpp.o -MF CMakeFiles/projectTests.dir/tests/ChatTest.cpp.o.d -o CMakeFiles/projectTests.dir/tests/ChatTest.cpp.o -c /Users/romanshulgan/reps/multithreading/tests/ChatTest.cpp

CMakeFiles/projectTests.dir/tests/ChatTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projectTests.dir/tests/ChatTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romanshulgan/reps/multithreading/tests/ChatTest.cpp > CMakeFiles/projectTests.dir/tests/ChatTest.cpp.i

CMakeFiles/projectTests.dir/tests/ChatTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projectTests.dir/tests/ChatTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romanshulgan/reps/multithreading/tests/ChatTest.cpp -o CMakeFiles/projectTests.dir/tests/ChatTest.cpp.s

CMakeFiles/projectTests.dir/tests/DatabaseTests.cpp.o: CMakeFiles/projectTests.dir/flags.make
CMakeFiles/projectTests.dir/tests/DatabaseTests.cpp.o: /Users/romanshulgan/reps/multithreading/tests/DatabaseTests.cpp
CMakeFiles/projectTests.dir/tests/DatabaseTests.cpp.o: CMakeFiles/projectTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/romanshulgan/reps/multithreading/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/projectTests.dir/tests/DatabaseTests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projectTests.dir/tests/DatabaseTests.cpp.o -MF CMakeFiles/projectTests.dir/tests/DatabaseTests.cpp.o.d -o CMakeFiles/projectTests.dir/tests/DatabaseTests.cpp.o -c /Users/romanshulgan/reps/multithreading/tests/DatabaseTests.cpp

CMakeFiles/projectTests.dir/tests/DatabaseTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projectTests.dir/tests/DatabaseTests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romanshulgan/reps/multithreading/tests/DatabaseTests.cpp > CMakeFiles/projectTests.dir/tests/DatabaseTests.cpp.i

CMakeFiles/projectTests.dir/tests/DatabaseTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projectTests.dir/tests/DatabaseTests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romanshulgan/reps/multithreading/tests/DatabaseTests.cpp -o CMakeFiles/projectTests.dir/tests/DatabaseTests.cpp.s

CMakeFiles/projectTests.dir/tests/NetworkTest.cpp.o: CMakeFiles/projectTests.dir/flags.make
CMakeFiles/projectTests.dir/tests/NetworkTest.cpp.o: /Users/romanshulgan/reps/multithreading/tests/NetworkTest.cpp
CMakeFiles/projectTests.dir/tests/NetworkTest.cpp.o: CMakeFiles/projectTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/romanshulgan/reps/multithreading/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/projectTests.dir/tests/NetworkTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projectTests.dir/tests/NetworkTest.cpp.o -MF CMakeFiles/projectTests.dir/tests/NetworkTest.cpp.o.d -o CMakeFiles/projectTests.dir/tests/NetworkTest.cpp.o -c /Users/romanshulgan/reps/multithreading/tests/NetworkTest.cpp

CMakeFiles/projectTests.dir/tests/NetworkTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projectTests.dir/tests/NetworkTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romanshulgan/reps/multithreading/tests/NetworkTest.cpp > CMakeFiles/projectTests.dir/tests/NetworkTest.cpp.i

CMakeFiles/projectTests.dir/tests/NetworkTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projectTests.dir/tests/NetworkTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romanshulgan/reps/multithreading/tests/NetworkTest.cpp -o CMakeFiles/projectTests.dir/tests/NetworkTest.cpp.s

CMakeFiles/projectTests.dir/tests/UserTest.cpp.o: CMakeFiles/projectTests.dir/flags.make
CMakeFiles/projectTests.dir/tests/UserTest.cpp.o: /Users/romanshulgan/reps/multithreading/tests/UserTest.cpp
CMakeFiles/projectTests.dir/tests/UserTest.cpp.o: CMakeFiles/projectTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/romanshulgan/reps/multithreading/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/projectTests.dir/tests/UserTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projectTests.dir/tests/UserTest.cpp.o -MF CMakeFiles/projectTests.dir/tests/UserTest.cpp.o.d -o CMakeFiles/projectTests.dir/tests/UserTest.cpp.o -c /Users/romanshulgan/reps/multithreading/tests/UserTest.cpp

CMakeFiles/projectTests.dir/tests/UserTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projectTests.dir/tests/UserTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romanshulgan/reps/multithreading/tests/UserTest.cpp > CMakeFiles/projectTests.dir/tests/UserTest.cpp.i

CMakeFiles/projectTests.dir/tests/UserTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projectTests.dir/tests/UserTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romanshulgan/reps/multithreading/tests/UserTest.cpp -o CMakeFiles/projectTests.dir/tests/UserTest.cpp.s

# Object files for target projectTests
projectTests_OBJECTS = \
"CMakeFiles/projectTests.dir/tests/ChatTest.cpp.o" \
"CMakeFiles/projectTests.dir/tests/DatabaseTests.cpp.o" \
"CMakeFiles/projectTests.dir/tests/NetworkTest.cpp.o" \
"CMakeFiles/projectTests.dir/tests/UserTest.cpp.o"

# External object files for target projectTests
projectTests_EXTERNAL_OBJECTS =

projectTests: CMakeFiles/projectTests.dir/tests/ChatTest.cpp.o
projectTests: CMakeFiles/projectTests.dir/tests/DatabaseTests.cpp.o
projectTests: CMakeFiles/projectTests.dir/tests/NetworkTest.cpp.o
projectTests: CMakeFiles/projectTests.dir/tests/UserTest.cpp.o
projectTests: CMakeFiles/projectTests.dir/build.make
projectTests: src/server/libserver.a
projectTests: /opt/homebrew/lib/libboost_system.dylib
projectTests: /opt/homebrew/lib/libboost_thread.dylib
projectTests: lib/libgtest_main.a
projectTests: src/user/libuser.a
projectTests: src/chat/libchat.a
projectTests: src/db/libdb.a
projectTests: lib/libgtest.a
projectTests: CMakeFiles/projectTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/romanshulgan/reps/multithreading/out/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable projectTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projectTests.dir/link.txt --verbose=$(VERBOSE)
	/opt/homebrew/bin/cmake -D TEST_TARGET=projectTests -D TEST_EXECUTABLE=/Users/romanshulgan/reps/multithreading/out/Debug/projectTests -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/romanshulgan/reps/multithreading/out/Debug -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=projectTests_TESTS -D CTEST_FILE=/Users/romanshulgan/reps/multithreading/out/Debug/projectTests[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_DISCOVERY_EXTRA_ARGS= -D TEST_XML_OUTPUT_DIR= -P /opt/homebrew/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/projectTests.dir/build: projectTests
.PHONY : CMakeFiles/projectTests.dir/build

CMakeFiles/projectTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projectTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projectTests.dir/clean

CMakeFiles/projectTests.dir/depend:
	cd /Users/romanshulgan/reps/multithreading/out/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/romanshulgan/reps/multithreading /Users/romanshulgan/reps/multithreading /Users/romanshulgan/reps/multithreading/out/Debug /Users/romanshulgan/reps/multithreading/out/Debug /Users/romanshulgan/reps/multithreading/out/Debug/CMakeFiles/projectTests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/projectTests.dir/depend

