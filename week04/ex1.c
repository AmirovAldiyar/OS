  #include <sys/types.h>
  #include <stdio.h>
  #include <stdlib.h>

  int main(){
    pid_t pid;
    pid = fork();
    int n = 12;
    if(pid > 0){
      printf("Hello from parent [%d - %d]\n", pid, n);
    }else if (pid == 0){
        printf("Hello from child [%d - %d]\n", pid, n);
    }
  }
