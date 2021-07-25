#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <sys/socket.h>//socket
#include <unistd.h>//close
#include <netinet/in.h>//addr
#include <arpa/inet.h>
int main()
{
struct sockaddr_in servaddr, cliaddr;
int ser,b,l,cli,c,len=0;
servaddr.sin_family = AF_INET; 
servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
servaddr.sin_port = htons(8080); 

ser = socket(AF_INET, SOCK_DGRAM, 0);//socket
if (ser == -1){
    printf("socket failed\n");
    exit(0);
}
else
    printf("socket created\n");
b = bind(ser,(struct sockaddr*)&servaddr,sizeof(servaddr));//bind
if (b != 0){
    printf("bind failed\n");
    exit(0);
}
else
    printf("bind success\n");
while(1)
    {
        char buff[512]; 
        len=sizeof(cliaddr);
        if (recvfrom(ser, buff, 512, 0, (struct sockaddr*)&cliaddr, &len)==-1)
            printf("recvfrom()");
        printf("Client messaged as: %s\n\n", buff);
    }

close(ser);//close ser,(struct sockaddr*)&servaddr,sizeof(servaddr
}
