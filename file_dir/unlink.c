#include "apue.h"

int main(int argc , char * argv[]){
    if(argc != 2)
      err_sys("no params ");
    if(unlink(argv[1]) < 0)
      err_sys("unlink error");
    exit(0);
}
