all: clean install run

install:
	@gcc main.c -o my_daemon
	@echo "Программа-демон скомпилирована."

run:
	@./my_daemon
	@echo -e "Программа-демон запущена. \n(Лог файл находится в /tmp/daemon.log)\nДля остановки демона напишите команду 'pkill -TERM my_daemon' или 'make stop'"

clean:
	@rm -f my_daemon
	@rm -f /tmp/daemon.log
	@echo "Все файлы программы удалены..."

stop:
	@pkill -TERM my_daemon
	@echo "Демон остановлен."
