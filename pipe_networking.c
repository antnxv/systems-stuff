#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client
  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.
  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
  // 0: S makes WKP, awaits WKP connection
  mkfifo(WKP, 0644);
  int from_client = open(WKP, O_RDONLY, 0644);
  char s2c[HANDSHAKE_BUFFER_SIZE];
  read(from_client, s2c, HANDSHAKE_BUFFER_SIZE);

  // 4: S gets C msg, removes WKP
  printf("0. S Got: [%s]\n---\n", s2c); /**/
  remove(WKP);

  // 5: S sends C respo
  *to_client = open(s2c, O_WRONLY, 0644);
  printf("1. S Sent: [%s]\n---\n", ACK); /**/
  write(*to_client, ACK, HANDSHAKE_BUFFER_SIZE);

  // 8: S gets C ack
  char ack[HANDSHAKE_BUFFER_SIZE];
  read(from_client, ack, HANDSHAKE_BUFFER_SIZE);
  printf("2. S Got: [%s]\n---\n", ack); /**/
  if (!strcmp(ack, "IOLA"))
    return from_client;
  else
    return -1;
}


/*=========================
  client_handshake
  args: int * to_server
  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.
  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  // 1: C makes SP
  char s2c[HANDSHAKE_BUFFER_SIZE];
  sprintf(s2c, "%d", getpid());
  mkfifo(s2c, 0644);

  // 2: C sends S SP name through WKP
  *to_server = open(WKP, O_WRONLY, 0644);
  printf("0. C Sent: [%s]\n---\n", s2c); /**/
  write(*to_server, s2c, HANDSHAKE_BUFFER_SIZE);

  // 3: C awaits S msg, SP connection
  char synack[HANDSHAKE_BUFFER_SIZE];
  int from_server = open(s2c, O_RDONLY, 0644);
  read(from_server, synack, HANDSHAKE_BUFFER_SIZE);

  // 6: C gets S msg, removes SP
  printf("1. C Got: [%s]\n---\n", synack); /**/
  remove(s2c);

  // 7: C sends S ack
  synack[0] ++;
  printf("2. C Sent: [%s]\n---\n", synack); /**/
  write(*to_server, synack, HANDSHAKE_BUFFER_SIZE);
  
  return from_server;
}
