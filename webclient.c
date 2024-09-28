#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <unistd.h>


int main(){
int socketFD;
    if ((socketFD= socket (AF_INET,SOCK_STREAM,0))<0){
        perror("error creating socket:");
        return 0;
    }

    printf("sucessfully created socket fd %i, continuing\n",socketFD);


    struct sockaddr_in address;
    memset((void*)&address,0,sizeof(address)); //this struct is already defined in the sys/socket.h file
    address.sin_family=AF_INET;

    if(bind(socketFD,(struct sockaddr *)&address,sizeof(address))<0){
        perror("error binding:");

    }
    printf("binding ip to port was sucessfull, continuing \n");


    struct sockaddr_in dest;
    dest.sin_family=AF_INET;
    dest.sin_port=htons(20001);
    char *ip="41.89.68.78";
    inet_pton(AF_INET,ip,&dest.sin_addr);

    if (connect(socketFD,(struct sockaddr *)&dest,sizeof(dest)) ==0){
        printf("connection was successfull\n");
    }


    printf("your message\n");
    printf("------------\n");
    char *buff=NULL;
    size_t len=0;
    ssize_t msgcount;
    
   while (true)
    { 
        ssize_t msgcount=getline(&buff,&len,stdin);
        printf("------------\n");

        if (msgcount>0){
            
            if (strcmp(buff,"exit\n")==0){
                break;
            }
        ssize_t msgsent=send(socketFD,buff,msgcount,0);
        }

    }
        


    close(socketFD);
    

    return 0;


}

