#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int full, empty, al=0;

char buffer[4];

void* producer (void* args){
  while(1){
      char c = rand()%128;
//    If there is no empty space in buffer, then just wait
      while(empty==0){
      }
      empty--;

      buffer[full]=c;

//    If there is everything is full, then just wait
      while(full>=4){
      }
      full++;
//    if al == 1 then print number and make al = 0
      if(al){
        printf("1\n");
        al = 0;
      }
  }
}

void* consumer (void* args){
  while(1){
//  if there is nothing to grab, then wait
    while(full==0){
    }
    full--;
      char c = buffer[full];
//  if there is nothing to empty, then wait
      while(empty>=4){
      }
      empty++;
  }
}


void* alarmer (void* args){
  while(1){
    //sleeps 60 sec and then makes al equal to 1
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
