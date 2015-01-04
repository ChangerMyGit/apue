#include "apue.h"

void my_exit1();
void my_exit2();

int main(){
   if(atexit(my_exit1) !=0 )
      err_sys("can not regeistor my exit1");
   if(atexit(my_exit1) !=0 )
      err_sys("can not regeistor my exit1");
   if(atexit(my_exit2) !=0 )
      err_sys("can not regeistor my exit2");
   printf("main do \n");
   exit(1);
}

void my_exit1(){
   printf("do my exit1! \n");
}

void my_exit2(){
   printf("do my exit2! \n");
}
