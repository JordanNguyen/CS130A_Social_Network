#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	NodeT<T> *pOld;
  	NodeT<T> *p = head;
  	for(p = head; p != NULL; delete pOld)
    {
      pOld = p;
      p = p->getNext();
    }
}

template <typename T>
void LinkedList<T>::addTail(T v)
{
	NodeT<T> *l = new NodeT<T>(v);

	if (head == NULL)
	{
		head = l;
		tail = l;
		return;
	}

	else
	{
		NodeT<T> *l2;
		for (l2 = head; l2->getNext() != NULL; l2 = l2->getNext();)
			;
		l2->setNext(l);
		tail = l;
		tail->setNext(NULL);
		count++;
		return;
	}
}

template <typename T>
int LinkedList<T>::getCount()
{
	return count;
}

template <typename T>
void LinkedList<T>::remove (int pos)
{
	//empty list
	if (head == NULL && tail == NULL)
		return;

	//single list
	if (head == tail)
	{
		delete head;
		return;
	}

	//if pos is invalid
	if (pos < 0)
	{
		std::cout << "Invalid position" << std::endl;
		return;
	}

	if (pos >= count)
	{
		std::cout << "Invalid position" << std::endl;
		return;
	}

	// removing position 0
	if (pos == 0)
	{
		NodeT<T> *temp = head;
		head = head->getNext();
		delete temp;
		count--;
	}
	//need to implement prev stuff
	if (pos == count - 1)
	{
		NodeT<T> *temp = tail;
		tail = tail->getPrev();
		delete temp;
		count--;	
	}

	else //WIP
	{
		NodeT<T> *temp = head;
		NodeT<T> *temp2 = head->getNext();
		for(int i = 0; i < pos; i++)
		{
			temp = temp->getNext();
			temp2 = temp2->getNext();
		}
	}





}

