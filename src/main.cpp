#include <iostream>
#include "fastfi/fastfi.h"


std::string  print_usage(std::string prog_name = "fastfi") {
    return "Usage: " + prog_name + " <host> <port>\n";
}

int main(int argc, char* argv[]) {
    std::cout << "==== Fast Financial ==== \n" << std::endl;
    try {
        if (argc != 3) {
            std::cerr << print_usage() << std::endl;
            return 1;
       }
        std::string host = argv[1];
        std::string  port = argv[2]; 
        // boost::asio::io_context io_context;
        boost::asio::io_context io_context{1};

        std::cout << " > Launching processor on host "<< host << " and port " << port << "." << std::endl;    
        fastfi::MarketDataProcessor processor(io_context, host, port);
        io_context.run();
   } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
   }

   return 0;
}