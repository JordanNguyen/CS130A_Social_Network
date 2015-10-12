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

}

void userNetwork::addUser(user u);
{
  users->addTail(u);
}

void userNetwork::deleteUser(string t) {
  Node<user> *temp = users->getHead();
  //temp->getData()->getUsername();

  //empty list
  if (users->getHead() == NULL && users->getTail() == NULL)
    return;
  //single entry
  
