#ifndef LINKED_H
#define LINKED_H
#include <stdexcept>
#include "Node.h"
#include "List.h"
#include <iostream>

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

    // inserting to empty list
    if (head == NULL && pos == 0)
      {
	head = insert;
	tail = insert;
	count++;
	return;
      }
    
    Node<T> *temp = head;
    //std::cout<< "created temp" << std::endl;
    //Node<T> *temp2 = head->getNext();

    //insert to beginning
    if (pos == 0)
      {
	insert->setNext(temp);
	temp->setPrev(insert);
	insert->setPrev(NULL);
	head = insert;
	count++;
	return;
      }

    //insert to end
    if (pos == count)
      {
    	tail->setNext(insert);
	insert->setPrev(tail);
	insert->setNext(NULL);
	tail = insert;
	count++;
    	return;
      }

    //insert anywhere else
    //std::cout<<"entering while loop" << std::endl;
    int i = 0;
    while (i <= pos)
      {
	if (i == pos && temp->getNext() != NULL)
	  {
	    /* insert->setNext(temp->getNext()); */
	    /* insert->setPrev(temp); */
	    /* temp->getNext()->setPrev(insert); */
	    /* temp->setNext(insert); */
	    /* temp->setNext(insert); */
	    /* insert->setPrev(temp); */
	    /* insert->setNext(temp2); */
	    /* temp2->setPrev(insert); */
	    temp->getPrev()->setNext(insert);
	    insert->setPrev(temp->getPrev());
	    insert->setNext(temp);
	    temp->setPrev(insert);
	    count++;
	    return;
	  }

	/* else if (i == pos && temp->getNext() == NULL) */
	/*   { */
	/*     temp->setNext(insert); */
	/*     insert->setPrev(temp); */
	/*     insert->setNext(NULL); */
	/*     tail = insert; */
	/*     count++; */
	/*     return; */
	/*   } */

	temp = temp->getNext();
	i++;
      }
      
    
    
  }

  /* Removes the element at position pos, shrinking the list by 1       
  *  pos must be between 0 and the current length of the list minus 1.
  */
  void remove(int pos)
  {
    if (pos < 0)
      {	
	std::cout << "Invalid position: less than 0" << std::endl;
	return;
      }

    if (pos >= count)
      {
	std::cout << "Invalid position: must be less than or equal to " << 
	  count - 1 << std::endl;
	return;
      }

    //empty list
    if (head == nullptr && tail == nullptr)
      return;

    
    //single entry
    if (count == 1)
      {
	
	Node<T> *temp = head;
	head = nullptr;
	tail = nullptr;
	delete temp;
	count--;
	return;
      }

    //removing positon 0
    else if (pos == 0)
      {
	Node<T> *temp = head;
	head = temp->getNext();
	head->setPrev(nullptr);
	delete temp;
	count--;
	return;
      }

    //removing last element
    else if (pos == count - 1)
      {
	Node<T> *temp = tail;
	tail = tail->getPrev();
	tail->setNext(nullptr);
	delete temp;
	count--;
	return;
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
	return;
      }

    return;
  }

  /* remove data by value */
  void remove(T item)
  {
    Node<T> *temp = head;
    if (head == nullptr)
      {
	std::cout << "Empty list" << std::endl;
	return;
      }
    while (temp != nullptr)
      {
	if (temp->getDataConst() == item)
	  {
	    //if linkedlist only has 1 item
	    if (count == 1)
	      {
		head = nullptr;
		tail = nullptr;
		delete temp;
		count--;
		return;
	      }
	    //if deleting at beginning
	    else if (temp == head)
	      {
		head = temp->getNext();
		head->setPrev(nullptr);
		delete temp;
		count--;
		return;
	      }
	    //if deleting at end
	    else if (temp->getNext() == nullptr)
	      {
		tail = tail->getPrev();
		tail->setNext(nullptr);
		delete temp;
		count--;
		return;
	      }
	    //deleting anywhere else
	    else
	      {
		temp->getPrev()->setNext(temp->getNext());
		temp->getNext()->setPrev(temp->getPrev());
		delete temp;
		count--;
		return;
	      }
	  }
	temp = temp->getNext();
      }

    //std::cout<<"Item not found."<<std::endl;
    return;
  }

  
  /* overwrites position pos in the list with item.
   *  does not change the length of the list.
   *  pos must be between 0 and the current length of the list minus 1.
   */
  void set(int pos, const T & item)
  {
     if (pos > count || pos < 0)
      {
	std::cout << "Invalid position. Must be between 0 and "
		  << count-1 << std::endl;
	return;
	//throw std::out_of_range("Position out of acceptable range.");
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
        throw std::out_of_range("Position out of acceptable range.");
      }

    Node<T> *temp = head;

    int i = 0;
    while (i <= pos)
      {
	if (i == pos)
	  {
	    //std::cout<< temp->getData() << std::endl;
	    return temp->getDataConst();
	  }

	temp = temp->getNext();
	i++;
      }

    return temp->getDataConst();
  }

  /* add a new Node to the end
   of the LinkedList */
  void addTail(T v)
  {
    Node<T> *endNode = new Node<T>(v);

    //empty list
    if (head == NULL && tail == NULL)
      {
	head = endNode;
	tail = endNode;
	endNode->setNext(NULL);
	endNode->setPrev(NULL);
	count++;
	return;
      }
    //non empty list. set current tail.next to link to new node
    //link new node.prev to current tail
    //update tail to be the end node
    else
      {
	tail->setNext(endNode);
	//	tail->getNext()->setPrev(tail);
	endNode->setPrev(tail);
	endNode->setNext(NULL);
	tail = tail->getNext();
	count++;
	return;
      }
  }

  void printList()
  {
    Node<T> *temp = head;
    if (head == nullptr)
      {
      std::cout << "empty list" <<std::endl;
      return;
      }
    while (temp != nullptr)
      {
	if (temp->getNext() != nullptr)
	  std::cout << temp->getData() << ", ";
	else if (temp->getNext() == nullptr)
	  std::cout << temp->getData() << std::endl;
	temp = temp->getNext();
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

