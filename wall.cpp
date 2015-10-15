#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include "wall.h"
using namespace std;

wall::wall() {

  wp = new LinkedList<wallPost>;
  username = "";
  cout << "Wall created!" << endl;

}

wall::~wall() {
  delete wp;

}

void wall::newPost(wallPost p) {

  wp->addTail(p);
  cout << "New post added" << endl;
}

void wall::deletePost(int i) {
  wp->remove(i);
}

string wall::getUsername() {
  return username;
}

void wall::setUsername(string t) {
  username = t;
}

string wall::displayWall() {
  int count = wp->getCount();
  string wholeWall = "";
  Node<wallPost> *temp = wp->getHead();
  for (int i=0; i < count; temp=temp->getNext(), i++)
    {
    wholeWall += temp->getData().getPost();
    }
  std::cout << wholeWall;
  return wholeWall;
}

void wall::readWall(string t) {
  
  //empty linkedlist of wallposts and recreate it
  delete wp;

  cout << "checkpoint";
  wp = new LinkedList<wallPost>;

  std::cout << "I made to 1";

  // need two while loops
  string s = t;
  // first delimiter to divide up wall posts
  string delimiter1 = "\n\n";
  // second delimiter to divide up each element of wall post
  string delimiter2 = "\n";

  size_t pos1 = 0;
  int counter;

  string post;
  string timeOfPost;
  string location;

  string token1;
  string token2;

  std::cout << "I made it before the while loop";
  while ((pos1 = s.find(delimiter1)) != string::npos) {
    token1 = s.substr(0, pos1);
    size_t pos2 = 0;
    counter = 0;
    while ((pos2 = token1.find(delimiter2)) != string::npos) {
      
      token2 = token1.substr(0, pos2);
      if (counter == 0)
      {
        post = token2;
      }
      if (counter == 1)
      {
        timeOfPost = token2;
      }
      if (counter == 2)
      {
        location = token2;
        wallPost newPost(post,timeOfPost,location);
        wp->addTail(newPost);
      }
    }
  }

}

LinkedList<wallPost>* wall::getLL() {
  return wp;
}
