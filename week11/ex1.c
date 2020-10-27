#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
  int file = open("ex1.txt", O_RDWR);
  struct stat statbuf;
  fstat(file, &statbuf);
  char *ptr = mmap(NULL, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
  close(file);
  memset(ptr, 0, sizeof(ptr));
  strcpy(ptr, "This is a nice day");
}