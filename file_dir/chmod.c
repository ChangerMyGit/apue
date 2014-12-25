#include "apue.h"

int main(int argc , char * argv[]){
    if(chmod("bar", S_IRUSR | S_IROTH) < 0)
	err_sys("chmod error");
    exit(0);
}
