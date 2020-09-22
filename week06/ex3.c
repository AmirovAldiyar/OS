#include <stdio.h>

struct process{
  int i;
  float at;
  float bt;
  float ct;
  float tat;
  float wt;
  float rm; //remaining burst time
};
/*
for the test:
Process 1: arrival time - 0 burst time - 4
Process 2: arrival time - 0 burst time - 1
Process 2: arrival time - 0 burst time - 1
quantum = 2
the average TAT and WT round robin is less comparing to the FCFS and SJF
*/
int main(){
  int n;
  printf("Input the number of processes: " );
  scanf("%d", &n);
  float q;
  printf("Input the quantum: " );
  scanf("%f", &q);
  float at[n], bt[n];
  struct  process p[n];
  for(int i = 0; i < n; i ++){
    printf("Print arrival time of the process %d: ", i+1);
    scanf("%f", &at[i]);
    printf("Print burst time of the process %d: ", i+1);
    scanf("%f", &bt[i]);
    p[i].at=at[i];
    p[i].bt=bt[i];
    p[i].i=i;
    p[i].rm=bt[i];
  }
  int done=0;
  int time=0;
  int cur=0;
  while(done != n){
    int found = 0;
    if(p[cur].rm > 0){
      time += (p[cur].rm > q ? q : p[cur].rm);
      p[cur].rm -= (p[cur].rm > q ? q : p[cur].rm);
      if(p[cur].rm == 0){
        p[cur].tat = time-p[cur].at;
        p[cur].ct = p[cur].tat + p[cur].at;
        p[cur].wt = p[cur].tat - p[cur].bt;
        done++;
      }
      for(int i = cur+1; i < n; i ++){
        if(p[i].at <= time && p[i].rm > 0){
          cur = i;
          found = 1;
          break;
        }
      }
      if(found){
        continue;
      }
      for(int i = 0; i < cur; i ++){
        if(p[i].at <= time && p[i].rm > 0){
          cur = i;
          found = 1;
          break;
        }
      }
      if(found){
        continue;
      }
    }
    printf("%d\n", done);
    for(int i = cur+1; i < n; i ++){
      if(p[i].at <= time && p[i].rm > 0){
        cur = i;
        found = 1;
        break;
      }
    }
    if(found){
      continue;
    }
    for(int i = 0; i < cur; i ++){
      if(p[i].at <= time && p[i].rm > 0){
        cur = i;
        found = 1;
        break;
      }
    }
    if(found){
      continue;
    }
    time++;
  }

  printf("P#      AT      BT      CT     TAT      WT\n");
  float ct=0;
  float tatsum=0;
  float wtsum=0;
  for(int i = 0; i < n; i ++){
    int it = p[i].i;
    float ati = p[i].at;
    float bti = p[i].bt;
    float ct = p[i].ct;
    float wt = p[i].wt;
    float tat = p[i].tat;
    printf("P%d%8.2f%8.2f%8.2f%8.2f%8.2f\n", it+1, ati, bti, ct, tat, wt);
    tatsum+=tat;
    wtsum+=wt;
  }
  printf("Average TAT: %f\n", tatsum/n);
  printf("Average WT: %f\n", wtsum/n);
}
