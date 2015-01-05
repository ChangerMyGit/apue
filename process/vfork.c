#include "apue.h"
int globalvar = 6;

int main(){
   pid_t pid;
   int var = 88;
   printf("before vfork \n");
   if((pid = vfork()) < 0)
      err_sys("vfork error!");
   else if(pid == 0){
      globalvar++;
      var++;
      //exit(0);
      _exit(0);
   }
   printf("pid = %ld , globvar = %d , var = %d\n",(long)getpid() , globalvar , var);
}
