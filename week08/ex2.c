#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){
  void* ptr ;
  for(int i = 0; i < 10; i++){
  sleep(1);
    ptr = malloc(1024*1024*10);
    memset(ptr, 0, 1024*1024*10);
  }

}
/*
Exercise 2:
it seems that si increases, but so stays 0.
But it may be wrong as the 'si' jumps up and down even if my programm is not running.

Exercise 3:
The virtual memory changes from ~4150M to ~4250,
when physical memory changes from 0 to 100M.
*/
