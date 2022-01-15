#include "BindingSocket.hpp"

HDE::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long interfaces) :
    SimpleSocket(domain, service, protocol, port, interfaces) {
        set_connection(connect_to_network(get_sock(), get_address()));
        test_connection(get_connection());
    }

// connect to network virtual function implementation
int HDE::BindingSocket::connect_to_network(int sock, struct sockaddr_in address) {
    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}

