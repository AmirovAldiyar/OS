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
    for(int i = 0; i < 50; i ++){
      args[i]=NULL;
    }
    args[0]=(char*)malloc(512);
    getline(&s, &size, stdin);
    for(int i = 0; i < strlen(s)-1; i ++){
      if(s[i] != ' '){
        args[cnt][cur++]=s[i];
      }else{
        cur = 0;
        args[++cnt]=(char*)malloc(512);
      }
    }
    int n = fork();
    char* envp[] = {NULL};
    if(n == 0)
    execvp(args[0], args);

  }
}

// int main(){
//   char* argv[] = {"&", NULL};
//   char* envp[] = {NULL};
//   execve("./ex2.out", argv, envp);
// }
