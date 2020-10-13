#include <stdio.h>

int main(){
  int page_n = 0;
  printf("Number of pages: \n");
  scanf("%d", &page_n);
  int refs_n = 0;
  printf("Number of references: \n");
  scanf("%d", &refs_n);
  FILE *fp;
  long long v[page_n];
  int pages[page_n];
  for(int i = 0; i < page_n; i++){
    v[i] = 0;
    pages[i] = -1;
  }
  fp = fopen("input.txt", "r");
  int miss = 0;
  int hit = 0;
  for(int i = 0; i < refs_n; i ++){
    int d;
    fscanf(fp, "%d", &d);
    int fnd = 0;
    int id = -1;
    for(int j = 0; j < page_n; j ++){
      if(pages[j] == d){
        hit++;
        fnd = 1;
        id = j;
        break;
      }
    }
    if(!fnd){
      miss++;
      for(int j = 0; j < page_n; j ++){
        if(pages[j] == -1){
          id = j;
          break;
        }
      }
      if(id == -1){
        int min = 10000;
        for(int j = 0; j < page_n; j ++){
          if(v[j] < min){
            min = v[j];
            id = j;
          }
        }
      }
      pages[id] = d;
    }
    for(int j = 0; j < page_n; j ++){
      v[j] = v[j] >> 1;
    }
    v[id]=v[id] | (1 << 32);
  }
  // int d;
  // fscanf(fp, "%d", &d);
  // fscanf(fp, "%d", &d);
  // fscanf(fp, "%d", &d);
  // fscanf(fp, "%d", &d);
  // printf("%d\n", d);
  printf("hits %d\n", hit);
  printf("miss %d\n", miss);
  fclose(fp);
}
