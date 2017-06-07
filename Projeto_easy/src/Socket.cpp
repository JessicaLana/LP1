#include "../include/Socket.h"
SocketCliente::SocketCliente(std::string ip, unsigned long port){
    //Inicializando campos da variavel serverAddr, que será em seguida utilizada na função connect. Essa variavel é do tipo sockaddr_in definidio na biblioteca socket.h
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_aton(ip.c_str(), &serverAddr.sin_addr);
    //Criando socket e atribuindo seu ID - valor inteiro - à variavel fides.
    fides = socket(AF_INET, SOCK_STREAM, 0);
}
void SocketCliente::connectToServer(){
    //Estabelece conexão e trata de seu sucesso ou falha
    if(connect(fides, (const sockaddr*)&serverAddr, sizeof(serverAddr)) == 0){
        std::cout << "Connected!" << std::endl;
    }
    else 
        throw std::runtime_error("Failed connecting to server");
}
void SocketCliente::sendData(const char* data_, int size){
    //Copia dados para o buffer
    memcpy(buffer, data_, size);
    //Escreve os dados do buffer no socket
    write(fides, buffer, size);
    //Limpa o buffer
    memset(buffer, '\0', sizeof(buffer));
}
int SocketCliente::getFides(){
    return fides;
}
SocketCliente::~SocketCliente(){
    //Finaliza conexão
    close(fides);
}
