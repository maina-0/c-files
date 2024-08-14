#include <stdio.h>
#include <string.h>
#include <stdlib.h>



static char name[20];


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
    {   char *text;
        system("clear");
        printf("file opened sucesfully \n \
        please type and when done press enter,\n \
        incase you want to jump to a new line,\n \
        you will have to use an \\ n \
        without the space in between:- \n");
        text = fgets(text,10000,stdin);
        setbuf(fli,NULL);
        fprintf(fli,text);
        if (fclose==0)
        printf("err closing file;%c \n");
        return 0;
    }


}

int dyww(){

     char *o;
    printf("Do you want to add anything to your file:-\n y -yes \n n -no \nAns:");
    o = fgets(o,2,stdin);
    char *y="y";
    if (strcmp( o,y) == 0){
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
    // dyww();
   // write();

    return 0;
   
    }