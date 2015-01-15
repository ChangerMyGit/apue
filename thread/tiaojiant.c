#include "apue.h"
#include <pthread.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t conda = PTHREAD_COND_INITIALIZER;
pthread_cond_t condb = PTHREAD_COND_INITIALIZER;
pthread_cond_t condc = PTHREAD_COND_INITIALIZER;

char * msg = "A";

void * printA(void * arg){
    int i;
    for(i = 0 ; i < 10 ; i++){
        pthread_mutex_lock(&mut);
        while(strcmp(msg , "A") != 0){
	   pthread_cond_wait(&conda,&mut);
	}
	printf("%s",msg);
	msg = "B";
	pthread_cond_signal(&condb);
	pthread_mutex_unlock(&mut);
	sleep(1);
    }
}

void * printB(void * arg){
    int i;
    for(i = 0 ; i < 10 ; i++){
        pthread_mutex_lock(&mut);
        while(strcmp(msg , "B") != 0){
	   pthread_cond_wait(&condb,&mut);
	}
	printf("%s",msg);
	msg = "C";
	pthread_cond_signal(&condc);
	pthread_mutex_unlock(&mut);
	sleep(1);
    }
}


void * printC(void * arg){
    int i;
    for(i = 0 ; i < 10 ; i++){
        pthread_mutex_lock(&mut);
        while(strcmp(msg , "C") != 0){
	   pthread_cond_wait(&condc,&mut);
	}
	printf("%s\n",msg);
	msg = "A";
	pthread_cond_signal(&conda);
	pthread_mutex_unlock(&mut);
	sleep(1);
    }
}

int main(){
    int i;
    pthread_t threads[3];
    pthread_create(&threads[0] , NULL, printA,NULL);
    pthread_create(&threads[1] , NULL, printB,NULL);
    pthread_create(&threads[2] , NULL, printC,NULL);
    for(i = 0; i< 3;i++){
       pthread_join(threads[i] , NULL);
    }

    exit(0);
}


