#pragma once

#include <ostream>
#include "Stack.h"

template<class T>
using Comparator = int (*)(T, T);

template<class T>
class Tree {
    struct Node {
        T info;
        Node *left;
        Node *right;
    };

    Node *root;
    Comparator<T> comparator;
public:
    Tree(Comparator<T> comparator) {
        this->root = nullptr;
        this->comparator = comparator;
    }

    ~Tree() {
        if (root == nullptr) {
            return;
        }
        Stack<Node *> stack;
        stack.push(root);
        while (!stack.isEmpty()) {
            Node *cur = stack.pop();
            if (cur->left != nullptr) {
                stack.push(cur->left);
            }
            if (cur->right != nullptr) {
                stack.push(cur->right);
            }
        }
    }

    void push(T info) {
        Node *newItem = new Node{info};
        if (root == nullptr) {
            root = newItem;
            return;
        }
        int cmp;
        Node *prev;
        Node *cur = root;
        while (cur != nullptr) {
            prev = cur;
            cmp = comparator(info, cur->info);
            if (cmp == 0) {
                break;
            }
            cur = cmp < 0 ? cur->left : cur->right;
        }
        if (cmp < 0) {
            prev->left = newItem;
        } else {
            Node *t = prev->right;
            prev->right = newItem;
            newItem->right = t;
        }
    }

    bool contains(T info) {
        Node *cur = root;
        while (cur != nullptr) {
            int cmp = comparator(info, cur->info);
            if (cmp == 0) {
                return true;
            }
            cur = cmp < 0 ? cur->left : cur->right;
        }
        return false;
    }

    void remove(T info){
//        todo
    }

    friend std::ostream &operator<<(std::ostream &os, const Tree &tree) {
        tree.print(os, tree.root);
        return os;
    }

private:
    void print(std::ostream &os, Node *node) const {
        if (node != nullptr) {
            print(os, node->left);
            os << node->info << " ";
            print(os, node->right);
        }
    }
};