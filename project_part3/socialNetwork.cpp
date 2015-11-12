#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <algorithm>
#include "socialNetwork.h"

socialNetwork::socialNetwork()
{
  //instantiate new instance of usernetwork
  un = new userNetwork();
  //fill up usernetwork from files
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
  //std::cout << "#     #" << std::endl;                                           
  std::cout << "#  #  # ###### #       ####   ####  #    # ######" << std::endl; 
  std::cout << "#  #  # #      #      #    # #    # ##  ## #"      << std::endl;
  std::cout << "#  #  # #####  #      #      #    # # ## # #####"  << std::endl;
  std::cout << "#  #  # #      #      #      #    # #    # #"      << std::endl;
  std::cout << "#  #  # #      #      #    # #    # #    # #"      << std::endl;
  std::cout << " ## ##  ###### ######  ####   ####  #    # ######" << std::endl;

  std::cout << "              TO YOUR SOCIAL NETWORK!            " << std::endl;
  std::cout << "*************************************************" << std::endl;

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
     if (!cin)
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    un->writeFriends(0);
    un->writeFriends(1);
    std::cout << "*******************************" << std::endl;
    std::cout<<"New user successfully created!"<<std::endl;
    std::cout << "*******************************" << std::endl;

  }

  else {
    std::cout << "*******************************" << std::endl;
    std::cout<<"Username is already taken."<<std::endl;
    std::cout << "*******************************" << std::endl;

  }
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
    std::cout << "*******************************" << std::endl;
    std::cout<<"Login Successful"<<std::endl;
    return checkRequest(un->getUserNode(username));
    }
  else
    {
      std::cout << "*******************************" << std::endl;
      std::cout<<"Invalid username or password"<<std::endl;
      return start();
    }

}

void socialNetwork::checkRequest(Node<user>* usr)
{
  if (usr->getData().hasRequests())
  {
    std::cout << "*******************************" << std::endl;
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
    {
    std::cout << "*******************************" << std::endl;
    std::cout << "FRIEND REQUESTS" <<std::endl;
    std::cout << usr->getData().displayRequests()<<std::endl;
    std::cout << "*******************************" << std::endl;
    return friendMenu(usr);
    }
      
  }

  else 
    return userPage(usr);

}

void socialNetwork::userPage(Node<user>* usr)
{
  std::cout << "*******************************" << std::endl;
  std::cout<<"Select an option"<<std::endl;
  std::cout<<"1.) View your wall"<<std::endl;
  std::cout<<"2.) Create new wall post"<<std::endl;
  std::cout<<"3.) View friends menu" << std::endl;
  std::cout<<"4.) Search for users" << std::endl;
  std::cout<<"5.) Delete a wall post" << std::endl;
  std::cout<<"6.) Edit account information" << std::endl;
  std::cout<<"7.) Delete your account" <<std::endl;
  std::cout<<"8.) Logout"<<endl;

  int selection = 1;

  do{
    std::cin >> selection;
    if (!cin)
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (selection < 1 || selection > 8)
      std::cout << "Invalid selection" << std::endl;
  } while (selection < 1 || selection > 8);

  if (selection == 1)
    return displayWall(usr);

  if (selection == 2)
    return newPost(usr);

  if (selection == 3) {
    std::cout << "*******************************" << std::endl;
    return friendMenu(usr);
  }
  if (selection == 4)
    return searchUser(usr);

  if (selection == 5)
    return deletePost(usr);

  if (selection == 6)
    return changeInfo(usr);

  if (selection == 7)
    return deleteUser(usr);

  if (selection == 8)
    {
      std::cout << "*******************************" << std::endl;
      std::cout<<"You have logged out."<<std::endl;
      std::cout << "*******************************" << std::endl;
      un->writeUserNetwork();
      un->writeFriends(0);
      un->writeFriends(1);
      return start();
    }
    
}

void socialNetwork::displayWall(Node<user>* usr)
{
  std::cout << "*******************************" << std::endl;
  std::cout<<usr->getData().getWall().WallToString();
  return userPage(usr);
}


