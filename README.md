# PC_Mobile_Controller
Control your PC by your mobile phone using C++ Tcp/ip Socket
![image](https://github.com/user-attachments/assets/f5434967-b607-417b-990b-e10c6c11726e)
![image](https://github.com/user-attachments/assets/e77d733b-6232-48ce-89c1-e79946037f88)
![image](https://github.com/user-attachments/assets/6d32e651-b5d4-4524-8c12-8b881d5738ad)



# Network Control Server

This project implements a simple TCP server in C++ that allows a client (such as a mobile app) to send commands to control applications on a PC over a network.

## Features

- Accepts connections from clients over a TCP network.
- Listens for specific commands to open applications:
  - `Gedit` or `Edit` - Opens Gedit text editor.
  - `Firefox` or `Browser` - Opens the Firefox web browser.
  - `Code` or `VSC` - Opens Visual Studio Code.
- The server can be stopped by sending the command `exit`.
- You can add whatever you like (Commands, Applications or Even Tasks). 

## Requirements

- A C++ compiler (e.g., g++, clang++).
- A Linux-based operating system (for application commands).
- Necessary libraries for socket programming (typically included in most C++ installations).

## Setup

1. **Clone the repository**:
   ```bash
   git clone <repository-url>
   cd <repository-directory>

In Linux, the & symbol is used to run a command in the background. Here’s why you might use it:

Reasons to Use &
Non-blocking Execution: 
     When you append & to a command, it allows that command to run in the background while you continue using the terminal. This means you can execute other commands without waiting for the previous one to finish.
Multiple Processes: You can start multiple processes simultaneously. For example, if you want to open several applications or run multiple scripts at once, using & lets you do that without having to open multiple terminal windows.

## Compile the server:
2. **Compile the server**:
   ```bash
      g++ -o server main.cpp TcpServer.cpp


## Run the server:
3. **Run**
   ```bash
     ./server

Replace 192.168.8.116 in the source code with your server's IP address if necessary.

## Connect from the client :
4. **Connect from the client**
Use a mobile application or another client program to connect to the server's IP address on port 5555.
Usage
Once connected, send commands like Gedit, Firefox, or Code from the client to open the respective applications on the server.
Type exit to disconnect the client and stop the server.


## Notes on Using & in Commands
In Linux, the & symbol is used to run a command in the background. Here are some reasons to use it:

Non-blocking Execution: When you append & to a command, it allows that command to run in the background while you continue using the terminal. This means you can execute other commands without waiting for the previous one to finish.
Multiple Processes: You can start multiple processes simultaneously. For example, if you want to open several applications or run multiple scripts at once, using & lets you do that without having to open multiple terminal windows.
Troubleshooting
If the server cannot bind to the port, ensure no other service is using it.
Make sure the client is on the same network as the server.
