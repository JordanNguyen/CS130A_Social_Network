#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include "wallPost.h"
#include "wall.h"
#include "user.h"
using namespace std;

user::user()
{
  username = "";
  password = "";
  realName = "";
  dob = "";
  friends = new LinkedList<string>;
  requests = new LinkedList<string>;
  
}

user::user(string u, string p, string r, string d)
{
  username = u;
  password = p;
  realName = r;
  dob = d;
  w.setUsername(u);
  friends = new LinkedList<string>;
  requests = new LinkedList<string>;
}

user::user(string info)
{
  // string of format "Username\nPassword\nRealName\nDob\n  \nPost1\nTimeOfPost\nLocation\n \n"

  friends = new LinkedList<string>;
  
  string s = info;
  string delimiter1 = "  \n";
  string delimiter2 = "\n";
  string delimiter3 = " \n";

  size_t pos1 = 0;
  size_t pos2 = 0;
  int counter = 0;

  string token1;
  string token2;

  string post;
  string timeOfPost;
  string location;

  // find the end of the basic user info before the wall
  while ((pos1 = s.find(delimiter1)) != string::npos) {
    token1 = s.substr(0, pos1);

    while ((pos2 = token1.find(delimiter2)) != string::npos) {
      token2 = token1.substr(0,pos2);
      if (counter == 0)
        username = token2;
      if (counter == 1)
        password = token2;
      if (counter == 2)
        realName = token2;

      counter++;
      token1.erase(0, pos2+delimiter2.length());
    }

  s.erase(0, pos1 + delimiter1.length());
  dob = token2;
  }

  while ((pos1 = s.find(delimiter3)) != string::npos) {
    token1 = s.substr(0, pos1);
    counter = 0;
    while ((pos2 = token1.find(delimiter2)) != string::npos) {

      token2 = token1.substr(0,pos2);
      if (counter == 0)
        post = token2;
      if (counter == 1)
        timeOfPost = token2 + "\n";
      counter++;
      token1.erase(0,pos2 + delimiter2.length());

    }

    s.erase(0, pos1 + delimiter3.length());
    location = token2;
    wallPost npost(post,timeOfPost,location);
    w.newPost(npost);

  }



}

user::~user()
{
  
}


void user::setUsername(string t) 
{
  username = t;
}

void user::setPassword(string t) 
{
  password = t;
}

void user::setRealName(string t) 
{
  realName = t;
}

void user::setDOB(string t) 
{
  dob = t;
}

string user::userInfo() 
{
  string info;
  info = "Username: " + username + "\n"
  + "Password: " + password + "\n" + "Real name: "
  + realName + "\n" + "Birthday: " + dob + "\n";
  string wallposts = w.WallToString();

  info += wallposts;

  //std::cout << info;
  return info;
}

string user::userInfoWrite() 
{
  string info;
  info = username + "\n" + password + "\n" + realName 
  + "\n" + dob + "\n" + "[/endinfo]\n";

  return info;

}

string user::friendListWrite(int option)
{
  string frnds;
  frnds += username;
  frnds += "\n[/username]\n";

  Node<string> *temp;
  if (option == 0)
    temp = friends->getHead();

  else if (option == 1)
    temp = requests->getHead();

  while (temp != NULL)
  {
    frnds += temp->getDataConst();
    frnds += "\n";
    temp=temp->getNext();
  }

  frnds += "[/endfriends]";
  return frnds;
}

string user::displayFriends()
{
  string frnds;
  Node<string> *temp = friends->getHead();

  if (temp == NULL)
    frnds = "You have no friends :(";
  
  while (temp != NULL)
    {
      frnds += temp->getData();
      frnds += "\n";
      temp = temp->getNext();
    }

  return frnds;
  
}

string user::displayRequests()
{
  string reqs;
  Node<string> *temp = requests->getHead();

  if (temp == NULL)
    reqs = "You have no friend requests.";
  int i = 0;
  while (temp != NULL)
  {
    ostringstream convert;
    convert << i+1;
    reqs += convert.str();
    reqs += ".)";
    reqs += temp->getData();
    reqs += "\n";
    temp = temp->getNext();
    i++;
  }

  return reqs;

}
  

string user::getUsername()
{
  return username;
}

string user::getPassword()
{
  return password;
}

string user::getRealName()
{
  return realName;
}

string user::getDob()
{
  return dob;
}

void user::addToWall(wallPost wallpost) 
{
  w.newPost(wallpost);
}

void user::deleteWallPost(int i) 
{
  w.deletePost(i);
}


wall user::getWall() 
{
  return w;
}

void user::addFriend(string s)
{
  friends->addTail(s);
}

void user::addRequest(string s)
{
  requests->addTail(s);
}

LinkedList<string>* user::getFriends()
{
  return friends;
}

LinkedList<string>* user::getRequests()
{
  return requests;
}

bool user::hasRequests()
{
  if (requests->getHead() == NULL)
    return false;
  else 
    return true;

}

bool user::checkRequest(string usr)
{
  return requests->contains(usr);
}