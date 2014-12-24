#include "apue.h"
#include <fcntl.h>
#include <unistd.h>

void set_fl(int fd,int flags);

int main(){
    char buf[1024];
    int n = 0, fd , i = 1;
    if((fd = open("./inittab",O_RDWR)) < 0)
       err_sys("open error");
    n = pread(fd,buf,10,10);
    write(STDOUT_FILENO,buf,n);
    while((n = pread(fd,buf,10,i++ * n)) > 0){ 
       write(STDOUT_FILENO,buf,n);
    }
/*
    while((n = read(fd,buf,1024)) > 0)
      if(write(STDOUT_FILENO,buf,n) != n )
	 err_sys("write error"); 
*/
     exit(0);
}

void set_fl(int fd,int flags){
    int val ;
    if((val = fcntl(fd,F_GETFL,0)) < 0)
       err_sys("fcntl F_GETFL error");
    val |= flags;
    if(fcntl(fd,F_SETFL,val) < 0)
       err_sys("fcntl F_SETFL error");
}
