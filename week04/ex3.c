#include <stdlib.h>
#include <stdio.h>

int are_equal(char* c, char* s){//code to check whether two strings given by pointer to char are equal
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
  while(1){//infinetely executing commands
    char* s;
    size_t size = 1024;
    getline(&s, &size, stdin);//reading the line
    if(are_equal(s, "exit")){//if write 'exit' it terminates shell
      return 0;
    }
    system(s);//executing command
  }
}
