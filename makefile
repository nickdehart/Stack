# This is a comment line
# Sample makefile for fraction class

test: test_stack1.o
	g++ -std=c++11 -o test test_stack1.o

test_stack1.o: test_stack1.cpp stack.h stack.hpp
	g++ -std=c++11 -c test_stack1.cpp

clean:
	rm *.o test