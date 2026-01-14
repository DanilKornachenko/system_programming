main := main.c
libs := lib/*.c

all: clean compile run

compile:
	@gcc $(main) $(libs) -o pointers.out

run:
	./pointers.out

test_leaks: clean compile
	valgrind -s ./pointers.out

clean:
	@rm -f pointers.out
