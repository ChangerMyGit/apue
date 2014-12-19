#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFSIZE 1024
#define PERMS 0666
//#undef getchar

//int getchar(void);
int main(int argc , char * argv[]){
	char buf[BUFSIZE];
	int n , f1 ,f2;
/*	while((n = read(0,buf,BUFSIZE))>0){
            write(1,buf,n);
	}
*/
/*	while( ( n = getchar()) != EOF)
  	  putchar(n);
*/
        if(argc != 3){
	    printf("Usage cp fro to \n");
	    exit(1);
	}
	  // error("Usage cp from to",agrv[1]);
	if( ( f1 = open(argv[1] , O_RDONLY , 0)) == -1){
	    printf("cp : can not open %s \n", argv[1]);
	    exit(2);
	}
	if(( f2 = creat(argv[2] , PERMS)) == -1){
	    printf("cp : can not create %s \n " ,argv[1]);
	    exit(3);
	}
	//printf(" f1 = %d , f2 = %d  argv1 = %s , argv2 = %s \n ", f1 , f2,argv[1],argv[2]);

	while((n = read(f1,buf,BUFSIZE))>0){
	    write(f2,buf,n);
	}

	return 0;
}

/*int getchar(){
   char c;
   return (read(0,&c,1) == 1) ? c : EOF;
}*/
