
BOOST_INC=/usr/local/include/boost
BOOST_LIB=/usr/local/lib

#main.o: main.cpp
#	clang -std=c++17 -I$(BOOST_INC) -c main.cpp -o main.o

fastfinancial:	fastfinancial.cpp
	g++ -std=c++17 fastfinancial.cpp -lboost_system -lpthread -o fastfinancial

