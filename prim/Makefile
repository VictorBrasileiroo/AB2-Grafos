CXX = g++

CXXFLAGS = -std=c++11 -Wall -O2

SRC = prim.cpp

TARGET = prim

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)