#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc , char * argv[]){
/*    int c;
    if(argc == 1) {
       printf("no params!\n");
       return 1;
    }
    FILE * fp = fopen(argv[1],"r");
    if(fp == NULL) {
       printf("can not open %s \n",argv[1]);
       return 1;
    }
    while((c = getc(fp))!=EOF)
        putc(c,stdout);
  */
	int f;
	f = creat("./haha",0666);
      	printf("FD= %d" , f);
	return 0;
}
