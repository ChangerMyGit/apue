#include "apue.h"

int main(int agrc , char * argv[]){
   if(link("/root/c_project/file_dir/file1.ln","/root/c_project/file_dir/filehard") < 0)
      err_sys("link error");
   exit(0);
}
