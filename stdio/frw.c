#include "apue.h"

int main(){
   char buf[1024];
   int fd;
   FILE * file = fopen("./stdio","rb");;
   FILE * newfile = fopen("./newstd","wb");
   fd = fileno(newfile);
   while(fread(buf , sizeof(buf) , 1 , file) == 1){
      fwrite(buf,sizeof(buf),1,newfile);
   }
   fchmod(fd,S_IWOTH | S_IXOTH);
   exit(0);
}
