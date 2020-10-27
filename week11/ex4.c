#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
  int file = open("ex1.txt", O_RDWR);
  struct stat statbuf;
  struct stat statbuf1;
  fstat(file, &statbuf);
  char *ptr = mmap(NULL, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
  close(file);

  int des = open("ex1.memcpy.txt", O_RDWR);
  ftruncate(des, strlen(ptr) + 1);
  fstat(des, &statbuf1);
  char *ptr1 = mmap(NULL, statbuf1.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, des, 0);
  close(des);

  memcpy(ptr1, ptr, strlen(ptr) + 1);
}