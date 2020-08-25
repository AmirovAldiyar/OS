#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 128

int main(int argc, char **argv){
  int n;
  sscanf(argv[1], "%d", &n);
  int width = 2*n-1;
  for(int i = 1;i <= n; i ++){
    int spaces = (width - 2*i + 1)/2;
    for(int j = 0; j < spaces; j ++){
      printf("%c", ' ');
    }
    for(int j = 0; j < i*2-1; j ++){
      printf("%c", '*');
    }
    printf("\n");
  }
}
