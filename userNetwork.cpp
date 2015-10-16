#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include "userNetwork.h"
using namespace std;

userNetwork::userNetwork()
{
  users = new LinkedList<user>;
}

userNetwork::~userNetwork()
{
  delete users;
}

void userNetwork::addUser(user u)
{
  users->addTail(u);
}

void userNetwork::deleteUser(string t) 
{
 	
  
 	//empty list
  	if (users->getHead() == NULL && users->getTail() == NULL)
    	return;
  	//single entry
  	if (users->getHead() == users->getTail() && users->getHead()->getData().getUsername() == t)
  	{
  		//Node<user> *temp = users->getHead();
  		//delete temp;
  		users->setHead(NULL);
  		users->setTail(NULL);
  		return;
  	}

  	//delete head
  	if (users->getHead()->getData().getUsername() == t)
  	{
  		Node<user> *temp = users->getHead();
  		users->setHead(users->getHead()->getNext());
  		delete temp;
  		return;
  	}

  	//delete tail
  	if (users->getTail()->getData().getUsername() == t)
  	{
  		Node<user> *temp = users->getTail();
  		users->setTail(users->getTail()->getPrev());
  		users->getTail()->setNext(NULL);
  		delete temp;
  		return;
  	}

  	//anything else
  	else
  	{
  		Node<user> *temp = users->getHead();
  		while (temp != NULL)
  		{
  			if (temp->getData().getUsername() == t)
  			{
  				temp->getPrev()->setNext(temp->getNext());
  				temp->getNext()->setPrev(temp->getPrev());
  				delete temp;
  			}
  			temp = temp->getNext();
  		}
  	}

  	return;
}

void userNetwork::printUsernames()
{
	if (users->getHead() == NULL)
	{
		cout << "empty user network" << endl;
		return;
	}

	Node<user> *temp = users->getHead();
	while (temp != NULL)
	{
		cout << temp->getData().getUsername() << endl;
		temp = temp->getNext();
	}
}

LinkedList<user>* userNetwork::getULL()
{
	return users;
}




