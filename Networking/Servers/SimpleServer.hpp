#ifndef SimpleServer_hpp
#define SimpleServer_hpp

#include <stdio.h>
#include <io.h>
#include <process.h>

#include "../hdelibc-networking.hpp"

namespace HDE
{
    class SimpleServer {
        // point to socket memory space
        ListeningSocket* socket;
        // virtual functions for reusability
        virtual void accepter() = 0;
        virtual void handler() = 0;
        virtual void responder() = 0;

        public:
            SimpleServer(int domain, int service, int protocol, int port, u_long interfaces, int bcklg);
            // virtual launch function
            virtual void launch() = 0;

            // getters
            ListeningSocket* get_socket();
    };
}

#endif