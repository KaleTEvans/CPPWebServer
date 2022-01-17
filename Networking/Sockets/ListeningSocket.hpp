#ifndef ListeningSocket_hpp
#define ListeningSocket_hpp

#include <stdio.h>

#include "BindingSocket.hpp"

namespace HDE
{
    class ListeningSocket : public BindingSocket {

        int backlog;
        int listening;

        public:
            ListeningSocket(int domain, int service, int protocol, int port, u_long interfaces, int bcklg);

            void start_listening();
            // getters
            int get_listening();
            int get_backlog();
    };
}


#endif