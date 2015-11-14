#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <list>
#include "wall.h"
using namespace std;

wall::wall() {

  wp = new list<wallPost>;
  username = "";

}

wall::~wall() {
  //delete wp;

}

// new wall post to end of wall
void wall::newPost(wallPost p) {

  wp->push_back(p);
  //cout << "New post added" << endl;
}

// delete wall post at index i
void wall::deletePost(int i) {
  std::list<wallPost>::iterator it;
  it = wp->begin();
  advance(it, i);
  wp->erase(it);
}

// get username
string wall::getUsername() {
  return username;
}

// change username
void wall::setUsername(string t) {
  username = t;
}

/*
void wall::insertPost(int pos, wallPost p){
  iterator it;
  it = wp->begin();
  advance(it, i);
  wp->insert(pos,p);
}
*/

/*
void wall::setPost(int pos, wallPost p){
  wp->set(pos,p);
}
*/


wallPost* wall::getPost(int pos){

  std::list<wallPost>::iterator it;
  int i = 0;
  for (it = wp->begin(); i < pos; ++it, i++);

  return &(*it);
}

// return the wall as a formated string
string wall::WallToString() 
{
  int count = wp->size();
  string wholeWall = "";
  if (wp->empty())
    {
      wholeWall = "Your wall is empty.\n";
      return wholeWall;
    }

  std::list<wallPost>::iterator it;
  int i = 0;
  for (it = wp->begin(), i = 0; it != wp->end(); ++it, i++)
    {
      ostringstream convert;
      convert << i+1;
      wholeWall += convert.str();
      wholeWall += ".) ";
      wholeWall += it->getPost();
    }
  //std::cout << wholeWall;
  return wholeWall;
}

// write the wall as a formatted string for file
string wall::WallToStringWrite()
{
  int count = wp->size();
  string wholeWall = "";
  
  if (wp->empty())
    return wholeWall;

  std::list<wallPost>::iterator it;
  int i = 0;
  for (it = wp->begin(), i=0; it != wp->end(); ++it, i++)
  {
    wholeWall += it->getPostWrite();
    wholeWall += it->writeResponses();
    wholeWall += "[/endpost]\n";
    if (i == count - 1)
      wholeWall += "[/endwallposts]";
    else
      wholeWall += "\n";
  }

  return wholeWall;

}


// return the pointer to the list
list<wallPost>* wall::getList() {
  return wp;
}

