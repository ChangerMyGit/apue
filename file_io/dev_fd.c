#include "apue.h"
#include <fcntl.h>

int main(){
   char buf[] = "write for dev";
   int fd = open("/dev/fd/1",O_RDWR);
   if(fd > 0)
     write(fd,buf,strlen(buf));
   exit(0);
}
