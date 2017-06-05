#ifndef MY_SOCKET_CLASS
#define MY_SOCKET_CLASS 
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "string.h"
#include "unistd.h"
#include <stdexcept>
#include <iostream>
#include <string>
#define BUFFERSIZE 124
/*! This class is a simple c++ wrapper on linux C sockets, it uses AF_INET as protocol and can have it's buffer size set through the BUFFERSIZE macro*/
class Socket{
    public:
    int domain = AF_INET;   /*!< Socket domain, please refer to the linux manuals for more info on other possible socket domains */
    int type = SOCK_STREAM; /*!< Socket type - TCP packet stream -, please refer to the linux manuals for more info on other possible socket types */
    int protocol = 0; /*!< Set to 0 if not using alternative protocol for the given socket type */
    sockaddr_in serverAddr; /*!< Structure holding the target server address */
    int fides; /*!< Socket file descriptor writes are made into */
    char buffer[BUFFERSIZE]; /*!< Data buffer, feel free to especify yours through the BUFFERSIZE macro */
    int connected = 0;
    public:
    Socket(std::string ip,unsigned long port); /*!< Initializes ip server address and port. Does NOT establish connection*/
    void connectToServer(); /*!< Establishes connection to server */
    void sendData(char* data_, int size); /*!< Sends arbritrary data - use the sizeof operator*/
    Socket(){}; /*!< Default constructor */
    ~Socket(); /*!< Closes connection */
};
#endif