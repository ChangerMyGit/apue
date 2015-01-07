#include "apue.h"

int main(){
   pid_t pid = getpid();
   pid_t sid = getsid(0);
   printf("pid = %ld ,pgid = %ld, sid = %ld \n" , pid , getpgid(pid), sid);
   exit(0);
}
