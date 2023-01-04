#include "SortList.h"
//#include <iostream>
using namespace std;


template <class T>
SortList<T>::SortList(bool asc) : ascending(asc)
{
	head = NULL;
	tail = NULL;
}

template <class T>
void SortList<T>::add(SortNode<T>* a)
{
	if (!head)
	{
		head = a;
		tail = a;
	}
	else
	{ 
		SortNode<T>* nodePrt = head;

		while (nodePrt->next) // Iterate through the entire
			nodePrt = nodePrt->next;

		// This still applies even if there is only one element in the list

		nodePrt->next = a;
		a->prev = nodePrt;
		a->next = NULL;
		tail = a;
	}
}

template <class T>
SortNode<T>* SortList<T>::remove(T val)
{
	//Assuming that you can not remove for a list with one element as indicated by the slides

	if (!head)// if the list is empty
		return NULL;

	SortNode<T>* node = head;

	if (head == tail)
	{// If there is one element in the list
		head = NULL;
		tail = NULL;

		return node;
	} 
	

	while (node->next && node->getValue() != val)// Iterate through the list if there are still elements in the list and value has not been found yet
		node = node->next;

	if (node->next == NULL && node->getValue() != val) // If the value has not been found after iteration of the entire list
		return NULL;

	if (!node->prev)
	{ // if the found node is the first node
		head = node->next; // Head is now the second node
		node->next->prev = NULL; //second node previous is now NULL
		node->next = NULL;

		return node;
	} 

		//Unlink the found node from the list
		//If the node is found somewhere inside the list

	if (node->next != NULL && node->prev != NULL)
	{ 		
		node->prev->next = node->next; 
		node->next->prev = node->prev; 
		node->next = NULL;
		node->prev = NULL;

		return node;
	}

	//If the required element is at the end of the list

	if (!node->next)
	{
		tail = node->prev; // set tail to be the node prior to it
		node->prev->next = NULL; // set the node prior to its next is NULL
		node->prev = NULL; // unlink the node form the list 

		return node;
	}

	return NULL; // For other unfactor cases// maybe remove this return statement consider
}

template <class T>
void SortList<T>::setAsc(bool a)
{
	bool wall = false;
	
	if (wall)
	{
		if (head->next != NULL && head != tail)
		{ // if it not already in the required order and the list is not empty and the list has atleast more than one element 


			SortNode<T>* temp; // create a temp node to hold the pointers to be swapped
			SortNode<T>* node = NULL; // being the interation from the first node

			node = head;
			
			while (node)
			{ // while its not null
				if (node != head || node != temp)
				{
				temp = node->prev;
				node->prev = node->next;	
				node->next = temp;
				node = node->prev;
				}

			}

			temp = tail;
			tail = head;
			head = temp;
			ascending = a;
		}
	}
}

template <class T>
SortNode<T>* SortList<T>::getHead()
{
	return head;
}


template <class T>
string SortList<T>::print()
{
	string finalstring = "";

	if (!head) // the list is empty
		return finalstring;

	if (head == tail) // there is one element in the list
		return head->print();

	SortNode<T>* nodePrt = head;

	while (nodePrt->next)
	{
		finalstring += nodePrt->print() + ",";
		nodePrt = nodePrt->next;
	}

	finalstring += nodePrt->print();

	return finalstring;
}

template <class T>
void SortList<T>::sort()
{
	// Phase 1
	//create an array to hold on the values in the list
	//sort that array such that it removes the first item in the list as we iterate 
	//add the remove nodes to the temp list


	//Phase 2 
	//add all the items for the temp list to the original list

	if (head && head != tail)
	{ //item in the list and its not a 1 itemed list

		//iterate through the list to determine the size of the array

		int count = 1;
		SortNode<T>* node = this->head;

		while (node->next)
		{
			count++;
			node = node->next;
		}

		//cout<< "value of count "<< count<<endl;

		T arrayvals[count];

		int k = 0;
		node = head;
		T tempval;
		SortList<T>*templist = new SortList<T>(ascending);
		SortNode<T>* removednode;


		while (k < count)
		{ // Populate the array
			arrayvals[k] = node->getValue();
			k++;
			node = node->next;
		}

		//Soft the array according to the ascending variable

		if (ascending)
		{ //sort it in ascending order

			for (int i = 0; i < count - 1; i++)
				for (int j = 0; j < count - i - 1; j++)
					if (arrayvals[j] > arrayvals[j + 1])
					{
						tempval = arrayvals[j];
						arrayvals[j] = arrayvals[j + 1];
						arrayvals[j + 1] = tempval;
					}

			for (int i = 0; i < count; i++)
			{ //removing the items in the list and add them accordingly to the temp list
				removednode = this->remove(arrayvals[i]);
				templist->add(removednode);
			}
		}
		else
		{
			for (int i = 0; i < count - 1; i++)
				for (int j = 0; j < count - i - 1; j++)
					if (arrayvals[j] < arrayvals[j + 1])
					{
						tempval = arrayvals[j];
						arrayvals[j] = arrayvals[j + 1];
						arrayvals[j + 1] = tempval;
					}

			for (int i = 0; i < count; i++)
			{
				removednode = this->remove(arrayvals[i]);
				templist->add(removednode);
			}
		}

		//Apparently the equal operator has to be overloaded for this to work even though these are pointer *rolling my eyes emoji*
		//this = templist;
		//which head does this refer to templists of this'

		node = templist->head;
		SortNode<T>* holdernext = NULL;
		k = 0;

		while (k < count)
		{
			holdernext = node->next;
			this->add(node);
			node = holdernext;
			k++;
		}

		node = this->head;
	}
}

