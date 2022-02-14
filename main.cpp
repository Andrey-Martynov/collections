#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main() {
    Stack<int> stack;
    cout << "Stack\n";
    stack.print();
    for (int i = 0; i < 10; i++) {
        stack.push(i * 10);
        stack.print();
    }
    stack.print();
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << stack.pop() << endl;
        stack.print();
    }

    cout << "\n\nQueue\n";
    Queue<int> queue;
    for (int i = 0; i < 10; i++) {
        queue.push(i * 10);
        queue.print();
    }
    queue.print();
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << queue.pop() << endl;
        queue.print();
    }
    return 0;
}
