#include "apue.h"


int main(){
   extern char ** environ;
   while(*environ)
     printf("%s \n" , *environ++);
   exit(10);
}
