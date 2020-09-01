#include <stdio.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int arr[], int size){
  for(int i = 0; i < size; i ++){
    for(int j = i + 1; j < size; j ++){
      if(arr[i] > arr[j]){
        swap(&arr[i], &arr[j]);
      }
    }
  }
}

int main(){
  int n;
  printf("Input the array size:\n");
  scanf("%d", &n);
  const int N = n;
  int arr[N];
  printf("Intput an array:\n");
  for(int i = 0; i < n; i ++){
    scanf("%d", &arr[i]);
  }
  printf("\nSorted array: \n");
  bubble_sort(arr, n);
  for(int i = 0; i < n; i ++){
    printf("%d ", arr[i]);
  }
}
