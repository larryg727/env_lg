C11_FLAGS=-std=c11 -Wall -Wextra -Wpedantic

env_make: main.c functions.c
	cc -o env_lg main.c functions.c $(C11_FLAGS)