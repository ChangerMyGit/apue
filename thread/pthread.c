#include "apue.h"
#include <pthread.h>

pthread_t ntid;

void printids(const char * s){
   pid_t pid;
   pthread_t tid;
   pid = getpid();
   tid = pthread_self();
   printf("%s pid %lu tid %lu (0x%lx) \n", s , (unsigned long)pid , (unsigned long)tid , (unsigned long)tid);
}

void * thr_fn(void *arg){
   printids("new thread : ");
   return ((void *) 0);
}


int main(){
   int error;
   void * trt;
   error = pthread_create(&ntid ,NULL,thr_fn,NULL);
   if(error !=0)
     err_exit(error,"can not create thread!\n");
   printids("main thread : ");
   error = pthread_join(ntid , &trt);
   if(error != 0)
     err_exit(error,"can not join threed ");
   printf("child thread return is %ld \n",(long)trt);
   //sleep(1);
   exit(0);
}
