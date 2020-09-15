#include <stdio.h>
#include <pthread.h>

int turn =-1;

typedef struct {
  int *id;
} thread_args;

void *printId (void *args) {

    thread_args *arguments = args;
    while(turn!=*(arguments->id)){
    }
    printf("%d - thread is running\n", *(arguments->id));
    turn = -1;
    free(arguments);
    return 0;
}
int main() {
    int N = 4;
    for (int i = 0; i < N; ++i) {
        while(turn != -1){}
        thread_args *args = malloc(sizeof *args);
        pthread_t *id = malloc(sizeof *id);
        int *i_turn = malloc(sizeof *i_turn);
        *i_turn = i;
        args->id = i_turn;
        int res = pthread_create(id, NULL, printId, args);
        if(res == 0){
          printf("Thread %d created\n", i);
          turn = i;
        }else{
          printf("Thread not created\n" );
        }
    }
    return 0;
}
