#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>



int main(){
    if (chdir("/")!= 0)
    {perror("error:-");
    };
    int code = mkdir("sandboxes", 0777);
    if (code == 0) {
        printf("Directory created successfully.\n");
    } else {
        perror("Failed to create directory\n");
    }
    //moving to new dir "sandbox" now

    int code1=chdir("sandboxes/");
    if (code1 == 1){
        perror("error moving to dir:-\n");
    };


    int code2=mkdir("sandbox1",0777);
    if (code2==0){
        printf("sandbox1 created.\n");
    }else{
        perror("problems creating sandbox1\n");
    }
    return 0;

}