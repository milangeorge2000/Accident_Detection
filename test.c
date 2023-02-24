#include<sys/types.h>
#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
int clientsocket,serversocket;
struct sockaddr_in serveraddr,clientaddr; 
socklen_t len;
char message[50],writemsg[20]=�hello client�;
serversocket=socket(AF_INET,SOCK_STREAM,0);
bzero((char *)&serveraddr,sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(5030);
serveraddr.sin_addr.s_addr = INADDR_ANY;
bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(clientaddr));
len=sizeof(clientaddr);
listen(serversocket,5);
printf(�\n[s]:WAITING FOR CLENT CONNECTIVITY.....\n�);
clientsocket=accept(serversocket,(struct sockaddr *)&clientaddr,&len);
printf(�\n[s]:CLIENT CONNECTED......\n�);
printf(�\n[s]:READING MESSAGE FROM CLIENT \n�);
read(clientsocket,message,sizeof(message));
printf(�\n[s]:SENDING MESSAGE TO CLIENT \n�);
write(clientsocket,writemsg,sizeof(writemsg));
printf(�\n[s]:MESSAGE SENT\n�);
close(clientsocket);
close(serversocket);
}
