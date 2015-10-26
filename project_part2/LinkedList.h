#ifndef LINKED_H
#define LINKED_H
#include "Node.h"
#include "List.h"

template <class T>
class LinkedList: public List<T> {

 private:
  
  Node<T> *head;
  Node<T> *tail;
  int count;

  
 public:

  /*default constructor intializes
    head and tail to NULL */
  LinkedList()
    {
      head = NULL;
      tail = NULL;
      count = 0;
    }

  /* destructor iterates through wholl
     list and deletes each node */
  ~LinkedList()
    {
      Node<T> *pOld;
      Node<T> *p = head;
      for (p = head; p != NULL; delete pOld)
	{
	  pOld = p;
	  p = p->getNext();
	}
    }

  /* Inserts the item right before position pos, growing the list by 1
   *  pos must be between 0 and the current length of the list.
   */
  void insert(int pos, const T & item)
  {
    if (pos > count || pos < 0)
      {
	std::cout << "Invalid position. Must be between 0 and "
		  << count << std::endl;
	return;
      }

    Node<T> *insert = new Node<T>(item);
    Node<T> *temp = head;
    Node<T> *temp2 = head->getNext();

    if (head == NULL && pos == 0)
      {
	head = insert;
	tail = insert;
	count++;
      }

    if (pos == 0)
      {
	insert->setNext(temp);
	temp->setPrev(insert);
	insert->setPrev(NULL);
	head = insert;
	count++;
	return;
      }

    if (pos == 1)
      {
	temp->setNext(insert);
	insert->setPrev(temp);
	insert->setNext(temp2);
	temp2->setPrev(insert);
	count++;
	return;
      }

    int i = 1;
    while (i <= pos)
      {
	if (i == pos)
	  {
	    temp->setNext(insert);
	    insert->setPrev(temp);
	    insert->setNext(temp2);
	    temp2->setPrev(insert);
	    count++;
	    return;
	  }

	if (temp2 == NULL)
	  {
	    temp->setNext(insert);
	    insert->setPrev(temp);
	    insert->setNext(NULL);
	    tail = insert;
	    count++;
	    return;
	  }

	temp = temp->getNext();
	temp2 = temp2->getNext();
	i++;
      }
    
  }

  /* Removes the element at position pos, shrinking the list by 1       
  *  pos must be between 0 and the current length of the list minus 1.
  */
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
				delete temp;
				count--;
			}

			return;
  }

  
  /* overwrites position pos in the list with item.
   *  does not change the length of the list.
   *  pos must be between 0 and the current length of the list minus 1.
   */
  void set(int pos, const T & item)
  {
     if (pos > count-1 || pos < 0)
      {
	std::cout << "Invalid position. Must be between 0 and "
		  << count - 1 << std::endl;
	return;
      }

    if (head == NULL && pos == 0)
      {
	std::cout << "Empty list, nothing to set" << std::endl;
	return;
      }

    Node<T> *temp = head;

    int i = 0;
    while (i <= pos)
      {
	if (i == pos)
	  {
	    temp->setValue(item);
	  }

	temp = temp->getNext();
	i++;
      }
  }

  /* returns the item at position pos, not changing the list.
   *  pos must be between 0 and the current length of the list minus 1.	
   */
  T const & get(int pos) const
  {
     if (pos > count-1 || pos < 0)
      {
	std::cout << "Invalid position. Must be between 0 and "
		  << count - 1 << std::endl;
	return 0;
      }

    if (head == NULL && pos == 0)
      {
	std::cout << "Empty list, nothing to get" << std::endl;
	return 0;
      }

    Node<T> *temp = head;

    int i = 0;
    while (i <= pos)
      {
	if (i == pos)
	  {
	    return temp->getData();
	  }

	temp = temp->getNext();
	i++;
      }
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


  void addCount()          { count++; }
  void subCount()          { count--; }
  int getCount()           { return count; }
  Node<T> *getHead()       { return head; }
  Node<T> *getTail()       { return tail; }
  void setHead(Node<T> *h) { head = h; }
  void setTail(Node<T> *t) { tail = t; }


};

#endif

