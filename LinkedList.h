#ifndef LINK_H
#define LINK_H
#include "Node.h"

template <class T> class LinkedList {
	private:
		Node<T> *head;
		Node<T> *tail;
		int count;

	public:
		LinkedList()
		{
		head = NULL;
		tail = NULL;
		count = 0;
		}

		~LinkedList()
		{
		Node<T> *pOld;
  		Node<T> *p = head;
  		for(p = head; p != NULL; delete pOld)
    		{
      			pOld = p;
      			p = p->getNext();
    		}
		}

		void addTail(T v)
		{
			Node<T> *endNode = new Node<T>(v);

			//empty list
			if (head == NULL)
			{
				head = endNode;
				tail = endNode;
				count++;
				return;
			}

			//non empty list. set current tail.next to link to new node
			//link new node.prev to current tail
			//update tail to be the end node
			else
			{
				tail->setNext(endNode);
				tail->getNext()->setPrev(tail);
				tail = tail->getNext();
				count++;
				return;
			}
		}

		//void remove(int pos);
		int getCount()	 { return count; }

		Node<T> *getHead()  { return head; }
		Node<T> *getTail()  { return tail; }

};



#endif


