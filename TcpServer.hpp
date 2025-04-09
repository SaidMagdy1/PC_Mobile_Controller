#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cstring>    // For memset
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> // For sockaddr_in
#include <unistd.h>    // For close()
#include <arpa/inet.h> // For inet_addr("127.0.0.1");  
//states
#define FAIL -1

class TcpServer{
    
    int server_fd ,client_sock;
    const char *ip;
    int port;

    struct sockaddr_in hint;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
   
    public:
    TcpServer();
    TcpServer(const char * ip,int port);
    ~TcpServer();
    int createSocket(int &fd_);
    int bindSocket(int &fd_);
    int listening(int &fd_);
    int accepting(int &c_fd);
    void chat();
   
};
