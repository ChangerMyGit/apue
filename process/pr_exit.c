//#include "apue.h"
#include <stdio.h>
#include <sys/wait.h>

void pr_exit(int status){
   if(WIFEXITED(status))
	  printf("normal termination , exit status = %d \n" , WEXITSTATUS(status));
   else if(WIFSIGNALED(status))
	  printf("abonormal termination ,signal number = %d\n",WTERMSIG(status));
   else if(WIFSTOPPED(status))
	  printf("child stopped ,signal number = %d \n",WSTOPSIG(status));
}
