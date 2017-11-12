#include "../AsioGenericServer.hpp"


class ClientHandler
{
public:
    ClientHandler (asio::io_service io_service) {};
};

int main ()
{
    asio_generic_server<ClientHandler> a;
}
