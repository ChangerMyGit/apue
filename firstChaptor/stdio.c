#include "apue.h"

int main(){
   int c;
   while( (c = getc(stdin)) != EOF)
        if(putc(c,stdout) == EOF)
		err_sys("output_error");
   if(ferror(stdin))
	   err_sys("intput_error");
   exit(0);
}

