#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "NodeT.h"

//int NodeT::count=0;

/* This is the constructor that will most often be used.
 */
template <typename T>
NodeT<T>::NodeT(T d)
{
	data = d;
	prev = NULL;
	next = NULL;
	//count++;
	std::cout << "Node Created!" << std::endl;
}

/* here is another constructor in case someone wants to make the 
 * link before they know what value it will have.
 * You can have multiple constructors as long as each has a different
 * set of input parameter types.  The names don't matter.
 */
template <typename T>
NodeT<T>::NodeT()
{
	data = 0;
	prev = NULL;
	next = NULL;
	//count++;
}

template <typename T>
NodeT<T>::~NodeT()
{
	//count--;
}

//T NodeT<T>::getCount()
//{
//	return count;
//}

template <typename T>
void NodeT<T>::setValue(T v)
{
	data = v;
}

template <typename T>
void NodeT<T>::setNext(NodeT *t)
{
	next = t;
}

// template <typename T>
// T NodeT<T>::getData()
// {
// 	return data;
// }

// template <typename T>
// NodeT<T>* NodeT<T>::getPrev()
// {
// 	return prev;
// }

// template <typename T>
// NodeT<T>* NodeT<T>::getNext()
// {
// 	return next;
// }

template <typename T>
void NodeT<T>::printNodeT()
{
	std::cout << data << std::endl;
}

