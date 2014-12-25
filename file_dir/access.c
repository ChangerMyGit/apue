#include "apue.h"
#include <fcntl.h>

int main(int argc , char * argv[]){
   if(argc != 2)
      err_quit("usage : a.out");
   if(access(argv[1] , R_OK) < 0)
      err_ret("access error for %s ", argv[1]);
   else
     printf("read access %s " , argv[1]);
   exit(0);
}

