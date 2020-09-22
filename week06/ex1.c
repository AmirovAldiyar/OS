#include <stdio.h>

int main(){
  int n;
  printf("Input the number of processes: " );
  scanf("%d", &n);
  float at[n], bt[n];
  for(int i = 0; i < n; i ++){
    printf("Print arrival time of the process %d: ", i+1);
    scanf("%f", &at[i]);
    printf("Print burst time of the process %d: ", i+1);
    scanf("%f", &bt[i]);
  }
  printf("P#      AT      BT      CT     TAT      WT\n");
  float ct=0;
  float tatsum=0;
  float wtsum=0;
  for(int i = 0; i < n; i ++){
    printf("P%d%8.2f%8.2f%8.2f%8.2f%8.2f\n", i+1, at[i], bt[i], (ct<at[i] ? at[i] : ct)+bt[i],(ct > at[i] ? ct-at[i] : 0)+bt[i], (ct > at[i] ? ct-at[i] : 0));
    tatsum+=(ct > at[i] ? ct-at[i] : 0)+bt[i];
    wtsum+=(ct > at[i] ? ct-at[i] : 0);
    ct=ct+bt[i];
  }
  printf("Average TAT: %f\n", tatsum/n);
  printf("Average WT: %f\n", wtsum/n);
}
