#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <list>

namespace StackStructure
{

template <typename T>
class Stack
{
private:
	std::list<T> theStack;

public:
	Stack();								  // zero-argument constructor.
	~Stack();								  // destructor.
	Stack(const Stack<T> &rhs);				  // copy constructor.
	Stack(Stack<T> &&rhs);					  // move constructor.
	Stack<T> &operator=(const Stack<T> &rhs); // copy assignment operator=.
	Stack<T> &operator=(Stack<T> &&rhs);	  // move assignment operator=
	bool empty() const;						  // returns true if the Stack contains no elements, and false otherwise.
	void clear();							  // delete all elements from the stack.
	void push(const T &x);					  // adds  x  to the Stack.   copy version.
	void push(T &&x);						  // adds x to the Stack. move version.
	void pop();								  // removes and discards the most recently added element of the Stack.
	T &top();								  // mutator that returns a reference to the most recently added element of the Stack.
	const T &top() const;					  // accessor that returns the most recently added element of the Stack.
	int size() const;						  // returns the number of elements stored in the Stack.
	void print(std::ostream &os, char ofc = ' ') const;
	// print elements of Stack to ostream os.
	//ofc is the separator between elements in the stack when they are printed out.
	//Note that print() prints elements in the opposite order of the Stack (that is,
	//the oldest element should be printed first).
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Stack<T> &a);
// invokes the print() method to print the Stack<T> a in the specified ostream

template <typename T>
bool operator==(const Stack<T> &, const Stack<T> &);
// returns true if the two compared Stacks have the same elements, in the same order.

template <typename T>
bool operator!=(const Stack<T> &, const Stack<T> &);
// opposite of operator==().

template <typename T>
bool operator<(const Stack<T> &a, const Stack<T> &b);
// returns true if every element in Stack a is smaller than corresponding elements of
//Statck b, i.e., if repeatedly invoking top() and pop() on both a and b will generate a
//sequence of elements a_i from a and b_i from b, and for every i,  a_i < b_i, until a is empty.

#include "stack.hpp"

} // namespace StackStructure

#endif
