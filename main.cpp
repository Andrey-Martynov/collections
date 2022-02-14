#include <iostream>

using namespace std;

template<class T>
struct Node {
    T info;
    Node<T> *next;
};

template<class T>
void pushToStack(Node<T> *&top, T info) {
    Node<T> *newItem = new Node<T>{info, top};
    top = newItem;
}

template<class T>
T popFromStack(Node<T> *&top) {
    T info = top->info;
    Node<T> *cur = top;
    top = top->next;
    delete cur;
    return info;
}

template<class T>
void print(Node<T> *top) {
    cout << "-> ";
    if (top == nullptr) {
        cout << "empty";
    }
    while (top != nullptr) {
        cout << top->info << " ";
        top = top->next;
    }
    cout << endl;
}

int main() {
    Node<int> *top = nullptr;
    print(top);
    for (int i = 0; i < 10; i++) {
        pushToStack(top, i * 10);
        print(top);
    }
    print(top);
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << popFromStack(top) << endl;
        print(top);
    }
    return 0;
}
