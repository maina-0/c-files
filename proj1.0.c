#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>



static char name[20];
int nm();
int file();
int write();
int dyww();


int nm(){
    printf("Please enter your file name:-");
    fgets(name,20,stdin);  
    return 0;

}
int file(){

    FILE *fl;

    fl=fopen(name,"w");
    printf("empty file created called %s has been created.\n",name);
    fclose(fl);
    if (fclose==0)
    printf("err closing file;%c \n");
    return 0;

}

FILE *fli;

int write(){

    fli=fopen(name,"a+");

    if(fli != NULL)
    {   
        system("clear");
        printf("file opened sucessfully please enter text\n");
        printf("-----------------------------------------\n");
        while(true){
            char *text=NULL;
            size_t len=0;
            ssize_t bytes=getline(&text,&len,stdin);
            if (bytes>1){
            if(strcmp(text,"exit\n")==0){
                break;
            }
            printf("%i bytes entered\n",(bytes-1));
            fprintf(fli,"%s\n",text);
        }
        }
    }
        free(fli);
        if(!fclose(fli)){
        perror("err closing file: \n");
        return 1;
    }
        return 0;
}




int dyww(){


    char *o;
    printf("Do you want to add anything to your file:-\ny -yes \nn -no \nAns:");
    o= fgets(o,2,stdin);
    if (strcmp(o,"y") == 0){
        write();
    }
    else{
        printf("Okay, Thank you \n");
}
}

int main()
{
    nm();
    file();
    dyww();
    

    return 0;
   
    }
