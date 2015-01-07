#include "apue.h"

void sig_usr(int signo);

int main(){
   if(signal(SIGUSR1 , sig_usr) == SIG_ERR)
     err_sys("can not catch SIGUSR1");
   if(signal(SIGUSR2 , sig_usr) == SIG_ERR)
     err_sys("can not catch SIGUSR2");
   while(1)
     pause();
}
void sig_usr(int signo){
   //signal(signo , sig_usr);
   if(signo == SIGUSR1)
	printf("receive SIGUSR1 !\n");   
   else if(signo == SIGUSR2)
	printf("receive SIGUSR2 !\n");   
   else
	err_dump("receive signal %d\n",signo);
}
