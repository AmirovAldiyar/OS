#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node* next;
};

struct linked_list{
  struct node* head;
  int size;
};

void print_list(struct linked_list* list){
  if(list->head == NULL){
    return;
  }
  struct node* cur;
  cur = list->head;
  while(cur != NULL){
    printf("%d ", cur->data);
    cur = cur->next;
  }
  printf("\n");
}

void insert_node(struct linked_list *list, int data){
  if(list->size == 0){
    struct node* first = malloc(sizeof first);
    first->data = data;
    first->next = NULL;
    list->head = first;
    list->size++;
    return;
  }
  struct node *cur = list->head;
  while(cur->next != NULL){
    cur = cur->next;
  }
  struct node* b =  malloc(sizeof *b);
  b->data=data;
  b->next = NULL;
  cur->next = b;
  list->size ++;
}

void delete_node(struct linked_list* list, int data){
  struct node* cur = list->head;
  while(cur->next != 0 && cur->next->data != data){
    cur = cur->next;
  }
  if(cur->next != 0){
    cur->next = cur->next->next;
  }
}

struct linked_list linked_list(){
  struct linked_list a;
  a.head = NULL;
  a.size = 0;
  return a;
}

int main(){
  printf("12  ");
  struct linked_list a = linked_list();
  insert_node(&a, 1);
  insert_node(&a, 5);
  insert_node(&a, 6);
  print_list(&a);
  delete_node(&a, 5);
  print_list(&a);
  insert_node(&a, 8);
  insert_node(&a, 11);
  insert_node(&a, 15);
  print_list(&a);
  delete_node(&a, 99);
  print_list(&a);
  delete_node(&a, 15);
  delete_node(&a, 11);
  print_list(&a);
}
