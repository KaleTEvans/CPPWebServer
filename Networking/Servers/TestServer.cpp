
#include "TestServer.hpp"

HDE::TestServer::TestServer() : SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10) {
    launch();
}

void HDE::TestServer::accepter() {
    struct sockaddr_in address = get_socket()->get_address();

    int addrlen = sizeof(address);

    new_socket = accept(get_socket()->get_sock(), (struct sockaddr*)&address, (socklen_t*)&addrlen);
    // store the actual request in buffer
    read(new_socket, buffer, 30000);
}

void HDE::TestServer::handler() {
    std::cout << buffer << std::endl;
}

// output server response
void HDE::TestServer::responder() {
    // create a pointer to a string literal
    char *hello = "Hello from server";
    write(new_socket, hello, strlen(hello));
    close(new_socket);
}

void HDE::TestServer::launch() {
    while (1) {
        std::cout << "======WAITING=======" << std::endl;
        accepter();
        handler();
        responder();
        std::cout << "======DONE======" << std::endl;
    }
}