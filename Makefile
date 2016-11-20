CC=g++
CFLAGS=-std=c++11 -g -Wall

#SOURCES=$(shell find . *.cpp)
CPP=$(shell ls | grep .cpp)
OBJ=$(patsubst %.cpp, %.o, $(CPP))
EXE=$(patsubst %.cpp, %, $(CPP))

all: $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -o$(patsubst %.o, %, $@)$(patsubst %.o, %.cpp, $@)

clean:
	rm -rf$(EXE)
