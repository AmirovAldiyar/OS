#include <stdio.h>

struct process{
  int i;
  float at;
  float bt;
};

int main(){
  int n;
  printf("Input the number of processes: " );
  scanf("%d", &n);
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
  }

  for(int i = 0; i < n; i ++){
    for(int j = i; j < n; j ++){
      if(p[i].at > p[j].at){
        struct process tmp = p[i];
        p[i] = p[j];
        p[j] = tmp;
      }
    }
  }

  printf("P#      AT      BT      CT     TAT      WT\n");
  float ct=0;
  float tatsum=0;
  float wtsum=0;
  for(int i = 0; i < n; i ++){
    int it = p[i].i;
    float ati = p[i].at;
    float bti = p[i].bt;
    printf("P%d%8.2f%8.2f%8.2f%8.2f%8.2f\n", it+1, ati, bti, (ct<ati ? ati : ct)+bti,(ct > ati ? ct-ati : 0)+bti, (ct > ati ? ct-ati : 0));
    tatsum+=(ct > ati ? ct-ati : 0)+bti;
    wtsum+=(ct > ati ? ct-ati : 0);
    ct=ct+bti;
  }
  printf("Average TAT: %f\n", tatsum/n);
  printf("Average WT: %f\n", wtsum/n);
}
