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
int ser,co,len=0;
servaddr.sin_family = AF_INET; 
servaddr.sin_addr.s_addr =inet_addr("127.0.0.1");
//servaddr.sin_addr.s_addr =inet_addr(INADDR_ANY);
servaddr.sin_port = htons(8080); 

ser = socket(AF_INET, SOCK_STREAM, 0);//socket
if (ser == -1){
    printf("socket failed\n");
    exit(0);
}
else
    printf("socket created\n");
while(1)
    {
        char buff[512]; 
        len=sizeof(servaddr);
        bzero(buff,512);
        printf("Message to server as- ");
        fgets(buff,512, stdin);
       // printf("skkdks-%s",buff);
        if (sendto(ser, buff,512, 0, (struct sockaddr*)&servaddr,len)==-1)
            printf("error while sending");
        else
            printf("mesg sent sucess");       
    }
close(ser);//close
}
