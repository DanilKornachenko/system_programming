#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

volatile sig_atomic_t stop_flag = 0;

void term_handler(int sig) { stop_flag = 1; }

int main() {
  pid_t pid = fork();

  if (pid < 0) exit(EXIT_FAILURE);
  if (pid > 0) exit(EXIT_SUCCESS);  // Родитель завершается

  umask(0);
  setsid();
  chdir("/");

  // Закрываем стандартные дескрипторы
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  signal(SIGTERM, term_handler);

  while (!stop_flag) {
    // Логирование в файл
    FILE* log = fopen("/tmp/daemon.log", "a");
    if (log) {
      fprintf(log, "Демон работает...\n");
      fclose(log);
    }
    sleep(5);
  }

  // Корректный выход
  FILE* log = fopen("/tmp/daemon.log", "a");
  fprintf(log, "Демон остановлен!\n");
  fclose(log);

  return 0;
}
