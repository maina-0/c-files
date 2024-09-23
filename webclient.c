#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>


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
}
