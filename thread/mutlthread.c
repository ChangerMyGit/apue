#include "apue.h"
#include <pthread.h>

pthread_mutex_t lock  = PTHREAD_MUTEX_INITIALIZER;

struct foo {
   int f_count;
   pthread_mutex_t f_lock;
};

struct foo * foo_alloc(){
   struct foo * fp;
   if((fp = malloc(sizeof(struct foo))) !=NULL ){
      fp->f_count = 1;
      if(pthread_mutex_init(&fp->f_lock , NULL) != 0){
          free(fp);
	  return NULL;
      }
   }
   return fp;
}


void  foo_hold(struct foo * fp){
    pthread_mutex_lock(&fp->f_lock);
    fp->f_count++;
    pthread_mutex_unlock(&fp->f_lock);
}


void * thr_fn(void * arg){
    pthread_mutex_lock(&lock);
    int i;
    for(i = 0 ; i < 20; i++)
       printf("tid = %lu , i = %d \n" , (unsigned long)pthread_self() , i);
    pthread_mutex_unlock(&lock);
}

int main(){
    pthread_t tid1 , tid2;
    int err;
    struct foo * fp = foo_alloc();
    err = pthread_create(&tid1 , NULL , thr_fn , NULL);
    if(err !=0)
       err_exit(err , "can not create thread 1");
    err = pthread_create(&tid2 , NULL , thr_fn , NULL);
    if(err !=0)
       err_exit(err , "can not create thread 2");
    sleep(5);
    exit(5);
}





















