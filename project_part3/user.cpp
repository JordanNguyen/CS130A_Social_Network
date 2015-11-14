#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include "wallPost.h"
#include "wall.h"
#include "user.h"
#include <list>
using namespace std;

user::user()
{
  username = "";
  password = "";
  realName = "";
  dob = "";
  friends = new list<string>;
  requests = new list<string>;
  
}

user::user(string u, string p, string r, string d)
{
  username = u;
  password = p;
  realName = r;
  dob = d;
  w.setUsername(u);
  friends = new list<string>;
  requests = new list<string>;
}

user::~user()
{
  //delete friends;
  //delete requests;
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

  //Node<string> *temp;
  std::list<string>::iterator it;
  if (option == 0)
  {
    it = friends->begin();
    for (it = friends->begin(); it != friends->end(); ++it)
    {
      frnds += *it;
      frnds += "\n";
    }
  }

  else if (option == 1)
  {
    it = requests->begin();
    for (it = requests->begin(); it != requests->end(); ++it)
    {
      frnds += *it;
      frnds += "\n";
    }
  }

  frnds += "[/endfriends]";
  return frnds;
}

string user::displayFriends()
{
  string frnds;
  std::list<string>::iterator it;

  if (friends->empty())
    frnds = "You have no friends :(";
  
  for (it = friends->begin(); it != friends->end(); ++it)
    {
      frnds += *it;
      frnds += "\n";
      
    }

  return frnds;
  
}

string user::displayRequests()
{
  string reqs;
  std::list<string>::iterator it;

  if (requests->empty())
  {
    reqs = "You have no friend requests.";
    return reqs;
  }

  int i = 1;
  for (it = requests->begin(); it != requests->end(); ++it, i++)
  {
    ostringstream convert;
    convert << i;
    reqs += convert.str();
    reqs += ".)";
    reqs += *it;
    reqs += "\n";
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
  friends->push_back(s);
}

void user::addRequest(string s)
{
  requests->push_back(s);
}

list<string>* user::getFriends()
{
  return friends;
}

list<string>* user::getRequests()
{
  return requests;
}

bool user::hasRequests()
{
  if (requests->empty())
    return false;
  else 
    return true;

}

bool user::checkRequest(string usr)
{
  std::list<string>::iterator it;
  for (it = requests->begin(); it != requests->end(); ++it)
  {
    if (*it == usr)
      return true;
  }

  return false;

}

bool user::isFriendsWith(string usr)
{
  std::list<string>::iterator it;
  for (it = friends->begin(); it != friends->end(); ++it)
    {
      if (*it == usr)
	return true;
    }
  return false;
}

void user::deleteFriend(string usr)
{
  std::list<string>::iterator it;
  for (it = friends->begin(); it != friends->end(); ++it)
    {
      if (*it == usr)
	{
	  friends->erase(it);
	  return;
	}
    }
}

void user::deleteRequest(string usr)
{
  std::list<string>::iterator it;
  for (it = requests->begin(); it != requests->end(); ++it)
    {
      if (*it == usr)
	{
	  requests->erase(it);
	  return;
	}
    }
}

string user::getRequestName(int index)
{
  std::list<string>::iterator it;
  int i = 0;
  for (it = requests->begin(), i = 0; i < index; ++it, ++i);
  return *it;
}
