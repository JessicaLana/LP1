#include "../include/Socket.h"
Socket::Socket(std::string ip, unsigned long port){
    //Inicializando campos da variavel serverAddr, que será em seguida utilizada na função connect. Essa variavel é do tipo sockaddr_in definidio na biblioteca socket.h
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_aton(ip.c_str(), &serverAddr.sin_addr);
    //Criando socket e atribuindo seu ID - valor inteiro - à variavel fides.
    fides = socket(AF_INET, SOCK_STREAM, 0);
}
void Socket::connectToServer(){
    //Estabelece conexão e trata de seu sucesso ou falha
    if(connect(fides, (const sockaddr*)&serverAddr, sizeof(serverAddr)) == 0){
        std::cout << "Connected!" << std::endl;
        connected = 1;
    }
    else 
        throw std::runtime_error("Failed connecting to server");
}
void Socket::sendData(char* data_, int size){
    if(connected == 1){
        //Copia dados para o buffer
        memcpy(buffer, data_, size);
        //Escreve os dados do buffer no socket
        write(fides, buffer, size);
        //Limpa o buffer
        memset(buffer, '\0', sizeof(buffer));
    }
    else {
        //Se conexão falhar
        throw std::runtime_error("Error; trying to send data to a server you're not connected to");
    }
}

Socket::~Socket(){
    //Finaliza conexão
    close(fides);
}
