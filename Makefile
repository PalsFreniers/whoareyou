CC=g++
BUILD=main
SOURCES=$(wildcard lib/src/*.cpp)
CXXFLAGS= -O3
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

.PHONY: main

all: main debug

run: main
	@echo "Running program"
	@./main

main: main.cpp
	@echo "building release version of the program"
	@$(CC) -o $(BUILD) main.cpp $(SOURCES) $(CXXFLAGS) $(LIBS)

debug: main.cpp
	@echo "build program with debug tools"
	@$(CC) -g main.cpp $(SOURCES) $(LIBS)
