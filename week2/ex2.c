#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 128

int main(){
  char s[MAX_STRING_LEN];
  scanf("%s", s);
  for(int i = strlen(s)-1; i >= 0; i --){
    printf("%c", s[i]);
  }
}
