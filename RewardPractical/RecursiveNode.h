#ifndef RECURSIVENODE_H
#define RECURSIVENODE_H

#include <cstddef>
#include <iostream>

template <typename T>
class RecursiveNode {
private:
    RecursiveNode<T> *next;
    T data;

public:
    RecursiveNode(T data);
    T getData() const;
    RecursiveNode<T> *getNext() const;
    void setNext(RecursiveNode<T> *next);
    void print() {
        std::cout << data << "|";
    }
};

#endif