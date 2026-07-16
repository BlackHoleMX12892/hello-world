CC = gcc
CXX = g++

CFLAGS = -Wall -Wextra -Wpedantic -std=c17 -g
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++20 -g

target:
	$(CC) main.c -o interpreter $(CFLAGS)
	$(CXX) assembler/main.cpp -o assembler/assembler $(CXXFLAGS)
