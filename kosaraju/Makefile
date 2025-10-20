CXX = g++

CXXFLAGS = -std=c++11 -Wall -O2

SRC = kosaraju.cpp

TARGET = kosaraju

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)