#include "apue.h"
int main(int argc , char * argv[]){
   char buf[1024];
   ssize_t c;
   if(argc != 2)
     err_quit("no params ");
   if((c = readlink(argv[1], buf , 1024)) > 0)
     write(STDOUT_FILENO, buf ,c);
   exit(0);
}
