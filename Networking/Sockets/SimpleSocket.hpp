#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <iostream>

namespace HDE 
{
    class SimpleSocket {
        struct sockaddr_in address;
        int sock;
        int connection;

        public:
            SimpleSocket(int domain, int service, int protocol, int port, u_long interfaces);
            // virtual function to connect to a network
            virtual int connect_to_network(int sock, struct sockaddr_in address) = 0;

            void test_connection(int);
            // getter fxns
            struct sockaddr_in get_address();
            int get_sock();
            int get_connection();
            // setter fxns
            void set_connection(int con);
    };
}

#endif