void socialNetwork::newPost(Node<user> *usr)
{

  std::cout << "Enter your post: ";
  string text;
  //std::getline(std::cin, text);
  std::getline(std::cin, text);

  std::cout << "Where are you posting from?" << std::endl;
  string loc;
  std::getline(std::cin, loc);
  // std::getline(std::cin, loc);

  wallPost npost(text,loc);
  usr->getData().getWall().newPost(npost);
  std::cout << "*******************************" << std::endl;
  std::cout << "Post successful!" << std::endl;

  return userPage(usr);
  
}

void socialNetwork::deletePost(Node<user> *usr)
{
 
  int num;

  if (usr->getData().getWall().getHead() == NULL)
  {
    std::cout << "*******************************" << std::endl;
    std::cout << "Your wall is empty." <<std::endl;
    return userPage(usr);
  }
  
  do{
    std::cout << "Enter the number corresponding to the wall post you wish to delete" << std::endl;
    std::cin >> num;
    if (!cin)
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (num < 1 || num > usr->getData().getWall().getLL()->getCount())
      std::cout << "Invalid selection" << std::endl;
  } while (num < 1 || num > usr->getData().getWall().getLL()->getCount());

  usr->getDataToMod()->deleteWallPost(num - 1);
  std::cout << "*******************************" << std::endl;
  std::cout << "Post successfully deleted!" << std::endl;
  return userPage(usr);
  

}

void socialNetwork::deleteUser(Node<user> *usr)
{
  std::cout << "Are you sure you would like to delete your account and all its info? (yes/no)" << std::endl;
  string answer;

  do{
    std::getline(std::cin, answer);
    //std::cin >> answer;
    //if (!cin)
        //cin.clear();
        //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (answer != "yes" && answer != "no")
      std::cout << "Please select either 'yes' or 'no'" << std::endl;
  } while (answer != "yes" && answer != "no");

  if (answer == "no")
    return userPage(usr);

  else if (answer == "yes")
  {
    
    //remove deleted users from all friends lists and friend requests
    Node<user>* temp = un->getHead();
    while (temp != NULL)
    {
      if (temp->getData().getFriends()->contains(usr->getData().getUsername()))
       temp->getDataToMod()->getFriends()->remove(usr->getData().getUsername());

      if (temp->getData().getRequests()->contains(usr->getData().getUsername()))
        temp->getDataToMod()->getRequests()->remove(usr->getData().getUsername());

      temp = temp->getNext();
    }

    int index = un->getUserIndex(usr->getData().getUsername());
    un->getULL()->remove(index);
    std::cout << "*******************************" << std::endl;
    std::cout << "Your account has been deleted." << std::endl;
    std::cout << "*******************************" << std::endl;
    un->writeUserNetwork();
    un->writeFriends(0);
    un->writeFriends(1);
    return start();
  }


}

void socialNetwork::friendMenu(Node<user> *usr)
{
  std::cout << "Select an option" << std::endl;
  std::cout << "1.) Display friends" << std::endl;
  std::cout << "2.) Delete a friend" << std::endl;
  std::cout << "3.) View friend requests" <<std::endl;
  std::cout << "4.) Send a friend request"<<std::endl;
  std::cout << "5.) Manage friend requests" <<std::endl;
  std::cout << "6.) Return to user menu" <<std::endl;

  int selection = 1;
  
  do{
    std::cin >> selection;
    if (!cin)
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (selection < 1 || selection > 6)
      std::cout << "Invalid selection" << std::endl;
  } while (selection < 1 || selection > 6);

  if (selection == 1)
  {
    std::cout << "*******************************" << std::endl;
    std::cout << "FRIENDS" <<std::endl;
    std::cout << usr->getData().displayFriends()<<std::endl;
    std::cout << "*******************************" << std::endl;
    return friendMenu(usr);
  }

  if (selection == 2)
    {
      return deleteFriend(usr);
    }

  if (selection == 3)
  {
    std::cout << "*******************************" << std::endl;
    std::cout << "FRIEND REQUESTS" <<std::endl;
    std::cout << usr->getData().displayRequests()<<std::endl;
    std::cout << "*******************************" << std::endl;
    return friendMenu(usr);
  }  

  if (selection == 4)
  {
    return sendFriendRequest(usr);
  }

  if (selection == 5)
  {
    if (usr->getData().getRequests()->getHead() == NULL)
    {
      std::cout << "*******************************" << std::endl;
      std::cout<<"You have no friend requests." << std::endl;
      std::cout << "*******************************" << std::endl;
      return friendMenu(usr);
    }
    else
      return manageRequests(usr);
  }

  if (selection == 6)
    {
      return userPage(usr);
    }
  
}

