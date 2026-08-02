#ifndef SOCKET_SERVER_H
#define SOCKET_SERVER_H

int SocketServer_Init(void);

void SocketServer_Send(const char *message);

void SocketServer_Close(void);

#endif