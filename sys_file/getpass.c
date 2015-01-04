#include "apue.h"
#include <pwd.h>
#include <string.h>
#include <stddef.h>

int main(){
   struct passwd * ptr;
   setpwent();
   while((ptr = getpwent()) != NULL)
      printf("%s \n",ptr->pw_name);
   endpwent();
   exit(10);
}
