#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>



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
        printf("file opened sucesfully \n \
        please type and when done press enter,\n \
        incase you want to jump to a new line,\n \
        you will have to use an \\ n \n\
        without the space in between:- \n");
        char text[1000];
         
        setbuf(fli,NULL);
        printf("enter text: \n");
        if (fgets(text,sizeof(text),stdin)!=NULL){
            fprintf(fli,"%s",text);
            return 0;
            
        }
        else{
            fclose(fli);
            perror("err opening file; \n");
            return 1;
        }
        }else{
            return 1;
        }

        if(!fclose(fli)){
        perror("err closing file: \n");
        return 1;
    }
        return 0;
    }




int dyww(){


    char *yes ="y";
    char *o;
    printf("Do you want to add anything to your file:-\n y -yes \n n -no \nAns:");
    o = fgets(o,2,stdin);
    if (strcmp(o,yes) == 0){
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
