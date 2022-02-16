#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Tree.h"

using namespace std;

int main() {
    Stack<int> stack;
    cout << "Stack\n";
    cout << stack << endl;
    for (int i = 0; i < 10; i++) {
        stack.push(i * 10);
        cout << stack << endl;
    }
    cout << stack << endl;
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << stack.pop() << endl;
        cout << stack << endl;
    }

    cout << "\n\nQueue\n";
    Queue<int> queue;
    for (int i = 0; i < 10; i++) {
        queue.push(i * 10);
        cout << queue << endl;
    }
    cout << queue << endl;
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << queue.pop() << endl;
        cout << queue << endl;
    }

    cout << "\n\nTree\n";
    Tree<int> tree([](int x, int y) { return x - y; });
    for (int i = 0; i < 10; i++) {
        tree.push(rand() % 1000);
        cout << tree << endl;
    }
    return 0;
}
