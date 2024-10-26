include env.settings

# Variables
TARGET := fastfinancial.app
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
INCLUDES = -I$(INCLUDE_DIR) -I$(BOOST_INC) 

# Rules
all: $(BUILD_DIR) $(TARGET)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link objects to create the final executable
$(TARGET): $(OBJS)
	$(CXX) -std=c++20 $(CFLAGS) -o $(BUILD_DIR)/$@ $^ $(LDFLAGS)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -std=c++20 $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean

#fastfinancial:
#	$(CXX) -std=c++20 -o fastfinancial fastfinancial.o -lboost_system -lpthread

#fastfinancial.o:	fastfinancial.cpp fastfinancial.hpp
#	g++ -std=c++20 -c fastfinancial.cpp -o fastfinancial.o
#
#clean:
#	rm *.o
