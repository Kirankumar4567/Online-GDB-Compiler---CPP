#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

using namespace std;


int main()
{
int fd = open("famous", O_CREAT|O_WRONLY);
   char readbuf[80];
 printf("Enter string: ");
      fgets(readbuf, sizeof(readbuf), stdin);
      int stringlen = strlen(readbuf);
      readbuf[stringlen - 1] = '\0';
      write(fd, readbuf, strlen(readbuf));

}
