#include <stdlib.h>
#include <stdio.h>

int are_equal(char* c, char* s){
  while(*c == *s){
    if(*c == '\0' || s == '\0'){
      break;
    }
    c ++;
    s++;
  }
  if(*c != '\0' || *s != '\0'){
    return 0;
  }
  return 1;
}

int main(){
  printf("Please type 'exit' to terminate the shell\n");
  while(1){
    char* s;
    size_t size = 1024;
    getline(&s, &size, stdin);
    if(are_equal(s, "exit")){
      return 0;
    }
    system(s);
  }
}
