#include "Stack.h"
using namespace std;

template <class T>
Stack<T>::Stack()
{
	top = NULL;
}

template <class T>
Stack<T>::~Stack()
{
	while (top)
	{
		Node<T>* temp  = top;
		top = top->getNext();
		
		delete temp; 
		temp = NULL;
	}
}

template <class T>
void Stack<T>::push(T data)
{
	Node<T>* newnode = new Node<T>(data);// creates a newnode

	newnode->setNext(top); //old top is newnodes next
	top = newnode; //newnode is now top
}

template <class T>
Node<T>* Stack<T>::pop()
{
	if (!top) // if stack is empty top = NULL
		return NULL;

	//removing node from stack
	//don't deallocate it since you need to return it

	Node<T>* holder = top;
	top = top->getNext(); //set top is element one down

	return holder;
}

template <class T>
Node<T>* Stack<T>::getTop()
{
	return top; // this account for an empty stack since top is NULL
}

template <class T>
int Stack<T>::size()
{
	if (!top)
		return 0;

	int count = 0;
	Node<T>*nodeptr = top; 

	while(nodeptr)
	{
		count++;
		nodeptr = nodeptr->getNext();
	}

	return count;
}

template <class T>
bool Stack<T>::isEmpty()
{
	return (!top);
}

template <class T>
Stack<T>* Stack<T>::reverse()
{ //determine if its correct
	Stack<T>* NewStack = new Stack<T>();

	if (!top)
		return NewStack;

	Node<T>* nodeptr = top;

	//continuosly get top and then iterator to the the bottom and add it to the newstack

	while (nodeptr)
	{
		Node<T>* newnode = new Node<T>(nodeptr->getData());
		newnode->setNext(NewStack->top);
		NewStack->top = newnode;

		nodeptr = nodeptr->getNext();
	}

	return NewStack;
}

template <class T>
bool Stack<T>::contains(T data)
{
	if (!top)
		return false;

	Node<T>* nodeptr = top;

	while(nodeptr)
	{
		if (nodeptr->getData() == data)
			return true;

		nodeptr = nodeptr->getNext();
	}

	return false;
}