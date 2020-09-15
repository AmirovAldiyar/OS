#include <stdio.h>
#include <pthread.h>

//turn: -1 means main function. Any other means thread's turn
int turn =-1;

//id is the number of the thread
typedef struct {
  int *id;
} thread_args;

void *printId (void *args) {

    thread_args *arguments = args;
    //waits until main function prints "Thread <n> created"
    while(turn!=*(arguments->id)){
    }
    //Prints the sentence
    printf("%d - thread is running\n", *(arguments->id));
    //finishing work
    turn = -1;
    free(arguments);
    return 0;
}
int main() {
    int N = 4;
    for (int i = 0; i < N; ++i) {
        //wait til the thread finishes it's work
        while(turn != -1){}
        //allocate memory for arguments
        thread_args *args = malloc(sizeof *args);
        //allocate memory for id
        pthread_t *id = malloc(sizeof *id);
        //allocate memory for the number of the thread
        int *i_turn = malloc(sizeof *i_turn);
        *i_turn = i;
        args->id = i_turn;
        //create a thread
        int res = pthread_create(id, NULL, printId, args);
        //pthread_create return 0 if everything's OK
        if(res == 0){
          printf("Thread %d created\n", i);
          turn = i;
        }else{//if there is some problems
          printf("Thread not created\n" );
        }
    }
    return 0;
}
