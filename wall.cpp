#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include "wall.h"
using namespace std;

wall:wall() {
  w = NULL;
  username = "";

}

wall::~wall() {


}

void wall::newPost(wallPost *p) {

  w->addTail(p);
}

void wall::deletePost(int i) {
  w->remove(i);
}

string wall::getUsername() {
  return username;
}

void wall::setUsername(string t) {
  username = t;
}

string wall::displayWall() {
  string wholeWall = "";
  Node<wallPost> *temp = w->getHead();
  while (temp->getNext() != NULL)
    {
      wholeWall += temp->getPost();
      temp=temp->getNext();
    }
  //std::cout << wholeWall;
  return wholeWall;
}

void wall::readWall(string t) {

}
