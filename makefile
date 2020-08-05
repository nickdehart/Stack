# This is a comment line
# Sample makefile for fraction class

test: test_stack.o
	g++ -std=c++11 -o test test_stack.o

test_stack.o: test_stack.cpp stack.h stack.hpp
	g++ -std=c++11 -c test_stack.cpp

clean:
	rm *.o test