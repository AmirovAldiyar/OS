#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int are_equal(char* c, char* s){
  while(*c == *s){
    if(*c == '\0' || *s == '\0'){
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
    char* args[50];
    int cnt = 0, cur = 0;
    for(int i = 0; i < 50; i ++){//execvp arguments should end with null, also we have to clear information from previous
      args[i]=NULL;
    }
    args[0]=(char*)malloc(512);//allocating memory for new token
    getline(&s, &size, stdin);//reading line from console
    for(int i = 0; i < strlen(s)-1; i ++){//splitting line into tokens
      if(s[i] != ' '){//if it is not a space then we should add this symbol to the current token
        args[cnt][cur++]=s[i];
      }else{//else we should allocate memory for next token, and make cur variable zero so that we will fill next from the beginning
        cur = 0;
        args[++cnt]=(char*)malloc(512);//allocating memory for another token
      }
    }
    int n = fork();//making fork
    if(n == 0)//if it is child then execute
    execvp(args[0], args);

  }
}
