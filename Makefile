C11_FLAGS=-std=c11 -Wall -Wextra -Wpedantic

build: main.c functions.c
	cc -o env_lg main.c functions.c $(C11_FLAGS)
run: env_lg
	./env_lg
run_tests: tests/minunit.h tests/test_functions.c functions.c
	cc -o tests/run_tests tests/test_functions.c functions.c && ./tests/run_tests
