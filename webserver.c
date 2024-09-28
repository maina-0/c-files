#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <unistd.h>



int main(){

    int socketfd=socket(AF_INET,SOCK_STREAM,0);

    if (socketfd<0){
        perror("error creating socket");
    }
    printf("socket created sucessfully....\n");

    struct sockaddr_in myaddr;
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(20001);
    myaddr.sin_addr.s_addr=htons(INADDR_ANY);
    if (bind(socketfd,(struct sockaddr *)&myaddr,sizeof(myaddr))<0){
        perror("bind failed:");
        return 1;
    }

    printf("bind was sucessfull...\n");


    if((listen(socketfd,10))<0){
        perror("error trying to listen on port:");
    }
    struct sockaddr_in clientaddr;
    int addrsize = sizeof(clientaddr);
    int *pointer=&addrsize;
    //clientaddr.sin_family=AF_INET;
    
    int clientFD=accept(socketfd,(struct sockaddr *)&clientaddr,&addrsize);//alternatively in the last argument give pointer
    
    char buffer[1024];
    
    while(true){ 

    ssize_t amntrecv=recv(clientFD,buffer,1024,0);


    if (amntrecv>0){
            buffer[amntrecv]=0;
            printf("-------------\n");
            printf("%s \n",buffer);
            printf("-------------\n");
        
        }

        if (amntrecv==0){
            break;
        }

    }   

    close(clientFD);
    shutdown(socketfd,SHUT_RDWR);

    return 0;
}
