  #include <sys/types.h>
  #include <stdio.h>
  #include <stdlib.h>

  int main(){
    pid_t pid;
    pid = fork();//forking
    int n = 12;
    if(pid > 0){//Means parent
      printf("Hello from parent [%d - %d]\n", pid, n);
    }else if (pid == 0){//Child
        printf("Hello from child [%d - %d]\n", pid, n);
    }
  }
