#ifndef LINK_H
#define LINK_H
#include "Node.h"

template <class T> class LinkedList {
	private:
		Node<T> *head;
		Node<T> *tail;
		int count;

	public:
		/* default constructor 
		initializes head and tail to NULL*/
		LinkedList()
		{
		head = NULL;
		tail = NULL;
		count = 0;
		}

		/* destructor iterates through whole 
		list and deletes each node */
		~LinkedList()
		{
		Node<T> *pOld;
  		Node<T> *p = head;
  		for(p = head; p != NULL; delete pOld)
    		{
    			//std::cout << p->getData() << " destroyed" << std::endl;
      			pOld = p;
      			p = p->getNext();
    		}
    	//std::cout << "LinkedList destroyed" << std::endl;	
		}

		/* add a new Node to the end
		of the LinkedList */
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

		/* removes the node specified by 
		input position 'pos.' remove() starts 
		counting the first node as index 0, 
		followed by 1, etc */
		void remove(int pos)
		{
			//empty list
			if (head == NULL && tail == NULL)
				return;

			//single entry
			else if (head == tail)
			{
				delete head;
				count--;
			}

			//if pos is invalid
			else if (pos < 0)
			{	
				std::cout << "Invalid position: less than 0" << std::endl;
			}

			else if (pos >= count)
			{
				std::cout << "Invalid position: greater than or equal to " << 
				this->getCount() << std::endl;
			}

			//removing positon 0
			else if (pos == 0)
			{
				Node<T> *temp = head;
				head = head->getNext();
				delete temp;
				count--;
				return;
			}

			//removing last element
			else if (pos == count - 1)
			{
				Node<T> *temp = tail;
				tail = tail->getPrev();
				delete temp;
				count--;
			}

			else
			{
				Node<T> *temp = head;
				//move temp to node removing
				for(int i = 0; i < pos; i++)
					temp = temp->getNext();
				//link the two nodes surrounding temp
				temp->getPrev()->setNext(temp->getNext());
				temp->getNext()->setPrev(temp->getPrev());
				count--;
			}

			return;
		}

		/* this functions does
		I don't know... Iterates
		through all nodes for now */
		void iterateAll()
		{
			Node<T> *temp = head;
			while (temp->getNext() != NULL)
				temp=temp->getNext();
			return;
		}


		int getCount()	 { return count; }
		Node<T> *getHead()  { return head; }
		Node<T> *getTail()  { return tail; }

};



#endif


