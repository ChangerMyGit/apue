#include "apue.h"

int main(int argc , char * argv[]){
   FILE * fl;
   char * buf[MAXLINE];
   if(argc !=2 )
     err_sys("no args");
   if((fl = fopen(argv[1] , "r")) == NULL)
     err_sys("open error");
   while(fgets(buf,MAXLINE,fl) != NULL)
     if(fputs(buf,stdout) == EOF)
       err_sys("fputs error");
   exit(0);
}
