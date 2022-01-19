#OBJS specifies which files to compile as part of the project
OBJS = $(wildcard src/*.cpp) \
       $(wildcard src/rope/*.cpp) \
	   $(wildcard src/dynamics/*.cpp) \
	   $(wildcard src/common/*.cpp) \
	   $(wildcard src/collision/*.cpp)

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = game

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)