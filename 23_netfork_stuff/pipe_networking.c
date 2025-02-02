#include "pipe_networking.h"


/*==========================================================*\
  server_connect
  - Creates a bound, listening socket
  - Loops accepting client connection
  - When accepting, forks into two processes
  - One process returns socket descriptor to server function
\*==========================================================*/

int server_connect() {
  printf("Server Initiating!\n"); /**/
  
  // Preliminary
  struct addrinfo * hints, * results;
  hints = calloc(1, sizeof(struct addrinfo));
  hints->ai_family = AF_INET;
  hints->ai_socktype = SOCK_STREAM; // TCP
  hints->ai_flags = AI_PASSIVE; // only needed on server
  getaddrinfo(NULL, "9845", hints, &results);  // Server sets node to NULL
  
  // Socket
  int sd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);

  // Bind
  bind(sd, results->ai_addr, results->ai_addrlen);

  free(hints);
  freeaddrinfo(results);
  
  // Listen
  listen(sd, CLIENTNUM);
  printf("Server is running successfully!\n"); /**/
  
  int client_socket;
  socklen_t sock_size;
  struct sockaddr_storage client_address;
  sock_size = sizeof(client_address);

  // Accept
  while (1){
    client_socket = accept(sd, (struct sockaddr *) &client_address, &sock_size);
    printf("Server has received a connection!\n"); /**/

    int pid = fork();
    if (!pid)
      return client_socket;
  }
}

/*==========================================================*\
  client_connect
  - Creates a Server-searching socket
  - Connects socket to Server
  - Returns socket descriptor to client function
\*==========================================================*/
int client_connect() {
  printf("Client Initiating!\n"); /**/

  // Preliminary
  struct addrinfo * hints, * results;
  hints = calloc(1, sizeof(struct addrinfo));
  hints->ai_family = AF_INET;
  hints->ai_socktype = SOCK_STREAM; // TCP
  getaddrinfo("127.0.0.1", "9845", hints, &results);  // Client sets node to Server IP

  // Socket
  int sd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
  printf("Client is running successfully!\n"); /**/

  // Connect
  connect(sd, results->ai_addr, results->ai_addrlen);
  printf("Client has connected!\n"); /**/
  
  free(hints);
  freeaddrinfo(results);

  return sd;
}
