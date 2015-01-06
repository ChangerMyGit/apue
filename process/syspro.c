#include "apue.h"

static void chartime(char * str);

int main(){ 
   pid_t pid;
   //TELL_WAIT();
  
   if((pid = fork()) < 0)
     err_sys("fork error \n");
   else if(pid == 0){
     //WAIT_PARENT();
     chartime("out child process \n");
   } else {
     chartime("out parent process \n");
     wait();
     //TELL_CHILD(pid);
   }   
   exit(0);
}

static void chartime(char * str){
    char *ptr;
    int c;
    setbuf(stdout , NULL);
    for(ptr = str; (c = *ptr++) != 0;){
       putc(c,stdout);
    }
}
