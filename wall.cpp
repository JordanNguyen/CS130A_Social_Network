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
  wp = new LinkedList<wallPost>;
  

  string s = t;
  // first delimiter to divide up wall posts
  string delimiter1 = "\n\n";
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
      if (counter == 2)
      {
        location = token2;
        //token1.erase(0, pos2 + delimiter2.length());
      }  
      counter++;
      token1.erase(0, pos2 + delimiter2.length());


  }
    //cout << "TOKEN2 AT END OF WHILE LOOP: " << token2 << endl;
    s.erase(0, pos1 + delimiter1.length());
    location = token2;
    wallPost newPost(post,timeOfPost,location);
    wp->addTail(newPost);


  }

}

LinkedList<wallPost>* wall::getLL() {
  return wp;
}
