CXX = g++

CXXFLAGS = -std=c++11 -Wall -O2

SRC = dijkstra.cpp

TARGET = dijkstra

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)