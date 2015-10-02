#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "NodeT.h"

//int NodeT::count=0;

/* This is the constructor that will most often be used.
 */
NodeT::NodeT(T d)
{
	data = d;
	prev = NULL;
	next = NULL;
	count++;
	//cout << "Node Created!" << endl;
}

/* here is another constructor in case someone wants to make the 
 * link before they know what value it will have.
 * You can have multiple constructors as long as each has a different
 * set of input parameter types.  The names don't matter.
 */
NodeT::NodeT()
{
	data = 0;
	prev = NULL;
	next = NULL;
	count++;
}

NodeT::~NodeT()
{
	count--;
}

T NodeT::getCount()
{
	return count;
}

void NodeT::setValue(T v)
{
	data = v;
}
void NodeT::setNext(NodeT *t)
{
	next = t;
}

T NodeT::getValue()
{
	return value;
}

NodeT* NodeT::getPrev()
{
	return prev;
}

NodeT* NodeT::getNext()
{
	return next;
}

void NodeT::printNodeT()
{
	cout << data << endl;
}

