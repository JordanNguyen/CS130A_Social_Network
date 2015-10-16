#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <fstream>
#include "socialNetwork.h"

socialNetwork::socialNetwork()
{
  //instantiate new instance of usernetwork
  un = new userNetwork();
  //fill up usernetwork from file
  un->readUsers("userNetworkInput.txt");

}

socialNetwork::~socialNetwork()
{
  delete un;
}

void socialNetwork::start()
{
  std::cout << "Welcome to your social network!" << std::endl;
  std::cout << "Please choose an option: " << std::endl;
  std::cout << "1.) Create a new user" << std::endl;
  std::cout << "2.) Log in" << std::endl;
  std::cout << "3.) Quit program" << std::endl;

  int selection = 1;

  do{
    std::cin >> selection;
    if (selection != 1 && selection != 2 && selection !=3)
      std::cout << "Invalid selection" << std::endl;
  } while (selection != 1 && selection != 2 && selection !=3);
  
  if (selection == 1)
    return createNewUser();
}

void socialNetwork::createNewUser()
{
  std::cout << "Enter a username:" << std::endl;
  string username;
  std::cin >> username;
  if (checkUsername(username))
    {
      std::cout<<"Available"<<endl;
      std::cout<<"Username taken"<<endl;
    }
  return;

}

bool socialNetwork::checkUsername(string username)
{
  //use to iterate through usernetwork
  Node<user> *temp = new Node<user>;
  temp = un->getULL()->getHead();

  while (temp != NULL)
    {
      if (username == temp->getData().getUsername())
	return false;
    }

  return true;
}
