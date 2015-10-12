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
  if(w == NULL)
    w->addTail(p);
  

}

void wall::deletePost(int i) {

}

string wall::getUsername() {
  return username;
}

void wall::setUsername(string t) {
  username = t;
}

void wall::displayWall() {

}

void wall::readWall(string t) {

}
