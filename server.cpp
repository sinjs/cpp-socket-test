#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main()
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr *)&serverAddress,
         sizeof(serverAddress));

    listen(serverSocket, 5);

    char buffer[1024] = {0};

    while (true)
    {
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        int n = recv(clientSocket, buffer, sizeof(buffer), 0);
        buffer[n] = '\0';
        cout << "Incoming Message: " << buffer
             << endl;
    }

    return 0;
}
