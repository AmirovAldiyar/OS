#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

int main(){
  void* ptr ;
  for(int i = 0; i < 10; i++){
  sleep(1);
    ptr = malloc(1024*1024*10);
    memset(ptr, 0, 1024*1024*10);
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    printf("%ld\n", usage.ru_maxrss);
  }
}
/*
in the sys/resourse.h library there is 'rusage' structure that has ru_maxrss field which represent memory usage.
and RUSAGE_SELF is a constant.
*/
