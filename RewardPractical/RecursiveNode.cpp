#ifndef RECURSIVENODE_CPP
#define RECURSIVENODE_CPP

#include "RecursiveNode.h"

template <typename T>
RecursiveNode<T>::RecursiveNode(T data) {
}

template <typename T>
T RecursiveNode<T>::getData() const {
    return NULL;
}

template <typename T>
RecursiveNode<T> *RecursiveNode<T>::getNext() const {
    return NULL;
}

template <typename T>
void RecursiveNode<T>::setNext(RecursiveNode<T> *next) {
}

#endif