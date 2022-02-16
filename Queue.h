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

    friend std::ostream &operator<<(std::ostream &os, const Queue &queue) {
        os << "-> ";
        if (queue.head == nullptr) {
            os << "empty";
        }
        for (Node *cur = queue.head; cur != nullptr; cur = cur->next) {
            os << cur->info << " ";
        }
        return os;
    }
};