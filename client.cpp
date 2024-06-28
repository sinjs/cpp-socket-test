#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

void new_connection_and_send(const char *message)
{
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    connect(clientSocket, (struct sockaddr *)&serverAddress,
            sizeof(serverAddress));

    send(clientSocket, message, strlen(message), 0);

    close(clientSocket);
}

int main()
{
    new_connection_and_send("Hello!");
    new_connection_and_send("Hexx");
    return 0;
}
