#include "server.h"   

Client::Client(int socket, const string& name, const string& roomName) : socket(socket), name(name), roomName(roomName) {}

int Client::getSocket() const {
    return socket;
}

const string& Client::getName() const {
    return name;
}

const string& Client::getRoomName() const {
    return roomName;
}

Server::Server(){}

string Server::trim(const string& str) {
    // ... (trim implementation)
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");

    if (first == string::npos || last == string::npos)
        return "";
    else
        return str.substr(first, last - first + 1);
}

string Server::receiveString(int clientSocket) {
    // ... (receiveString implementation)
    char buffer[4096];
    int bytesReceived = recv(clientSocket, buffer, 4096, 0);

    // Check if data reception was successful
    if (bytesReceived <= 0) {
        cerr << "Error: Received data from client failed!" << endl;
        return "";
    }
    return string(buffer, 0, bytesReceived);
}
