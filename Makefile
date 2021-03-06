# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jgallagh/cs102/projects/finalproject9/project09-hackathon-james-gallagher

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jgallagh/cs102/projects/finalproject9/project09-hackathon-james-gallagher

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jgallagh/cs102/projects/finalproject9/project09-hackathon-james-gallagher/CMakeFiles /home/jgallagh/cs102/projects/finalproject9/project09-hackathon-james-gallagher/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jgallagh/cs102/projects/finalproject9/project09-hackathon-james-gallagher/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

Collectible.o: Collectible.cpp.o

.PHONY : Collectible.o

# target to build an object file
Collectible.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Collectible.cpp.o
.PHONY : Collectible.cpp.o

Collectible.i: Collectible.cpp.i

.PHONY : Collectible.i

# target to preprocess a source file
Collectible.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Collectible.cpp.i
.PHONY : Collectible.cpp.i

Collectible.s: Collectible.cpp.s

.PHONY : Collectible.s

# target to generate assembly for a file
Collectible.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Collectible.cpp.s
.PHONY : Collectible.cpp.s

Collectible_Manager.o: Collectible_Manager.cpp.o

.PHONY : Collectible_Manager.o

# target to build an object file
Collectible_Manager.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Collectible_Manager.cpp.o
.PHONY : Collectible_Manager.cpp.o

Collectible_Manager.i: Collectible_Manager.cpp.i

.PHONY : Collectible_Manager.i

# target to preprocess a source file
Collectible_Manager.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Collectible_Manager.cpp.i
.PHONY : Collectible_Manager.cpp.i

Collectible_Manager.s: Collectible_Manager.cpp.s

.PHONY : Collectible_Manager.s

# target to generate assembly for a file
Collectible_Manager.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Collectible_Manager.cpp.s
.PHONY : Collectible_Manager.cpp.s

Enemy.o: Enemy.cpp.o

.PHONY : Enemy.o

# target to build an object file
Enemy.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Enemy.cpp.o
.PHONY : Enemy.cpp.o

Enemy.i: Enemy.cpp.i

.PHONY : Enemy.i

# target to preprocess a source file
Enemy.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Enemy.cpp.i
.PHONY : Enemy.cpp.i

Enemy.s: Enemy.cpp.s

.PHONY : Enemy.s

# target to generate assembly for a file
Enemy.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Enemy.cpp.s
.PHONY : Enemy.cpp.s

Enemy_Manager.o: Enemy_Manager.cpp.o

.PHONY : Enemy_Manager.o

# target to build an object file
Enemy_Manager.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Enemy_Manager.cpp.o
.PHONY : Enemy_Manager.cpp.o

Enemy_Manager.i: Enemy_Manager.cpp.i

.PHONY : Enemy_Manager.i

# target to preprocess a source file
Enemy_Manager.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Enemy_Manager.cpp.i
.PHONY : Enemy_Manager.cpp.i

Enemy_Manager.s: Enemy_Manager.cpp.s

.PHONY : Enemy_Manager.s

# target to generate assembly for a file
Enemy_Manager.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Enemy_Manager.cpp.s
.PHONY : Enemy_Manager.cpp.s

Game_Generator.o: Game_Generator.cpp.o

.PHONY : Game_Generator.o

# target to build an object file
Game_Generator.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Game_Generator.cpp.o
.PHONY : Game_Generator.cpp.o

Game_Generator.i: Game_Generator.cpp.i

.PHONY : Game_Generator.i

# target to preprocess a source file
Game_Generator.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Game_Generator.cpp.i
.PHONY : Game_Generator.cpp.i

Game_Generator.s: Game_Generator.cpp.s

.PHONY : Game_Generator.s

# target to generate assembly for a file
Game_Generator.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Game_Generator.cpp.s
.PHONY : Game_Generator.cpp.s

Game_Player.o: Game_Player.cpp.o

.PHONY : Game_Player.o

# target to build an object file
Game_Player.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Game_Player.cpp.o
.PHONY : Game_Player.cpp.o

Game_Player.i: Game_Player.cpp.i

.PHONY : Game_Player.i

# target to preprocess a source file
Game_Player.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Game_Player.cpp.i
.PHONY : Game_Player.cpp.i

Game_Player.s: Game_Player.cpp.s

.PHONY : Game_Player.s

# target to generate assembly for a file
Game_Player.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Game_Player.cpp.s
.PHONY : Game_Player.cpp.s

Obstacle.o: Obstacle.cpp.o

