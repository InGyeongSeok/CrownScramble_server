#pragma once

#include <winSock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <iostream>
#include <cstring>
#include <thread>
#include <queue>
#include <mutex>
using namespace std;
#include "protocol.h"
#include "Header.h"
extern bool isW, isA, isS, isD;
extern bool isBullet;

#define serverIP "127.0.0.1"
#define serverPort 7777

#pragma comment(lib, "ws2_32.lib")
void makeInfo(SC_PLAYER_PACKET* p);
void animalInfo(SC_MONSTER_PACKET* p, int i);

void get_vangle(float* x, float* y);

extern int global_ID;

class NetworkManager {
public:
    NetworkManager()
    {
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
        std::cout << "����?" << std::endl;
        closesocket(clientSocket);
        WSACleanup();
    }

    bool Connect() {
        sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(serverPort);
        inet_pton(AF_INET, serverIP, &serverAddr.sin_addr);

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
    void SendIdlePlayer()
    {
        //idle ����!
        if (!isW && !isA && !isS && !isD && !isBullet) {
            CS_PLAYER_PACKET p;
            p.player_id = global_ID;
            get_vangle(&(p.camera.VangleX), &(p.camera.VangleY));
            p.Player_key.is_bullet = true;
            if (!SendPlayerData(p)) {
                std::cout << "��Ŷ������ ����" << std::endl;
            }
        }
    }
    bool SendPlayerData(CS_PLAYER_PACKET& p) {
        // Ŭ���̾�Ʈ���� ������ ID�� ������ ���� �۾�

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

    bool Receiveid() {
        int result = recv(clientSocket, reinterpret_cast<char*>(&global_ID), sizeof(global_ID), 0);
        if (result == SOCKET_ERROR) {
            std::cout << "Failed to receive data" << std::endl;
            return false;
        }
        std::cout << global_ID << std::endl;
        return false; // Connection closed
    }


    bool recvData() {
        char buf[500];
        int size;
        recv(clientSocket, reinterpret_cast<char*>(&size), sizeof(size), 0);
        recv(clientSocket, buf, size, 0);
        switch (buf[0]) {
        case SC_PLAYER: {
            SC_PLAYER_PACKET* p = reinterpret_cast<SC_PLAYER_PACKET*>(buf);
            makeInfo(p);
        }
        break;
        case SC_MONSTER: {
            std::cout << size << "����Ʈ ����" << std::endl;
            for (int i = 0; i < 6; ++i) {
                char anibuf[32];
                std::memcpy(&anibuf, &buf[i * 32], 32);
                SC_MONSTER_PACKET* p = reinterpret_cast<SC_MONSTER_PACKET*>(anibuf);
                animalInfo(p, i);
                cout << "=====" << i << "====" << endl;

                cout << p->x << endl;
                cout << p->y << endl;
                cout << p->z << endl;
            }
            break;

        }
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
    SOCKET clientSocket;
};