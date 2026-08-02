#include "socket_server.h"
#include "logger.h"
#include <string.h>
#include <stdio.h>
#ifdef _WIN32

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

static SOCKET serverSocket = INVALID_SOCKET;
static SOCKET clientSocket = INVALID_SOCKET;

int SocketServer_Init(void)
{
    WSADATA wsa;

    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0)
        return -1;

    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(serverSocket == INVALID_SOCKET)
        return -1;

    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(5000);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*)&server, sizeof(server));

    listen(serverSocket,1);

    Logger_LogInfo("Waiting for Dashboard...");

    clientSocket = accept(serverSocket,NULL,NULL);

    Logger_LogInfo("Dashboard Connected");

    return 0;
}

void SocketServer_Send(const char *message)
{
    if(clientSocket != INVALID_SOCKET)
    {
        int result = send(
            clientSocket,
            message,
            (int)strlen(message),
            0
        );

        if(result == SOCKET_ERROR)
        {
            Logger_LogError("Socket send failed");
        }
    }
}

void SocketServer_Close(void)
{
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();
}

#endif