.PHONY : Obstacle.o

# target to build an object file
Obstacle.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Obstacle.cpp.o
.PHONY : Obstacle.cpp.o

Obstacle.i: Obstacle.cpp.i

.PHONY : Obstacle.i

# target to preprocess a source file
Obstacle.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Obstacle.cpp.i
.PHONY : Obstacle.cpp.i

Obstacle.s: Obstacle.cpp.s

.PHONY : Obstacle.s

# target to generate assembly for a file
Obstacle.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Obstacle.cpp.s
.PHONY : Obstacle.cpp.s

Obstacle_Manager.o: Obstacle_Manager.cpp.o

.PHONY : Obstacle_Manager.o

# target to build an object file
Obstacle_Manager.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Obstacle_Manager.cpp.o
.PHONY : Obstacle_Manager.cpp.o

Obstacle_Manager.i: Obstacle_Manager.cpp.i

.PHONY : Obstacle_Manager.i

# target to preprocess a source file
Obstacle_Manager.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Obstacle_Manager.cpp.i
.PHONY : Obstacle_Manager.cpp.i

Obstacle_Manager.s: Obstacle_Manager.cpp.s

.PHONY : Obstacle_Manager.s

# target to generate assembly for a file
Obstacle_Manager.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Obstacle_Manager.cpp.s
.PHONY : Obstacle_Manager.cpp.s

Player.o: Player.cpp.o

.PHONY : Player.o

# target to build an object file
Player.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Player.cpp.o
.PHONY : Player.cpp.o

Player.i: Player.cpp.i

.PHONY : Player.i

# target to preprocess a source file
Player.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Player.cpp.i
.PHONY : Player.cpp.i

Player.s: Player.cpp.s

.PHONY : Player.s

# target to generate assembly for a file
Player.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Player.cpp.s
.PHONY : Player.cpp.s

Room_Generator.o: Room_Generator.cpp.o

.PHONY : Room_Generator.o

# target to build an object file
Room_Generator.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Room_Generator.cpp.o
.PHONY : Room_Generator.cpp.o

Room_Generator.i: Room_Generator.cpp.i

.PHONY : Room_Generator.i

# target to preprocess a source file
Room_Generator.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Room_Generator.cpp.i
.PHONY : Room_Generator.cpp.i

Room_Generator.s: Room_Generator.cpp.s

.PHONY : Room_Generator.s

# target to generate assembly for a file
Room_Generator.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Room_Generator.cpp.s
.PHONY : Room_Generator.cpp.s

Window_Generator.o: Window_Generator.cpp.o

.PHONY : Window_Generator.o

# target to build an object file
Window_Generator.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Window_Generator.cpp.o
.PHONY : Window_Generator.cpp.o

Window_Generator.i: Window_Generator.cpp.i

.PHONY : Window_Generator.i

# target to preprocess a source file
Window_Generator.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Window_Generator.cpp.i
.PHONY : Window_Generator.cpp.i

Window_Generator.s: Window_Generator.cpp.s

.PHONY : Window_Generator.s

# target to generate assembly for a file
Window_Generator.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Window_Generator.cpp.s
.PHONY : Window_Generator.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... main"
	@echo "... Collectible.o"
	@echo "... Collectible.i"
	@echo "... Collectible.s"
	@echo "... Collectible_Manager.o"
	@echo "... Collectible_Manager.i"
	@echo "... Collectible_Manager.s"
	@echo "... Enemy.o"
	@echo "... Enemy.i"
	@echo "... Enemy.s"
	@echo "... Enemy_Manager.o"
	@echo "... Enemy_Manager.i"
	@echo "... Enemy_Manager.s"
	@echo "... Game_Generator.o"
	@echo "... Game_Generator.i"
	@echo "... Game_Generator.s"
	@echo "... Game_Player.o"
	@echo "... Game_Player.i"
	@echo "... Game_Player.s"
	@echo "... Obstacle.o"
	@echo "... Obstacle.i"
	@echo "... Obstacle.s"
	@echo "... Obstacle_Manager.o"
	@echo "... Obstacle_Manager.i"
	@echo "... Obstacle_Manager.s"
	@echo "... Player.o"
	@echo "... Player.i"
	@echo "... Player.s"
	@echo "... Room_Generator.o"
	@echo "... Room_Generator.i"
	@echo "... Room_Generator.s"
	@echo "... Window_Generator.o"
	@echo "... Window_Generator.i"
	@echo "... Window_Generator.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

