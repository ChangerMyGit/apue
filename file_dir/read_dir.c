#include "apue.h"
#include <dirent.h>

int main(int argc , char * argv[]){
    DIR * dp;
    struct dirent * dirp;
    if(argc != 2)
      err_sys("No params");
    if((dp = opendir(argv[1])) == NULL)
      err_sys(" No this dir");
    while((dirp = readdir(dp)) != NULL)
      printf(" %s ",dirp->d_name);
    exit(0);
}
