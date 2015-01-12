#include "apue.h"

unsigned int sleep2(unsigned int);
static void sig_int(int);

int main(){
    unsigned int unslept;
    if(signal(SIGINT , sig_int) == SIG_ERR)
	err_sys("sigint error");
    unslept = sleep2(5);
    printf("sleep2 return %u \n" , unslept);
    exit(0);
}

static void sig_int(int signo){
   int i , j;
   volatile int k;
   printf("sig_int start \n");
   for(i = 0 ; i < 300000 ; i++)
     for(j = 0;j < 4000 ; j++)
	     k += i * j;
   printf("sig_int end \n");
}
