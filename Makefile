GCC = gcc
FLAGS = -ansi -pedantic -Wall -std=c11 -D_POSIX_C_SOURCE=199309L

CFLAGS = -lm

PROGS = bench_project

all: $(PROGS)

bench_project:
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) bench_functions.c -c
	$(GCC) $(FLAGS) -o $@ $@.o bench_functions.o $(CFLAGS)

clean:
	$(RM) *.o $(PROGS)