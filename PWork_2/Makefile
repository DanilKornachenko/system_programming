all: clean install

install:
	@gcc thread_sample.c -o thread_sample.out
	@echo "Задача 1. Потоки-писатели: thread_samle.out"
	@gcc thread_practice.c -o thread_practice.out
	@echo "Задача 2. Потоки-писатели: thread_practice.out"
	@echo "Для запуска thread_practice введите 'make input'"
	@gcc data_race_example.c -o data_race_example.out
	@echo "Задача 2. Гонки данных (Data Race): data_race_example.out"
	@gcc fixed_data_race_example.c -o fixed_data_race_example.out
	@echo "Доп. задача (от себя) исправления в ошибках в пногопоточке: fixed_data_race_example.out"

input:
	@./thread_practice.out <<< "2 10 0 14.5 4.2 100 0 0.9 23.2 15 10 22 \n"

clean:
	@rm -f *.out && clear && ls

style:
	@clang-format -style=Google -i *.c
