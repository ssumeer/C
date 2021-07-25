#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <sys/socket.h>//socket
#include <unistd.h>//close
#include <netinet/in.h>//addr
int main()
{
struct sockaddr_in servaddr, cliaddr;
int ser,b,l,cli,c,len=0;
servaddr.sin_family = AF_INET; 
servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
servaddr.sin_port = htons(8080); 

ser = socket(AF_INET, SOCK_STREAM, 0);//socket
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
l = listen(ser, 5);//listen
if (l != 0){
    printf("listen failed\n");
    exit(0);
}
else
    printf("listen success \n");
len=sizeof(struct sockaddr_in);
cli = accept(ser,(struct sockaddr*)&cliaddr,&len);//accept
if (cli < 0){
    printf("accept failed\n");
    exit(0);
}
else
    printf("accept success\n");
while(1){
char buff[90]; 
int n;
bzero(buff, 90);
read(cli, buff, sizeof(buff));//read
printf("client messaged as- %s", buff); 
printf("Message to client-");
bzero(buff, 90);//flush
n = 0; 
while ((buff[n++] = getchar()) != '\n');//cpy ser to buf
write(cli, buff, sizeof(buff));//write
}
close(ser);//close
}
