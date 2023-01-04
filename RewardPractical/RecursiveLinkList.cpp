#ifndef RECURSIVELINKLIST_CPP
#define RECURSIVELINKLIST_CPP

#include "RecursiveLinkList.h"

template <typename T>
RecursiveLinkList<T>::RecursiveLinkList() {
}

template <typename T>
RecursiveLinkList<T>::~RecursiveLinkList() {
}

template <typename T>
bool RecursiveLinkList<T>::insert(T data, int pos) {
    return false;
}

template <typename T>
bool RecursiveLinkList<T>::insert(T data, int pos, RecursiveNode<T> *curr, RecursiveNode<T> *prev) {
    return false;
}

template <typename T>
RecursiveNode<T> *RecursiveLinkList<T>::remove(int pos) {
    return NULL;
}

template <typename T>
RecursiveNode<T> *RecursiveLinkList<T>::remove(int pos, RecursiveNode<T> *curr, RecursiveNode<T> *prev) {
    return NULL;
}

template <typename T>
RecursiveNode<T> *RecursiveLinkList<T>::get(int pos) {
    return NULL;
}

template <typename T>
RecursiveNode<T> *RecursiveLinkList<T>::get(int pos, RecursiveNode<T> *curr) {
    return NULL;
}

template <typename T>
bool RecursiveLinkList<T>::contains(T data) {
    return false;
}

template <typename T>
bool RecursiveLinkList<T>::contains(T data, RecursiveNode<T> *curr) {
    return false;
}

template <typename T>
int RecursiveLinkList<T>::size() {
    return -1;
}

template <typename T>
int RecursiveLinkList<T>::size(RecursiveNode<T> *curr) {
    return -1;
}

template <typename T>
void RecursiveLinkList<T>::printInOrder() {
}

template <typename T>
void RecursiveLinkList<T>::printInOrder(RecursiveNode<T> *curr) {
}

template <typename T>
void RecursiveLinkList<T>::printRevOrder() {
}

template <typename T>
void RecursiveLinkList<T>::printRevOrder(RecursiveNode<T> *curr) {
}

template <typename T>
RecursiveLinkList<T> *RecursiveLinkList<T>::clone() {
    return NULL;
}

template <typename T>
RecursiveLinkList<T> *RecursiveLinkList<T>::clone(RecursiveLinkList<T> *result, RecursiveNode<T> *curr) {
    return NULL;
}

template <typename T>
void RecursiveLinkList<T>::clearList(RecursiveNode<T> *curr) {
}

#endif