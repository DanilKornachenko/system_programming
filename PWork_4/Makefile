

all: clean compile leak_check

compile:
	@gcc hello.c -o hello
	@gcc leaks.c -o leaks
	@gcc overflow.c -o overflow
	@gcc --coverage abs_example.c -o abs_example
	@gcc --coverage currect_abs.c -o currect_abs

leak_check:
	@mkdir -p logs
	@valgrind ./hello 2> logs/hello.log
	@valgrind ./leaks 2> logs/leaks.log
	@valgrind ./overflow 2> logs/overflow.log
	@./abs_example
	@gcov abs_example.c > logs/abs_example.log
	@./currect_abs
	@gcov currect_abs.c > logs/currect_abs.log

clean:
	@rm -f hello
	@rm -f leaks
	@rm -f overflow
	@rm -rf logs
	@rm -f abs_example
	@rm -f abs_example.c.gcov
	@rm -f abs_example.gcda
	@rm -f abs_example.gcno
	@rm -f currect_abs
	@rm -f currect_abs.c.gcov
	@rm -f currect_abs.gcda
	@rm -f currect_abs.gcno
	@rm -f vgcore*
