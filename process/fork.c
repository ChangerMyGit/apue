#include "apue.h"
int globvar = 6;
char buf[] = "a write to stdout\n";

int main(){
   pid_t pid;
   int var = 88;
   if(write(STDIN_FILENO , buf , strlen(buf)) != strlen(buf))
      err_sys("can not write stdout!");
   printf("before fork\n");
   //fflush(stdout);
   if((pid = fork()) < 0)
      err_sys("fork error!");
   else if(pid == 0){
      globvar++;
      var++;
   } else {
      sleep(2);
   }
   printf("pid = %ld , globval = %d , var = %d \n",(long)getpid(),globvar,var);
   exit(0);
}
