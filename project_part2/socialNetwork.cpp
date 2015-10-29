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
  un->readFriends("friendList.txt");

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
  std::cout<<"3.) Delete a wall post" << std::endl;
  std::cout<<"4.) Change account information" << std::endl;
  std::cout<<"5.) View friends list" << std::endl;
  std::cout<<"6.) Logout"<<endl;

  int selection = 1;

  do{
    std::cin >> selection;
    if (selection < 1 && selection > 5)
      std::cout << "Invalid selection" << std::endl;
  } while (selection < 1 && selection > 5);

  if (selection == 1)
    return displayWall(usr);

  if (selection == 2)
    return newPost(usr);

  if(selection == 3)
    return deletePost(usr);

  if(selection == 4)
    return changeInfo(usr);

  if (selection == 5)
    return displayFriends(usr);
  
  if (selection == 6)
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

void socialNetwork::deletePost(Node<user> *usr)
{

  std::cout << "Enter the number corresponding to the wallpost you wish to delete" << std::endl;

  int num;
  std::cin >> num;
  usr->getDataToMod()->deleteWallPost(num - 1);
  std::cout << "Post successfully deleted!" << std::endl;
  return userPage(usr);
  

}

void socialNetwork::displayFriends(Node<user> *usr)
{
  std::cout << "FRIENDS" <<std::endl;
  std::cout << usr->getData().displayFriends();
  return userPage(usr);
}
void socialNetwork::changeInfo(Node<user> *usr) {
  
  std::cout << "1.) Change password" << std::endl;
  std::cout << "2.) Change birthday" << std::endl;
  std::cout << "3.) Change real name" << std::endl;
  std::cout << "4.) Return to previous menu" << std::endl;
  
  
  int selection = 1;

  do{
    std::cin >> selection;
    if (selection < 1 && selection > 4)
      std::cout << "Invalid selection" << std::endl;
  } while (selection < 1 && selection > 4);

  if (selection == 1) {

    string pass;
    std::cout << "Enter current password:";
    std::cin >> pass;
    if (usr->getData().getPassword() != pass) {
       std::cout<<"Incorrect password"<<std::endl;
       return changeInfo(usr);
    }
   
    string newpass1;
    string newpass2;

    do{
      std::cout << "Enter a new password:";
      std::cin >> newpass1;
      std::cout << "Confirm your new password:";
      std::cin >> newpass2;
      if (newpass1 != newpass2)
	std::cout<<"Conflicting entries, please try again"<<std::endl;
    }
    while(newpass1 != newpass2);
    
    usr->getDataToMod()->setPassword(newpass1);
    std::cout << "Successfully changed your password!" << std::endl;
    return changeInfo(usr);
     
  }

  if (selection == 2) {

    string dob;
    std::cout << "Enter new birthday (mm/dd/yyyy):";
    std::cin >> dob;
    usr->getDataToMod()->setDOB(dob);
    std::cout << "Successfully changed your birthday!" << std::endl;
    return changeInfo(usr);

  }



  if (selection == 3) {
    
    string realn;
    std::cout << "Enter new real name:";
    std::cin >> realn;
    usr->getDataToMod()->setRealName(realn);
    std::cout << "Successfully changed your real name!" << std::endl;
    return changeInfo(usr);
    
  }


  
  if(selection == 4)
    return userPage(usr);


  
}
