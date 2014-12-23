#include "apue.h"
#include <fcntl.h>

int main(){
    char buf[1024];
    int fd , n;
    if((fd = open("./inittab",O_RDONLY)) < 0)
      err_sys("open error");
    //printf("fd : %d \n" , fd);
    if(lseek(fd,100,SEEK_SET) == -1)
      err_sys("lseek error");
    while((n = read(fd,buf,1024)) > 0){
      //printf("n : %d \n",n);
       if(write(STDOUT_FILENO,buf,n) != n)
	 err_sys("write error");
    }
    exit(0);
}
