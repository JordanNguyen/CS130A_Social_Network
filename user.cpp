#include <cstdlib>
#include <cstdio>
#include <iostream>
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
}

user::user(string u, string p, string r, string d)
{
  username = u;
  password = p;
  realName = r;
  dob = d;
}

user::user(string info)
{
  // string of format 
}

user::~user()
{
  
}


void user::setUsername(string t) {
  username = t;
}

void user::setPassword(string t) {
  password = t;
}

void user::setRealName(string t) {
  realName = t;
}

void user::setDOB(string t) {
  dob = t;
}

string user::userInfo() {
  string info;
  info = "Username: " + username + "\n"
  + "Password: " + password + "\n" + "Real name: "
  + realName + "\n" + "Birthday: " + dob + "\n";

  std::cout << info;
  return info;
}

string user::getUsername()
{
  return username;
}

void user::addToWall(wallPost wallpost) {
  w.newPost(wallpost);
}

void user::deleteWallPost(int i) {
  w.deletePost(i);
}


wall user::getWall() {
  return w;
}
