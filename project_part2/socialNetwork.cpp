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

void socialNetwork::welcome()
{
  std::cout << "Welcome to your social network!" << std::endl;
  return start();
}

void socialNetwork::start()
{

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
  
  // if (selection == 1)
  //   return createNewUser();
  // if (selection == 2)
  //   return login();
  // if (selection == 3)
  //   std::cout <<"Goodbye!"<<endl;
  //   return;

  //std:: cin>> selection;
  switch(selection){
  case 1:
    return createNewUser();
    break;
  case 2:
    return login();
    break;
  case 3:
    std::cout<<"Goodbye!"<<endl;
    return;
  }
    
  
}


void socialNetwork::createNewUser()
{
  std::cout << "Enter a username:" << std::endl;
  string username;
  std::cin >> username;
  
  std::cout << "Enter a password:" << std::endl;
  string password;
  std::cin >> password;
  
  std::cout << "Enter your real name:" << std::endl;
  string realname;
  std::getline(std::cin, realname);
  std::getline(std::cin, realname);
  
  std::cout << "Enter your birthday:" << std::endl;
  string dob;
  std::getline(std::cin, dob);

  if (!(un->checkUsername(username)))
  {
    user newUser(username,password,realname,dob);
    un->addUser(newUser);
    un->writeUserNetwork();
    std::cout<<"New user successfully created!"<<std::endl;
  }

  else
    std::cout<<"Username is already taken."<<std::endl;

  return start();

}

void socialNetwork::login()
{
  std::cout<<"Enter your username:"<<std::endl;
  string username;
  std::cin>>username;
  
  std::cout<<"Enter your password:"<<std::endl;
  string password;
  std::cin>>password;

  if (un->checkLogin(username, password))
    {
    std::cout<<"Login Successful"<<std::endl;
    return userPage(un->getUserNode(username));
    }
  else
    {
      std::cout<<"Invalid username or password"<<std::endl;
      return start();
    }

}

void socialNetwork::userPage(Node<user>* usr)
{
  std::cout<<"Select an option"<<std::endl;
  std::cout<<"1.) Display entire wall"<<std::endl;
  std::cout<<"2.) Create new wall post"<<std::endl;
  std::cout<<"3.) Logout"<<endl;

  int selection = 1;

  do{
    std::cin >> selection;
    if (selection < 1 && selection > 3)
      std::cout << "Invalid selection" << std::endl;
  } while (selection < 1 && selection > 3);

  if (selection == 1)
    return displayWall(usr);

  if (selection == 2)
    return newPost(usr);
  
  if (selection == 3)
    {
      std::cout<<"You have logged out."<<std::endl;
      un->writeUserNetwork();
      return start();
    }
    
}

void socialNetwork::displayWall(Node<user>* usr)
{
  std::cout<<usr->getData().getWall().WallToString();
  return userPage(usr);
}
  

void socialNetwork::newPost(Node<user> *usr)
{

  std::cout << "Enter your post: ";
  string text;
  std::getline(std::cin, text);
  std::getline(std::cin, text);

  std::cout << "Where are you posting from?" << std::endl;
  string loc;
  std::getline(std::cin, loc);
  // std::getline(std::cin, loc);

  wallPost npost(text,loc);
  usr->getData().getWall().newPost(npost);
  std::cout << "Post successful!" << std::endl;

  return userPage(usr);
  
}
