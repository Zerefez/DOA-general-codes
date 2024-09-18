#include <iostream>
#include "Set.h"

int main() {

    Setstack<int> mySetStack;

    cout << "Initial stack is empty: " << (mySetStack.empty() ? "Yes" : "No") << endl;

    mySetStack.push(5);
    mySetStack.push(24);
    mySetStack.push(5);  // Duplicate, should not be added
    mySetStack.push(11);
    mySetStack.push(23);

    cout << "Stack elements after pushing: ";
    mySetStack.display();

    int checkValue = 11;
    cout << "Stack contains " << checkValue << ": " << (mySetStack.contains(checkValue) ? "Yes" : "No") << endl;

    std::cout << "Removing element 10 from the stack" << endl;
    mySetStack.remove(11);
    cout << "Stack elements after removing 10:" << endl;
    mySetStack.display();

    cout << "Current stack size: " << mySetStack.size() << endl;

    cout << "Clearing the stack" << endl;
    mySetStack.clear();
    cout << "Stack elements after clearing, size = " << mySetStack.size() << endl;
    mySetStack.display();

    return 0;
}
