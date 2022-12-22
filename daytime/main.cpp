#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

void errHandler(const char * why, const int exitCode = 1)
{
    cerr<< why << endl;
    exit(exitCode);
}
int main (int argc, char **argv)
{
    //подготовить структуру с адресом нашей программы(клиента)
    sockaddr_in * selfAddr = new (sockaddr_in);
    selfAddr->sin_family = AF_INET; // интернет протокол IPv4
    selfAddr->sin_port = 0; // любой порт на усмотрение ОС
    selfAddr->sin_addr.s_addr = 0; // все адреса нашего пк

    //подготовить структуру с адресом на той стороне( сервера)
    sockaddr_in * remoteAddr = new (sockaddr_in);
    remoteAddr->sin_family = AF_INET; // интернет протокол IPv4
    remoteAddr->sin_port = htons(13); // порт 
    remoteAddr->sin_addr.s_addr = inet_addr("127.0.0.1"); // все адреса нашего пк
    // подготовить буфер для передачи и приема данных
    char *buf = new char[256];
    strcpy(buf,"Сколько времени?\n"); // копируем строку
    int msgLen = strlen(buf); // вычисляем длину строки
    // создать сокет
    int mySocket = socket(AF_INET, SOCK_DGRAM, 0);//UDP 
    if (mySocket == -1) {
        errHandler("Error open socket",11);
    }
    //связать сокет с адресом
    int rc = bind(mySocket, (const sockaddr *) selfAddr, sizeof ( sockaddr_in));
    if (rc == -1) {
        close(mySocket);
        errHandler("Error bind socket with local address",12);
    }
    //установить соединение
    rc = connect(mySocket, ( const sockaddr*) remoteAddr, sizeof(sockaddr_in));
    if ( rc == -1) {
        close(mySocket);
        errHandler("Error connect socket with remote server",13);
    }
    //передать данные
    rc = send(mySocket, buf,msgLen,0);
    if ( rc == -1) {
        close(mySocket);
        errHandler("Error send message",14);
    }
    cout << "We send: " << buf << endl;
    // принять ответ
    rc = recv(mySocket, buf, 256,0);
    if ( rc == -1) {
        close(mySocket);
        errHandler("Error receive answer",15);
    }
    buf[rc]='\0';
            cout << "We receive: " << buf << endl;
    // закрыть сокет
    close(mySocket);

    delete selfAddr;
    delete remoteAddr;
    delete[] buf;
    return 0;
}