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
servaddr.sin_port = htons(8080); 

ser = socket(AF_INET, SOCK_STREAM, 0);//socket
if (ser == -1){
    printf("socket failed\n");
    exit(0);
}
else
    printf("socket created\n");
co = connect(ser,(struct sockaddr*)&servaddr,sizeof(servaddr));//bind
if (co != 0){
    printf("connect failed\n");
    exit(0);
}
else
    printf("connect success\n");
while(1){
char buff[90]; 
int n;
bzero(buff, 90);
printf("Message to client-");
while ((buff[n++] = getchar()) != '\n');//cpy ser to buf
write(ser, buff, sizeof(buff));//write
printf("Message to server-%s",buff);
bzero(buff, 90);//flush
read(ser, buff, sizeof(buff));//read
printf("server messaged as- %s", buff); 
bzero(buff, 90);//flush
n = 0;
}
close(ser);//close
}
