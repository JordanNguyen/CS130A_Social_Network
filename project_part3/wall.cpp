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


wallPost wall::getPost(int pos){

  std::list<wallPost>::iterator it;
  int i = 0;
  for (it = wp->begin(); i < pos; ++it, i++);

  return *it;
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
    if (i == count - 1)
      wholeWall += "[/endwallposts]";
    else
      wholeWall += "\n";
  }

  return wholeWall;

}

// read in a wall from a properly formatted string
void wall::readWall(string t) {

  //empty list of wallposts
  wp->clear();  

  string s = t;
  // first delimiter to divide up wall posts
  string delimiter1 = " \n";
  // second delimiter to divide up each element of wall post
  string delimiter2 = "\n";

  size_t pos1 = 0;
  size_t pos2 = 0;
  int counter = 0;

  string post;
  string timeOfPost;
  string location;

  string token1;
  string token2;

  //divide up the posts
  while ((pos1 = s.find(delimiter1)) != string::npos) {
    token1 = s.substr(0, pos1);
    counter = 0;
    //cout << token1 << endl << "BREAK" << endl;
    while ((pos2 = token1.find(delimiter2)) != string::npos) {
      
      token2 = token1.substr(0, pos2);
      //cout << token2 << endl << "BREAK" << endl;

      if (counter == 0)
      {
        post = token2;
        //token1.erase(0, pos2 + delimiter2.length());
      }
      if (counter == 1)
      {
        timeOfPost = token2 + "\n";
        //token1.erase(0, pos2 + delimiter2.length());
      }
      //if (counter == 2)
      //{
        //location = token2;
        //token1.erase(0, pos2 + delimiter2.length());
      //}  
      counter++;
      token1.erase(0, pos2 + delimiter2.length());


  }
    //cout << "TOKEN2 AT END OF WHILE LOOP: " << token2 << endl;
    s.erase(0, pos1 + delimiter1.length());
    cout << s << endl;
    location = token2;
    wallPost newPost(post,timeOfPost,location);
    wp->push_back(newPost);


  }

}

// return the pointer to the list
list<wallPost>* wall::getList() {
  return wp;
}

// return the head pointer of the linked list
//Node<wallPost>* wall::getHead()
//{
//  return wp->getHead();
//}
