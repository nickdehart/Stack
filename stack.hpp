#include <iostream>
#include <list>
#include <cstdlib>
#include "stack.h"

using namespace StackStructure; //

template <typename T>
Stack<T>::Stack()//: zero-argument constructor.   
{//list created with object
}

template <typename T>
Stack<T>::~Stack ()//: destructor.  
{//list class has its own destructor
}

template <typename T>
Stack<T>::Stack (const Stack<T> &rhs)//: copy constructor.   
{
  for(auto & x : rhs.theStack)
  theStack.push_back(x);
}

template <typename T>
Stack<T>::Stack(Stack<T> && rhs)//: move constructor.
 : theStack{rhs.theStack}
{rhs.clear();}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack <T> &rhs)//: copy assignment operator=.
{
  std::list<T> copy = rhs.theStack;
  copy.swap(theStack);
  return *this;
}

template <typename T>
Stack<T> & Stack<T>::operator=(Stack<T> && rhs)//: move assignment operator=
{
  theStack.swap(rhs.theStack);	  
  return *this;
}

template <typename T>
bool Stack<T>::empty() const//: returns true if the Stack contains no elements, and false otherwise.  
{return(theStack.empty());}

template <typename T>
void Stack<T>::clear()//: delete all elements from the stack.
{if(!empty())
  theStack.clear();}

template <typename T>
void Stack<T>::push(const T& x)//: adds  x  to the Stack.   copy version.
{theStack.push_back(x);}

template <typename T>
void Stack<T>::push(T && x)//: adds x to the Stack. move version.
{theStack.push_back(x);}

template <typename T>
void Stack<T>::pop()//: removes and discards the most recently added element of the Stack.  
{if(!empty())
   theStack.pop_back();}

template <typename T>
T& Stack<T>::top()//: mutator that returns a reference to the most recently added element of the Stack.  
{//if(!empty())
  return(theStack.back());}

template <typename T>
const T& Stack<T>::top() const//: accessor that returns the most recently added element of the Stack.  
{//if(!empty())
  return(theStack.back());}

template <typename T>
int Stack<T>::size() const//: returns the number of elements stored in the Stack.
{return(theStack.size());}

template <typename T>
void Stack<T>::print(std::ostream& os, char ofc) const//: print elements of Stack to ostream os. 
//ofc is the separator between elements in the stack when they are printed out. 
//Note that print() prints elements in the opposite order of the Stack (that is, the oldest element should be printed first).
{
  for(auto & x : theStack)
	os << x << ofc;
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const Stack<T>& a)
//: invokes the print() method to print the Stack<T> a in the specified ostream    
{if(!a.empty())
  a.print(os,' ');
  return os;}

template <typename T>
bool operator== (const Stack<T>& a, const Stack <T>& b)
//: returns true if the two compared Stacks have the same elements, in the same order.  
{
if(a.empty() && b.empty())
  return true;
if(a.empty() || b.empty())
  return false;
if(a.size() != b.size())
  return false;
else{

Stack<T> c = a;
Stack<T> d = b;
while((c.top() == d.top()) && (!c.empty()))
  {
   if(!c.empty())
     c.pop();
   if(!d.empty())
     d.pop();
  }
if(c.empty())
  return true;
else return false;


}
}

template <typename T>
bool operator!= (const Stack<T>& a, const Stack <T>& b)
//: opposite of operator==().
{
bool equal = a == b;
if(equal == true)
  equal = false;
else equal = true;
return equal;
}

template <typename T>
bool operator< (const Stack<T>& a, const Stack <T>& b)
{
if(a.size() > b.size())
  return false;
if(a != b)
{
Stack<T> c = a;
Stack<T> d = b;
while((c.top() < d.top()) && (!c.empty()))
  {
   if(!c.empty())
     c.pop();
   if(!d.empty())
     d.pop();
  }
if(c.empty())
  return true;
else return false;
}
else return false;
}