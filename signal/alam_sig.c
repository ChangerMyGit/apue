#include "apue.h"
#include <pwd.h>

static void my_alarm(int );

int main(){
    struct passwd * ptr;
    signal(SIGALRM , my_alarm);
    alarm(1);
    for(;;){
        if((ptr = getpwnam("root")) == NULL)
	   err_sys("getpwnam(root error\n)");
	if(strcmp(ptr->pw_name , "7890393") != 0)
	   printf("return value corrented ! pw_name = %s\n", ptr->pw_name);
    }
}

static void my_alarm(int signo ){
    struct passwd * rootptr;
    printf("in signal hander \n");
    if((rootptr = getpwnam("root")) == NULL)
	   err_sys("getpwnam(root) error \n");
    alarm(1);
}

