CC=clang++
CFLAGS= -O3 -mllvm -inline-threshold=16000 -fdeclspec -march=native -funroll-loops -std=c++20 -pthread Main.cpp
# -flto
default: all

all: Main.cpp
	$(CC) $(CFLAGS) -o movegen_compare
	