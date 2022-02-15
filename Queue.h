#pragma once

#include "iostream"

template<class T>
class Queue {
    struct Node {
        T info;
        Node *next;
    };

    Node *head;
    Node *tail;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    ~Queue() {
        while (head != nullptr) {
            Node *cur = head;
            head = head->next;
            delete cur;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void push(T info) {
        Node *newItem = new Node{info, nullptr};
        if (head == nullptr) {
            head = tail = newItem;
            return;
        }
        tail->next = newItem;
        tail = newItem;
    }

    T pop() {
        T info = head->info;
        Node *cur = head;
        head = head->next;
        delete cur;
        return info;
    }

    void print() {
        std::cout << "-> ";
        if (head == nullptr) {
            std::cout << "empty";
        }
        for (Node *cur = head; cur != nullptr; cur = cur->next) {
            std::cout << cur->info << " ";
        }
        std::cout << std::endl;
    }
};