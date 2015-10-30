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
  un->readFriends("friendList.txt", 0);
  un->readFriends("friendRequests.txt", 1);

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
    return checkRequest(un->getUserNode(username));
    }
  else
    {
      std::cout<<"Invalid username or password"<<std::endl;
      return start();
    }

}

void socialNetwork::checkRequest(Node<user>* usr)
{
  if (usr->getData().hasRequests())
  { 
    std::cout<<"You have a friend request!"<<std::endl;
    std::cout<<"Would you like to view your friend requests? (yes/no)"<<std::endl;
    string answer;

    do{
      std::cin >> answer;
      if (answer != "yes" && answer != "no")
        std::cout << "Please select either 'yes' or 'no'" << std::endl;
    } while (answer != "yes" && answer != "no");

    if (answer == "no")
      return userPage(usr);
    else if (answer == "yes")
      return friendMenu(usr);
  }

  else
    return userPage(usr);

}

void socialNetwork::userPage(Node<user>* usr)
{

  std::cout<<"Select an option"<<std::endl;
  std::cout<<"1.) View your wall"<<std::endl;
  std::cout<<"2.) Create new wall post"<<std::endl;
  std::cout<<"3.) View friends menu" << std::endl;
  std::cout<<"4.) Delete a wall post" << std::endl;
  std::cout<<"5.) Edit account information" << std::endl;
  std::cout<<"6.) Delete your account" <<std::endl;
  std::cout<<"7.) Logout"<<endl;

  int selection = 1;

  do{
    std::cin >> selection;
    if (selection < 1 || selection > 7)
      std::cout << "Invalid selection" << std::endl;
  } while (selection < 1 || selection > 7);

  if (selection == 1)
    return displayWall(usr);

  if (selection == 2)
    return newPost(usr);

  if (selection == 3)
    return friendMenu(usr);

  if(selection == 4)
    return deletePost(usr);

  if(selection == 5)
    return changeInfo(usr);

  if (selection == 6)
    return deleteUser(usr);

  if (selection == 7)
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
 
  int num;
  
  do{
    std::cout << "Enter the number corresponding to the wall post you wish to delete" << std::endl;
    std::cin >> num;
    if (num < 1 || num > usr->getData().getWall().getLL()->getCount())
      std::cout << "Invalid selection" << std::endl;
  } while (num < 1 || num > usr->getData().getWall().getLL()->getCount());

  usr->getDataToMod()->deleteWallPost(num - 1);
  std::cout << "Post successfully deleted!" << std::endl;
  return userPage(usr);
  

}

void socialNetwork::deleteUser(Node<user> *usr)
{
  std::cout << "Are you sure you would like to delete your account and all its info? (yes/no)" << std::endl;
  string answer;

  do{
    std::cin >> answer;
    if (answer != "yes" && answer != "no")
      std::cout << "Please select either 'yes' or 'no'" << std::endl;
  } while (answer != "yes" && answer != "no");

  if (answer == "no")
    return userPage(usr);

  else if (answer == "yes")
  {
    int index = un->getUserIndex(usr->getData().getUsername());
    un->getULL()->remove(index);
    std::cout << "Your account has been deleted." << std::endl;
    un->writeUserNetwork();
    return start();
  }


}

void socialNetwork::friendMenu(Node<user> *usr)
{
  std::cout << "Select an option" << std::endl;
  std::cout << "1.) Display friends" << std::endl;
  std::cout << "2.) Delete a friend" << std::endl;
  std::cout << "3.) View friend requests" <<std::endl;
  std::cout << "4.) Return to previous menu" <<std::endl;

  int selection = 1;
  
  do{
    std::cin >> selection;
    if (selection < 1 || selection > 4)
      std::cout << "Invalid selection" << std::endl;
  } while (selection < 1 || selection > 4);

  if (selection == 1)
  {
    std::cout << "FRIENDS" <<std::endl;
    std::cout << usr->getData().displayFriends()<<std::endl;
    return friendMenu(usr);
  }

  if (selection == 2)
    {
      return deleteFriend(usr);
    }

  if (selection == 3)
  {
    std::cout << "FRIEND REQUESTS" <<std::endl;
    std::cout << usr->getData().displayRequests()<<std::endl;
    return friendMenu(usr);
  }  

  if (selection == 4)
    {
      return userPage(usr);
    }
  
}

void socialNetwork::deleteFriend(Node<user> *usr)
{

  if (usr->getData().getFriends()->getHead() == NULL)
    {
      std::cout<<"You have no friends to delete." << std::endl;
      return userPage(usr);
    }
  
  std::cout << "Please enter the username (case sensitive) of the friend you wish to delete:" << std::endl;
  string frnd;
  std::cin >> frnd;

  un->removeFriend(usr->getData().getUsername(), frnd);

  return friendMenu(usr);

}
  

void socialNetwork::changeInfo(Node<user> *usr) {

  std::cout << "Select an option" << std::endl;
  
  std::cout << "1.) Change password" << std::endl;
  std::cout << "2.) Change birthday" << std::endl;
  std::cout << "3.) Change real name" << std::endl;
  std::cout << "4.) Return to previous menu" << std::endl;
  
  
  int selection = 1;

  do{
    std::cin >> selection;
    if (selection < 1 || selection > 4)
      std::cout << "Invalid selection" << std::endl;
  } while (selection < 1 || selection > 4);

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
	std::cout<<"The passwords you entered did not match. Please try again."<<std::endl;
    }
    while(newpass1 != newpass2);
    
    usr->getDataToMod()->setPassword(newpass1);
    std::cout << "Successfully changed your password!" << std::endl;
    return changeInfo(usr);
     
  }

  if (selection == 2) {

    string dob;
    std::cout << "Enter your birthday:";
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
