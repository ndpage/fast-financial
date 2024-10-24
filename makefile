
BOOST_INC=/usr/local/include/boost
BOOST_LIB=/usr/local/lib

all: fastfinancial

fastfinancial:	fastfinancial.o fastfinancial.hpp
	g++ -std=c++20 -o fastfinancial fastfinancial.o -lboost_system -lpthread

fastfinancial.o:	fastfinancial.cpp fastfinancial.hpp
	g++ -std=c++20 -c fastfinancial.cpp -o fastfinancial.o

clean:
	rm *.o
