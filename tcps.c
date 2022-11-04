#include <stdio.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#define PORT 9999 

int main(void){
 int sock, client_sock;
 struct sockaddr_in addr, client_addr;
 char buffer[1024];
 int len, addr_len, recv_len;

 if((sock = socket(AF_INET, SOCK_STREAM, 0))<0){
   perror("socket ");
   return 1;
 } 

 memset(&addr, 0x00, sizeof(addr));
 addr.sin_family = AF_INET;
 addr.sin_addr.s_addr = htonl(INADDR_ANY);
 addr.sin_port = htons(PORT);
 if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0){
   perror("bind ");
   return 1;
 }
 if(listen(sock, 5) < 0){
   perror("listen ");
   return 1;
 }
 addr_len = sizeof(client_addr);
 printf("waiting for clinet..\n");
 while((client_sock = accept(sock, (struct sockaddr *)&client_addr, &addr_len)) > 0){
   printf("clinet ip : %s\n", inet_ntoa(client_addr.sin_addr));
   if((recv_len = recv(client_sock, buffer, 1024, 0)) < 0){ 
     perror("recv "); 
     return 1;
     break;
   }
   buffer[recv_len] = '\0';
   printf("receveid: Hello %s\n", buffer);
   buffer[0]='H';
   buffer[1]='E';
   buffer[2]='L';
   buffer[3]='L';
   buffer[4]='O';

   buffer[5]='1';
   buffer[6]='7';
   buffer[7]='8';
 buffer[8]='9';
 buffer[9]='0';
 buffer[10]='2';
   buffer[11]='4';
    buffer[12]='s';
 buffer[13]='i';
 buffer[14]='m';
 buffer[15]='h';
 buffer[16]='y';
 buffer[17]='u';
 buffer[18]='n';
  buffer[19]='s';
 buffer[20]='o';
 buffer[21]='o';


   send(client_sock, buffer, strlen(buffer), 0);

   close(client_sock);
 }
 close(sock);
 return 0; 
}


