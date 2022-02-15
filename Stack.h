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

    void print() {
        std::cout << "-> ";
        if (top == nullptr) {
            std::cout << "empty";
        }
        for (Node *cur = top; cur != nullptr; cur = cur->next) {
            std::cout << cur->info << " ";
        }
        std::cout << std::endl;
    }
};
