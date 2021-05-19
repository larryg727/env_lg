C11_FLAGS=-std=c11 -Wall -Wextra -Wpedantic

build: main.c functions.c
	cc -o env_lg main.c functions.c $(C11_FLAGS)
debug: main.c functions.c
	cc -g -o env_lg_debug main.c functions.c && gdb env_lg_debug || lldb env_lg_debug
run_tests: tests/minunit.h tests/test_functions.c functions.c
	cc -o tests/run_tests tests/test_functions.c functions.c && ./tests/run_tests
