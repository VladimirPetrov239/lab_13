.PHONY: all clean

CXX=g++
CXXFLAGS=-std=c++11 -Wall -pedantic

all: lab_13

bin:
	mkdir -p bin

lab_13: src/main.cpp include/*.h bin
	$(CXX) $(CXXFLAGS) -o $@ -Iinclude $< 

bin/%.o: src/%.cpp include/*.h bin
	$(CXX) $(CXXFLAGS) -c -o $@ -Iinclude $<

clean:
	rm -rf bin lab_13
