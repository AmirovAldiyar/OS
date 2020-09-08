#include <sys/types.h>
#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int main(){
  for(int i = 0; i < 5; i ++){// in case we have 3 fork it leads to 8 processes, in case 5 it leads to 32 processes
    //that happens because every fork() doubles the number of processor so the number is
    //2^n where n number of fork()'s
    fork();
  }
  sleep(5);
}
