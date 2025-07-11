#include "fastfi/fastfi.h"

namespace fastfi {

    void MarketDataProcessor::handle_connect(const boost::system::error_code& error) {
        if (!error) {
            boost::asio::async_read(socket_, boost::asio::buffer(data_, max_length),
            boost::bind(&MarketDataProcessor::handle_read, this, boost::asio::placeholders::error));
        }
    }
}

