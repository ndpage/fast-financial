#ifndef FASTFINANCIAL_H
#define FASTFINANCIAL_H
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

namespace fastfinancial {
class MarketDataProcessor {
public:
    MarketDataProcessor(boost::asio::io_context& io_context, const std::string& host, const std::string& port)
        : socket_(io_context), resolver_(io_context) {
        boost::asio::ip::tcp::resolver::results_type endpoints = resolver_.resolve(host, port);
        boost::asio::async_connect(socket_, endpoints,
            boost::bind(&MarketDataProcessor::handle_connect, this, boost::asio::placeholders::error));
    }

   /**
    * @brief Handles the connection from the client
    * 
    * @param error 
    */
    void handle_connect(const boost::system::error_code& error);
   
   /**
    * @brief Read the data from the buffer
    * 
    * @param error 
    */
    void handle_read(const boost::system::error_code& error) {
        if (!error) {
            // Process the market data here
            std::cout << "Received market data: " << data_ << std::endl;

            // Continue to read more data
            boost::asio::async_read(socket_, boost::asio::buffer(data_, max_length),
                boost::bind(&MarketDataProcessor::handle_read, this, boost::asio::placeholders::error));
        }
    }

private:
    boost::asio::ip::tcp::socket socket_;
    boost::asio::ip::tcp::resolver resolver_;
    enum { max_length = 1024 };
    char data_[max_length];
};
}
#endif
