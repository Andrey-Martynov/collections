#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Tree.h"

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

    cout << "\n\nTree\n";
    Tree<int> tree([](int x, int y) { return x - y; });
    for (int i = 0; i < 10; i++) {
        tree.push(rand() % 1000);
        tree.print();
    }
    return 0;
}
