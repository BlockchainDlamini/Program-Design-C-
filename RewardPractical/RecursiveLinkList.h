#ifndef RECURSIVELINKLIST_H
#define RECURSIVELINKLIST_H

#include "RecursiveNode.cpp"

#include <cstddef>

template <typename T>
class RecursiveLinkList {
private:
    RecursiveNode<T> *head;
    bool insert(T data, int pos, RecursiveNode<T> *curr, RecursiveNode<T> *prev);
    RecursiveNode<T> *remove(int pos, RecursiveNode<T> *curr, RecursiveNode<T> *prev);
    RecursiveNode<T> *get(int pos, RecursiveNode<T> *curr);
    bool contains(T data, RecursiveNode<T> *curr);
    int size(RecursiveNode<T> *curr);
    void printInOrder(RecursiveNode<T> *curr);
    void printRevOrder(RecursiveNode<T> *curr);
    RecursiveLinkList<T> *clone(RecursiveLinkList<T> *result, RecursiveNode<T> *curr);
    void clearList(RecursiveNode<T> *curr);

public:
    RecursiveLinkList();
    ~RecursiveLinkList();
    bool insert(T data, int pos);
    RecursiveNode<T> *remove(int pos);
    RecursiveNode<T> *get(int pos);
    bool contains(T data);
    int size();
    void printInOrder();
    void printRevOrder();
    RecursiveLinkList<T> *clone();
};

#endif