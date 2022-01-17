
#include "ListeningSocket.hpp"

HDE::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interfaces, int bcklg) :
    BindingSocket(domain, service, protocol, port, interfaces) {
        backlog = bcklg;
        // start lisetening to the network 
        start_listening();
        // confirm the connection was successful
        test_connection(listening);
    }

void HDE::ListeningSocket::start_listening() {
    listening = listen(get_sock(), backlog);
}

// Getters
int HDE::ListeningSocket::get_listening() { return listening; }
int HDE::ListeningSocket::get_backlog() { return backlog; }