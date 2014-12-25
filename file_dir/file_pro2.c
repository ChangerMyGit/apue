#include "apue.h"

int main(int argc , char * argv[]){
    int i;
    struct stat * buf = (struct stat *)malloc(sizeof(struct stat)) ;
    char * ptr;
    for(i = 1 ; i< argc ;i++){
       printf("%s  ",argv[i]);
       if(lstat(argv[i] , buf) < 0){
          err_sys("lstat error");
	  continue;
       }
       //printf("%d   ",buf.st_mode);
       if(S_ISREG(buf->st_mode))
	  ptr = "nomal file";
       else if(S_ISDIR(buf->st_mode))
          ptr = "directory";
       else if(S_ISCHR(buf->st_mode))
          ptr = "char special";
       else if(S_ISBLK(buf->st_mode))
          ptr = "black special";
       else if(S_ISFIFO(buf->st_mode))
          ptr = "fifo";
       else if(S_ISSOCK(buf->st_mode))
          ptr = "scoket";
       else if(S_ISLNK(buf->st_mode))
	  ptr = "link file";
       else 
	  ptr = "unknow file";
       printf("%s \n" , ptr);
    }
    exit(0);
}
