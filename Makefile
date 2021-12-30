CC=clang++
CFLAGS=-flto -O3 -march=native -funroll-loops -std=c++20 Main.cpp

default: all

all: Main.cpp
	$(CC) $(CFLAGS) -o movegen_compare
	