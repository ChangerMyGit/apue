#include "apue.h"

static void sig_usr1(int signo);

int main(){
    struct sigaction act;
    act.sa_handler = sig_usr1;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGUSR1, &act , NULL); 
    sigaction(SIGUSR2, &act , NULL); 
    for(;;)
      pause();
    exit(0);
}

static void sig_usr1(int signo){
    if(signo == SIGUSR1)
       printf("receive SIGUSR1 \n");
    else if(signo == SIGUSR2)
       printf("receive SIGUSR2 \n");
    else
       printf("receive signo %d \n" , signo);
}
