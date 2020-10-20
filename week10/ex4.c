#include <stdio.h>
#include <unistd.h>

struct map
{
  int key;
  int value;
};

int main()
{
  struct map cnt[11111];
  int size = 0;
  FILE *fp = popen("ls -i *", "r");
  char path[4096];
  while (fgets(path, 4096, fp) != NULL)
  {
    int inode = 0;
    for (int i = 0; i < 4096; i++)
    {
      if (path[i] == ' ')
      {
        break;
      }
      inode *= 10;
      inode += (path[i]) - 48;
    }
    int flag = 0;
    for (int j = 0; j < size; j++)
    {
      if (cnt[j].key == inode)
      {
        cnt[j].value++;
        flag = 1;
        break;
      }
    }
    if (!flag)
    {
      cnt[size].value = 1;
      cnt[size].key = inode;
      size++;
    }
  }
  for (int j = 0; j < size; j++)
  {
    if (cnt[j].value >= 2)
    {
      printf("inode - %d: \n", cnt[j].key);
      pclose(fp);
      fp = popen("ls -i *", "r");
      while (fgets(path, 4096, fp) != NULL)
      {
        int inode = 0;
        for (int i = 0; i < 4096; i++)
        {
          if (path[i] == ' ')
          {
            break;
          }
          inode *= 10;
          inode += (path[i]) - 48;
        }
        if (inode == cnt[j].key)
          printf("%s", path);
      }
      printf("\n\n");
    }
  }
}
