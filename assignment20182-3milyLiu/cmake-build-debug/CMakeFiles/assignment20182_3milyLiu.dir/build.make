# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\assignment20182_3milyLiu.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\assignment20182_3milyLiu.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\assignment20182_3milyLiu.dir\flags.make

CMakeFiles\assignment20182_3milyLiu.dir\MapOfItemsTest.cpp.obj: CMakeFiles\assignment20182_3milyLiu.dir\flags.make
CMakeFiles\assignment20182_3milyLiu.dir\MapOfItemsTest.cpp.obj: ..\MapOfItemsTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/assignment20182_3milyLiu.dir/MapOfItemsTest.cpp.obj"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\assignment20182_3milyLiu.dir\MapOfItemsTest.cpp.obj /FdCMakeFiles\assignment20182_3milyLiu.dir\ /FS -c C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\MapOfItemsTest.cpp
<<

CMakeFiles\assignment20182_3milyLiu.dir\MapOfItemsTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment20182_3milyLiu.dir/MapOfItemsTest.cpp.i"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\assignment20182_3milyLiu.dir\MapOfItemsTest.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\MapOfItemsTest.cpp
<<

CMakeFiles\assignment20182_3milyLiu.dir\MapOfItemsTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment20182_3milyLiu.dir/MapOfItemsTest.cpp.s"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\assignment20182_3milyLiu.dir\MapOfItemsTest.cpp.s /c C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\MapOfItemsTest.cpp
<<

CMakeFiles\assignment20182_3milyLiu.dir\TestStack.cpp.obj: CMakeFiles\assignment20182_3milyLiu.dir\flags.make
CMakeFiles\assignment20182_3milyLiu.dir\TestStack.cpp.obj: ..\TestStack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/assignment20182_3milyLiu.dir/TestStack.cpp.obj"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\assignment20182_3milyLiu.dir\TestStack.cpp.obj /FdCMakeFiles\assignment20182_3milyLiu.dir\ /FS -c C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\TestStack.cpp
<<

CMakeFiles\assignment20182_3milyLiu.dir\TestStack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment20182_3milyLiu.dir/TestStack.cpp.i"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\assignment20182_3milyLiu.dir\TestStack.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\TestStack.cpp
<<

CMakeFiles\assignment20182_3milyLiu.dir\TestStack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment20182_3milyLiu.dir/TestStack.cpp.s"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\assignment20182_3milyLiu.dir\TestStack.cpp.s /c C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\TestStack.cpp
<<

CMakeFiles\assignment20182_3milyLiu.dir\TestStringCons.cpp.obj: CMakeFiles\assignment20182_3milyLiu.dir\flags.make
CMakeFiles\assignment20182_3milyLiu.dir\TestStringCons.cpp.obj: ..\TestStringCons.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/assignment20182_3milyLiu.dir/TestStringCons.cpp.obj"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\assignment20182_3milyLiu.dir\TestStringCons.cpp.obj /FdCMakeFiles\assignment20182_3milyLiu.dir\ /FS -c C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\TestStringCons.cpp
<<

CMakeFiles\assignment20182_3milyLiu.dir\TestStringCons.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment20182_3milyLiu.dir/TestStringCons.cpp.i"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\assignment20182_3milyLiu.dir\TestStringCons.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\TestStringCons.cpp
<<

CMakeFiles\assignment20182_3milyLiu.dir\TestStringCons.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment20182_3milyLiu.dir/TestStringCons.cpp.s"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\assignment20182_3milyLiu.dir\TestStringCons.cpp.s /c C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\TestStringCons.cpp
<<

# Object files for target assignment20182_3milyLiu
assignment20182_3milyLiu_OBJECTS = \
"CMakeFiles\assignment20182_3milyLiu.dir\MapOfItemsTest.cpp.obj" \
"CMakeFiles\assignment20182_3milyLiu.dir\TestStack.cpp.obj" \
"CMakeFiles\assignment20182_3milyLiu.dir\TestStringCons.cpp.obj"

# External object files for target assignment20182_3milyLiu
assignment20182_3milyLiu_EXTERNAL_OBJECTS =

assignment20182_3milyLiu.exe: CMakeFiles\assignment20182_3milyLiu.dir\MapOfItemsTest.cpp.obj
assignment20182_3milyLiu.exe: CMakeFiles\assignment20182_3milyLiu.dir\TestStack.cpp.obj
assignment20182_3milyLiu.exe: CMakeFiles\assignment20182_3milyLiu.dir\TestStringCons.cpp.obj
assignment20182_3milyLiu.exe: CMakeFiles\assignment20182_3milyLiu.dir\build.make
assignment20182_3milyLiu.exe: CMakeFiles\assignment20182_3milyLiu.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable assignment20182_3milyLiu.exe"
	"C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\assignment20182_3milyLiu.dir --manifests  -- C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\assignment20182_3milyLiu.dir\objects1.rsp @<<
 /out:assignment20182_3milyLiu.exe /implib:assignment20182_3milyLiu.lib /pdb:C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\cmake-build-debug\assignment20182_3milyLiu.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\assignment20182_3milyLiu.dir\build: assignment20182_3milyLiu.exe

.PHONY : CMakeFiles\assignment20182_3milyLiu.dir\build

CMakeFiles\assignment20182_3milyLiu.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\assignment20182_3milyLiu.dir\cmake_clean.cmake
.PHONY : CMakeFiles\assignment20182_3milyLiu.dir\clean

CMakeFiles\assignment20182_3milyLiu.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\cmake-build-debug C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\cmake-build-debug C:\Users\emily\Documents\GitHub\assignment20182-3milyLiu\cmake-build-debug\CMakeFiles\assignment20182_3milyLiu.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\assignment20182_3milyLiu.dir\depend
