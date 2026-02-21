CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRCS = heap.cpp examheap.cpp
TARGET = examheap
all: $(TARGET)
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
clean:
	rm -f $(TARGET) *.o
