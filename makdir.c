#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>


int main(){

char *boy=("boy");
printf("%s\n",boy);

int code1 = mkdir("roy", 0777);
if (code1!=0){
    perror("error:-");
    }


    return 0;
    }
