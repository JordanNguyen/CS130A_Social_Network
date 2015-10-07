#ifndef LINK_H
#define LINK_H

#include "NodeT.h"

template <class T>
class LinkedList {
	private:
		NodeT<T> *head;
		NodeT<T> #tail;
		int count;

	public:
		LinkedList<T>();
		~LinkedList<T>();

		void addTail(T v);
		void remove(int pos);
		int getCount();

}