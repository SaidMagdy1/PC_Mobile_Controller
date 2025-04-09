#include "TcpServer.hpp"

TcpServer::TcpServer()
:ip{"127.0.0.1"},port{5555}
{
   createSocket(server_fd);
   bindSocket(server_fd);
   listening(server_fd);
   accepting(client_sock);
   chat();

}

TcpServer::TcpServer(const char *ip, int port)
    :ip{ip},port{port}
{
    createSocket(server_fd);
    bindSocket(server_fd);
    listening(server_fd);
    accepting(client_sock);
    chat();
}

TcpServer::~TcpServer()
{
    std::cout << "Server closing..." << std::endl;
    close(client_sock);
    close(server_fd);
}

 //Socket Initialization (File descriptor)
int TcpServer::createSocket(int &fd_)
{
    fd_ = socket(AF_INET,SOCK_STREAM,0);
    if(fd_ == FAIL)
    {
        std::cerr<<"Can Not Init the Socket"<<std::endl;
        return -1;
    }
    return 0;
}

int TcpServer::bindSocket(int &fd_)
{
    hint.sin_family = AF_INET;   //IPv4
    hint.sin_addr.s_addr = inet_addr(ip);  
    hint.sin_port = htons(port); 
    //htons keeps the port big enddian  i think the opposite is ntohs()
    /* ( Big-endian is an order in which the big end -- the most significant value in the sequence -- is first, 
    at the lowest storage address. 
    Little-endian is an order in which the little end,
    the least significant value in the sequence, is first.)*/

   int binding=bind(server_fd , (struct sockaddr *)&hint ,sizeof(hint));
    //std::cout<<"binding : "<<binding<<std::endl;
    if(binding == FAIL)
    {
        std::cerr << "Binding failed" << std::endl;
        return -2;
    }
    return 0;
}

int TcpServer::listening(int &fd_)
{
   int listened=listen(server_fd , SOMAXCONN);
    //std::cout<<"listening : "<<listening<<std::endl;
    if(listened == FAIL)
    {
        std::cerr << "Listen failed" << std::endl;
        return -3;
    }
    std::cout << "Server listening on port " << port << std::endl;
    return 0;
}

int TcpServer::accepting(int &c_fd)
{
    c_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    if(client_sock == FAIL)
    {
        std::cerr << "Accept failed" << std::endl;
        return -4;
    }
    return 0;
}

void TcpServer::chat()
{
    std::string message;
    while (true) {
        // Receive message from client
        memset(buffer, 0, sizeof(buffer)); // Clear buffer
        int bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);
        //std::string(buffer,bytes_received);
        if(std::string(buffer,bytes_received) == "exit" || std::string(buffer,bytes_received) == "Exit" )
        	break;
        if (bytes_received > 0) {
            std::cout << "Message from client: " << buffer << std::endl;
        }else if (bytes_received == 0) {
            std::cout << " Client Disconnected " << std::endl;
            break;
        }

        if(std::string(buffer,bytes_received) == "Gedit" || std::string(buffer,bytes_received) == "Edit" ){
            system("gedit &");
        }
        if(std::string(buffer,bytes_received) == "Firefox" || std::string(buffer,bytes_received) == "Browser" ){
            system("firefox &");
        }
        if(std::string(buffer,bytes_received) == "Code" || std::string(buffer,bytes_received) == "VSC" ){
            system("code . &");
        }
             
/*
        // Prompt server user to enter a message to send
        std::cout << "Enter message to send to client (type 'exit' to close): ";
        std::getline(std::cin, message);

        // Exit loop if user types "exit"
        if (message == "exit") {
            break;
        }
          // Send the message to the client
       send(client_sock, message.c_str(), message.length(), 0);
       std::cout << "Server > " << message << std::endl;
*/
      
    }
}
