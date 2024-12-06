#include <iostream>
#include "FastFinancial.h"

std::string  print_usage(){
    return "Usage: ./fastfinancial <host> <port>\n\tplease provide <host> and <port>";
}

int main(int argc, char* argv[]) {
    std::cout << " ==== Fast Financial ==== " << std::endl;
    try {
        if (argc != 3) {
            std::cerr << print_usage() << std::endl;
            return 1;
       }
        std::string host = argv[1];
        std::string  port = argv[2]; 
        boost::asio::io_context io_context;
        std::cout << " > Launching processor on host "<< host << " and port " << port << "." << std::endl;    
        fastfinancial::MarketDataProcessor processor(io_context, argv[1], argv[2]);
        io_context.run();
   } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
   }

   return 0;
}