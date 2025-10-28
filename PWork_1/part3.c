#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (pid < 0) {
      perror("Fork not forking :(\n");
  } else if (pid == 0) {
      // child
      printf("Я - ребёнок, мой PID: %d\n", getpid());

      pid_t grandchild_pid = fork();

      if (grandchild_pid < 0) {
        perror("Fork 2 not forking :(\n");
      } else if (grandchild_pid == 0) {
        printf("Я - внучок ^_^, мой PID: %d\n", getpid());
      }
  } else {
      printf("Я - родитель, мой PID: %d\n", getpid());
  }

  return 0;
}
