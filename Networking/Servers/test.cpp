#include <stdio.h>

#include "SimpleServer.hpp"
#include "TestServer.hpp"

int main() {
    HDE::TestServer *t;

    t->launch();
}