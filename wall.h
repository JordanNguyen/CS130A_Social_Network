#ifndef WALL_H
#define WALL_H
#include "wallPost.h"
#include "LinkedList.h"
using namespace std;

class wall {

 private:
  LinkedList<wallPost> *w; 
  string username;

 public:
  wall();
  ~wall();
  void newPost(wallPost *p);
  void deletePost(int i);
  string getUsername();
  void setUsername(string t);
  void displayWall();
  void readWall(string t);
  
};

#endif  
