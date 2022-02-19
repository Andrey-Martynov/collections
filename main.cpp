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
void pushToQueue(Node<T> *&top, T info) {
    Node<T> *newItem = new Node<T>{info, nullptr};
    if (top == nullptr) {
        top = newItem;
        return;
    }
    Node<T> *cur = top;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = newItem;
}

template<class T>
T popFromQueue(Node<T> *&top) {
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

template<class T>
void clear(Node<T> *&top) {
    while (top != nullptr) {
        Node<T> *cur = top;
        top = top->next;
        delete cur;
    }
}

int main() {
    Node<int> *top = nullptr;
    cout << "Stack\n";
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
    cout<<"\n\nQueue\n";
    for (int i = 0; i < 10; i++) {
        pushToQueue(top, i * 10);
        print(top);
    }
    print(top);
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << popFromQueue(top) << endl;
        print(top);
    }
    clear(top);
    return 0;
}
