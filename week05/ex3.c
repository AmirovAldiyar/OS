#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int full, empty, al=0;

char buffer[4];

void* producer (void* args){
  while(1){
      char c = rand()%128;

      while(empty==0){
      }
      empty--;

      buffer[full]=c;

      while(full>=4){
      }
      full++;
      if(al){
        printf("1\n");
        al = 0;
      }
  }
}

void* consumer (void* args){
  while(1){
    while(full==0){
    }
    full--;
      char c = buffer[full];
      while(empty>=4){
      }
      empty++;
  }
}


void* alarmer (void* args){
  while(1){
    sleep(60);
    al = 1;
  }
}

int main(){
  pthread_t id1, id2, id3;
  full = 0;
  empty = 4;
  pthread_create(&id1, NULL, producer, NULL);
  pthread_create(&id2, NULL, consumer, NULL);
  pthread_create(&id3, NULL, alarmer, NULL);
  while(1){}
}
