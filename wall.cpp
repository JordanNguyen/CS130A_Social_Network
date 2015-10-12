#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include "wall.h"
using namespace std;

wall::wall() {

  w = new LinkedList<wallPost>;
  username = "";
  cout << "Wall created!" << endl;

}

wall::~wall() {


}

void wall::newPost(wallPost p) {

  w->addTail(p);
  cout << "New post added" << endl;
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
  int count = w->getCount();
  string wholeWall = "";
  Node<wallPost> *temp = w->getHead();
  for (int i=0; i < count; temp=temp->getNext(), i++)
    {
    wholeWall += temp->getData().getPost();
    }
  //while (temp != NULL)
  //{
  //  wholeWall = wholeWall + temp->getData().getPost();
  //  temp=temp->getNext();
  //}
  std::cout << wholeWall;
  return wholeWall;
}

void wall::readWall(string t) {

}

LinkedList<wallPost>* wall::getLL() {
  return w;
}
