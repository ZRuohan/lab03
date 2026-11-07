CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

all: examheap

examheap: examheap.cpp heap.cpp heap.h
	$(CXX) $(CXXFLAGS) examheap.cpp heap.cpp -o examheap
