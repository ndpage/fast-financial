#include "fastfinancial.hpp"

int main(int argc, char* argv[]) {
    try {
        if (argc != 3) {
            std::cerr << print_usage() << std::endl;
            return 1;
        }

       boost::asio::io_context io_context;
       MarketDataProcessor processor(io_context, argv[1], argv[2]);
       io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