void socialNetwork::deleteFriend(Node<user> *usr)
{

  if (usr->getData().getFriends()->getHead() == NULL)
    {
      std::cout << "*******************************" << std::endl;
      std::cout<<"You have no friends to delete." << std::endl;
      std::cout << "*******************************" << std::endl;
      return friendMenu(usr);
    }
  
  std::cout << "Please enter the username (case sensitive) of the friend you wish to delete:" << std::endl;
  string frnd;
  std::cin >> frnd;

  un->removeFriend(usr->getData().getUsername(), frnd);
  std::cout << "*******************************" << std::endl;
  std::cout << "Your friend has been deleted." << std::endl;
  std::cout << "*******************************" << std::endl;
  un->writeFriends(0);

  return friendMenu(usr);

}
  

void socialNetwork::changeInfo(Node<user> *usr) 
{
  std::cout << "*******************************" << std::endl;
  std::cout << "Select an option" << std::endl;
  std::cout << "1.) Change password" << std::endl;
  std::cout << "2.) Change birthday" << std::endl;
  std::cout << "3.) Change real name" << std::endl;
  std::cout << "4.) Return to previous menu" << std::endl;
  
  
  int selection = 1;

  do{
    std::cin >> selection;
    if (!cin)
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (selection < 1 || selection > 4)
      std::cout << "Invalid selection" << std::endl;
  } while (selection < 1 || selection > 4);

  if (selection == 1) {

    string pass;
    std::cout << "Enter current password:";
    std::cin >> pass;
    if (usr->getData().getPassword() != pass) {
      std::cout << "*******************************" << std::endl;
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
    std::cout << "*******************************" << std::endl;
    std::cout << "Successfully changed your password!" << std::endl;
    return changeInfo(usr);
     
  }

  if (selection == 2) {

    string dob;
    std::cout << "Enter your birthday:";
    std::cin >> dob;
    usr->getDataToMod()->setDOB(dob);
    std::cout << "*******************************" << std::endl;
    std::cout << "Successfully changed your birthday!" << std::endl;
    return changeInfo(usr);

  }



  if (selection == 3) {
    
    string realn;
    std::cout << "Enter new real name:";
    std::cin >> realn;
    usr->getDataToMod()->setRealName(realn);
    std::cout << "*******************************" << std::endl;
    std::cout << "Successfully changed your real name!" << std::endl;
    return changeInfo(usr);
    
  }


  
  if(selection == 4)
    return userPage(usr);
  
}


// search for users by username or real name, not case sensitive
void socialNetwork::searchUser(Node<user> *usr)
{
  std::cout << "*******************************" << std::endl;
  std::cout << "Select an option" << std::endl;
  std::cout << "1.) Search by real name" << std::endl;
  std::cout << "2.) Search by username" << std::endl;
  std::cout << "3.) Return to previous menu" << std::endl;

  int selection = 1;

  do{
     std::cin >> selection;
     if (!cin)
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     if (selection != 1 && selection != 2 && selection != 3)
       std::cout << "Invalid selection" << std::endl;
  } while (selection != 1 && selection != 2 && selection != 3);

  if(selection == 3)
    return userPage(usr);
  
  std::cout << "Enter your search:" << std::endl;

  std::string input;

  do{
    std::cin >> input;
    if (input.length() < 2) {
      std::cout << "*******************************" << std::endl;
      std::cout << "Your search must be atleast 2 characters" <<std::endl;
      return searchUser(usr);
    }
  } while (input.length() < 2);
  // downcase the seaerch input
  std::transform(input.begin(),input.end(),input.begin(), ::tolower);

  std::cout << "RESULTS:" << std::endl;
  Node<user> *temp = un->getHead();
  int counter = 0;
  while (temp != NULL)
  {
    //save the case sensitive and downcased version of usernames
    std::string result, result2; 
    if (selection == 1)
      result = temp->getData().getRealName();
    else if (selection == 2)
      result = temp->getData().getUsername();
    result2 = result;
    // downcase the usernames
    std::transform(result2.begin(),result2.end(),result2.begin(),::tolower);

    // check if the input string is a substring of any username
    // and return the case sensitive version
    if (result2.find(input) != std::string::npos)
    {
      std::cout<<result<<std::endl;
      counter++;
    }

    temp = temp->getNext();
      
  }

  if (counter == 0)
  {
    std::cout << "*******************************" << std::endl;
    std::cout<<"No matching results found"<<std::endl;
    return userPage(usr);
  }

  string answer;
  std::cout << "*******************************" << std::endl;
  std::cout<<"Would you like to send a friend request? (yes/no)"<<std::endl;
  std::cout << "*******************************" << std::endl;
  do{
      std::cin >> answer;
      if (answer != "yes" && answer != "no")
        std::cout << "Please select either 'yes' or 'no'" << std::endl;
    } while (answer != "yes" && answer != "no");

    if (answer == "no")
      return userPage(usr);
    else if (answer == "yes")
      return sendFriendRequest(usr);

}

void socialNetwork::sendFriendRequest(Node<user> *usr)
{
  std::cout << "*******************************" << std::endl;
  std::cout << "Select an option" << std::endl;
  std::cout << "1.) Send request by real name" << std::endl;
  std::cout << "2.) Send request by username" << std::endl;
  std::cout << "3.) Return to friend menu" <<std::endl;

  int selection = -1;

  do{
     std::cin >> selection;
     if (!cin)
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     if (selection < 1 || selection > 3)
       std::cout << "Invalid selection" << std::endl;
  } while (selection < 1 || selection > 3);

  if (selection == 1)
    std::cout << "Enter the name of whom you would like to send a request:" << std::endl;

  else if (selection == 2)
    std::cout << "Enter the username of whom you would like to send a request:" << std::endl;

  else if (selection == 3) {
    std::cout << "*******************************" << std::endl;
    return friendMenu(usr);
  }

  std::string input;
  //std::cin >> input;
  std::getline(std::cin, input);
  //std::getline(std::cin, input);
  
  if (selection == 1)
  {
    if ((un->checkRealName(input)))
    {

      if (input == usr->getData().getRealName())
      {
	std::cout << "*******************************" << std::endl;
        std::cout<<"You can't be friends with yourself."<<std::endl;
        return sendFriendRequest(usr);
      }

      if (un->getUserNodeRealName(input)->getData().checkRequest(usr->getData().getUsername()))
      {
	std::cout << "*******************************" << std::endl;
        std::cout<<"You have already sent a friend request to this user."<<std::endl;
        return sendFriendRequest(usr);
      }

      if (usr->getData().getFriends()->contains(un->getUserNodeRealName(input)->getData().getUsername()))
      {
	std::cout << "*******************************" << std::endl;
        std::cout<<"You are already friends with this user."<<std::endl;
        return sendFriendRequest(usr);
      }

      else
      {
        un->getUserNodeRealName(input)->getDataToMod()->addRequest(usr->getData().getUsername());
	std::cout << "*******************************" << std::endl;
	std::cout << "Friend request sent!" << std::endl;
	std::cout << "*******************************" << std::endl;
        un->writeFriends(1);
        return friendMenu(usr);
      }
    }

    else
    {
      std::cout << "*******************************" << std::endl;
      std::cout << "Person not found" <<std::endl;
      return sendFriendRequest(usr); 
    }
  }

  if (selection == 2)
  {
    if ((un->checkUsername(input)))
    {
      if (input == usr->getData().getUsername())
      {
	std::cout << "*******************************" << std::endl;
        std::cout<<"You can't be friends with yourself."<<std::endl;
        return sendFriendRequest(usr);
      }

      if (un->getUserNode(input)->getData().checkRequest(usr->getData().getUsername()))
      {
	std::cout << "*******************************" << std::endl;
        std::cout<<"You have already sent a friend request to this user."<<std::endl;
        return sendFriendRequest(usr);
      }

      if (usr->getData().getFriends()->contains(input))
      {
	std::cout << "*******************************" << std::endl;
        std::cout<<"You are already friends with this user."<<std::endl;
        return sendFriendRequest(usr);
      }

      else
      {
        un->getUserNode(input)->getDataToMod()->addRequest(usr->getData().getUsername());
	std::cout << "*******************************" << std::endl;
	std::cout << "Friend request sent!" << std::endl;
	std::cout << "*******************************" << std::endl;
        un->writeFriends(1);
        return friendMenu(usr);
      }
    }

    else
    {
      std::cout << "*******************************" << std::endl;
      std::cout << "Person not found" <<std::endl;
      return sendFriendRequest(usr); 
    }
  }
}


void socialNetwork::manageRequests(Node<user> *usr)
{
  std::cout << "*******************************" << std::endl;
  std::cout << "FRIEND REQUESTS" <<std::endl;
  std::cout << usr->getData().displayRequests()<<std::endl;  

  int num = -1;
  do{
    std::cout << "Enter the number corresponding to the friend request you want to accept or decline" << std::endl;
    std::cin >> num;
    if (!cin)
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (num < 1 || num > usr->getData().getRequests()->getCount())
      std::cout << "Invalid selection" << std::endl;
  } while (num < 1 || num > usr->getData().getRequests()->getCount());  
  std::cout << "*******************************" << std::endl;
  std::cout << "What would you like to do with this request?" << std::endl;
  std::cout << "1.) Accept friend request"  << std::endl;
  std::cout << "2.) Decline friend request" << std::endl;
  std::cout << "3.) Nevermind, return to friend menu" <<std::endl;

  int selection;
  do{
    std::cin >> selection;
    if (!cin)
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (selection < 1 || selection > 3)
      std::cout << "Invalid selection" << std::endl;
  } while (selection < 1 || selection > 3);
  
  if (selection == 1)
  {
    string thisUser = usr->getData().getUsername();
    //std::cout<<thisUser<<std::endl;
    string otherUser = usr->getData().getRequests()->get(num-1);
    //std::cout<<otherUser<<std::endl;
    usr->getDataToMod()->addFriend(usr->getData().getRequests()->get(num-1));
    un->getUserNode(otherUser)->getDataToMod()->addFriend(thisUser); 
    usr->getDataToMod()->getRequests()->remove(num-1);
    un->writeFriends(0);
    un->writeFriends(1);
    std::cout << "*******************************" << std::endl;
    std::cout<<"You and " << otherUser << " are now friends!"<< std::endl;
    std::cout << "*******************************" << std::endl;
    return friendMenu(usr);
  }

  if (selection == 2)
  {
    string otherUser = usr->getData().getRequests()->get(num-1);
    usr->getDataToMod()->getRequests()->remove(num-1);
    un->writeFriends(0);
    un->writeFriends(1);
    std::cout << "*******************************" << std::endl;
    std::cout<<"You have declined the friend request from " << otherUser << "." <<std::endl;
    std::cout << "*******************************" << std::endl;
    return friendMenu(usr);

  }

  if (selection == 3)
  {
    std::cout << "*******************************" << std::endl;
    return friendMenu(usr);
  }



}




