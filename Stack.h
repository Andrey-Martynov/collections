#pragma once

#include "iostream"

template<class T>
class Stack {
    struct Node {
        T info;
        Node *next;
    };

    Node *top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (top != nullptr) {
            Node *cur = top;
            top = top->next;
            delete cur;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(T info) {
        Node *newItem = new Node{info, top};
        top = newItem;
    }

    T pop() {
        T info = top->info;
        Node *cur = top;
        top = top->next;
        delete cur;
        return info;
    }

    friend std::ostream &operator<<(std::ostream &os, const Stack &stack) {
        os << "-> ";
        if (stack.top == nullptr) {
            os << "empty";
        }
        for (Node *cur = stack.top; cur != nullptr; cur = cur->next) {
            os << cur->info << " ";
        }
        return os;
    }
};
