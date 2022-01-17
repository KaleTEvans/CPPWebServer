
#include "SimpleServer.hpp"

HDE::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, u_long interfaces, int bcklg) {
    // create new listening socket object
    socket = new ListeningSocket(domain, service, protocol, port, interfaces, bcklg);
}

HDE::ListeningSocket* HDE::SimpleServer::get_socket() {
    return socket;
}