
#include "ListeningSocket.hpp"

HDE::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interfaces, int bcklg) :
    BindingSocket(domain, service, protocol, port, interfaces) {
        backlog = bcklg;
        start_listening();
        test_connection(listening);
    }

void HDE::ListeningSocket::start_listening() {
    listening = listen(get_connection(), backlog);
}