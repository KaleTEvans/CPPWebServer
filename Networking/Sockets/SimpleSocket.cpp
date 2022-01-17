#include "SimpleSocket.hpp"

HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interfaces) {
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interfaces);
    // establish the connection, using a private variable so as not to change it
    sock = socket(domain, service, protocol);
    // test the socket connection
    test_connection(sock);
}

// test connection virtual function
void HDE::SimpleSocket::test_connection(int item_to_test) {
    // confirms that the socket or connection has been properly established
    if (item_to_test < 0) perror("Failed to connect..."), exit(EXIT_FAILURE);
}

struct sockaddr_in HDE::SimpleSocket::get_address() {
    return address;
}

int HDE::SimpleSocket::get_sock() {
    return sock;
}