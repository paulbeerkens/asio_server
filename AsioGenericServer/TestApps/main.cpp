#include <asio/streambuf.hpp>
#include <asio/strand.hpp>
#include <asio/read_until.hpp>
#include <deque>
#include "../AsioGenericServer.hpp"


class chat_handler
:public std::enable_shared_from_this <chat_handler>
{
public:
    chat_handler(asio::io_service& service)
            :service_(service)
            ,socket_ (service)
             ,write_strand_ (service)
    {}


    asio::ip::tcp::socket& socket () {return socket_;}

    void start () {read_packet ();}

    void read_packet ()
    {
        asio::async_read_until (socket_, in_packet_,'\0',
                 [me=shared_from_this ()] (asio::error_code const& ec, std::size_t bytes_xfer)
                 {
                    me->read_packet_done (ec, bytes_xfer);
                 });
    }

    void read_packet_done (asio::error_code const& error,
    std::size_t bytes_transferred)
    {
        if (error) return;

        std::istream stream(&in_packet_);
        std::string packet_string;
        stream>>packet_string;

        std::cout<<"Received: "<<packet_string<<std::endl;

        read_packet ();
    }

    void send
    continue from https://www.youtube.com/watch?v=rwOv_tw2eA4
private:
    asio::io_service& service_;
    asio::ip::tcp::socket socket_;
    asio::io_service::strand write_strand_;
    asio::streambuf in_packet_;
    std::deque<std::string> send_packet_queue;
};

int main ()
{
    asio_generic_server<chat_handler> a;
    a.start_server(8888);
    a.join_server_threads ();
}
