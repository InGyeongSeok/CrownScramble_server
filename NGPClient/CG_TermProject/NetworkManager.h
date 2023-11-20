#pragma once

#include <winSock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include "protocol.h"


#pragma comment(lib, "ws2_32.lib")
void makeInfo(SC_PLAYER_PACKET* p);


class NetworkManager {
public:
    NetworkManager(const std::string& serverIP, int serverPort)
        : serverIP(serverIP), serverPort(serverPort) {
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            std::cout << "WSAStartup failed" << std::endl;
            exit(1);
        }

        clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (clientSocket == INVALID_SOCKET) {
            std::cout << "Failed to create socket" << std::endl;
            WSACleanup();
            exit(1);
        }
    }

    ~NetworkManager() {
        closesocket(clientSocket);
        WSACleanup();
    }

    bool Connect() {
        sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(serverPort);
        inet_pton(AF_INET, serverIP.c_str(), &serverAddr.sin_addr);

        if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
            std::cout << "Failed to connect to the server" << std::endl;
            return false;
        }

        return true;
    }

    bool SendData(const std::string& data) {
        int result = send(clientSocket, data.c_str(), static_cast<int>(data.size()), 0);
        if (result == SOCKET_ERROR) {
            std::cout << "Failed to send data" << std::endl;
            return false;
        }
        return true;
    }

    bool SendPlayerData (CS_PLAYER_PACKET& p) {
        // Ŭ���̾�Ʈ���� ������ ID�� ������ ���� �۾�

        p.Player_pos.x = 3;
        p.Player_pos.y = 3;
        p.Player_pos.z = 3;

        int size = sizeof(p);
        send(clientSocket, reinterpret_cast<char*>(&size), sizeof(size), 0);
        int result = send(clientSocket, reinterpret_cast<char*>(&p), sizeof(p), 0);
        if (result == SOCKET_ERROR) {
            std::cout << "Failed to send data" << std::endl;
            return false;
        }
        return true;
    }

    bool ReceiveData(std::string& receivedData) {
        char buffer[1024];
        int result = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (result == SOCKET_ERROR) {
            std::cout << "Failed to receive data" << std::endl;
            return false;
        }

        if (result > 0) {
            receivedData.assign(buffer, result);
            return true;
        }

        return false; // Connection closed
    }

    bool recvData() {
        char buf[100];
        int size;
        recv(clientSocket, reinterpret_cast<char*>(&size), sizeof(size), 0);
        std::cout << size << "����Ʈ ����" << std::endl;
        recv(clientSocket, buf, size, 0);

        switch (buf[0]) {
        case SC_PLAYER: {
            SC_PLAYER_PACKET* p = reinterpret_cast<SC_PLAYER_PACKET*>(buf);
            std::cout << p->Player_pos.x << std::endl;
            std::cout << p->Player_pos.y << std::endl;
            std::cout << p->Player_pos.z << std::endl;
            //if (p->player_id == hero.id)
            makeInfo(p);
            
        }
        break;
        case SC_MONSTER: {
            SC_MONSTER_PACKET* p = reinterpret_cast<SC_MONSTER_PACKET*>(buf);
       
        }
        break;
        case SC_BULLET: {
            SC_BULLET_PACKET* p = reinterpret_cast<SC_BULLET_PACKET*>(buf);
        }
                       break;
        default:
            std::cout << "�߸��� ������" << std::endl;
            break;
        }
        return false;
    }
private:
    std::string serverIP;
    int serverPort;
    SOCKET clientSocket;
};