#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;
using namespace StackStructure;

int main()
{
    Stack<int> stck;

    cout << "inserting 10 elements" << endl;
    // Add some numbers
    for (unsigned int i = 0; i < 10; ++i)
        stck.push(i);

    cout << "Size: " << stck.size() << endl;
    cout << "elements: " << stck << endl;
    cout << "emptying the stack" << endl;

    // Remove the numbers
    while (!stck.empty())
    {
        cout << stck.top() << " ";
        stck.pop();
    }

    cout << endl;
    cout << "Size: " << stck.size() << endl;
    cout << "inserting 10 elements" << endl;

    // Add some more numbers
    for (unsigned int i = 0; i < 10; ++i)
        stck.push(i);

    // Test copy constructor
    Stack<int> stck1(stck);
    Stack<int> stck2;
    // Test assignment operator
    stck2 = stck;

    cout << stck << endl;
    cout << stck1 << endl;
    cout << stck2 << endl;

    if (stck1 == stck2)
        cout << "GOOD: Equal stacks" << endl;
    else
        cout << "ERROR: stacks are not equal" << endl;

    stck1.pop();

    if (stck1 == stck2)
        cout << "ERROR: equal stacks" << endl;
    else
        cout << "GOOD: Stacks are not equal" << endl;

    if (stck1 < stck2)
        cout << "GOOD: stck1 is less than stck2" << endl;
    else
        cout << "ERROR: wrong comparision" << endl;

    return (EXIT_SUCCESS);
}
