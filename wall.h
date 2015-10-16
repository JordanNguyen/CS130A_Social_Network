#ifndef WALL_H
#define WALL_H
#include "wallPost.h"
#include "LinkedList.h"
using namespace std;

class wall {

 private:
  LinkedList<wallPost> *wp; 
  string username;

 public:
  wall();
  ~wall();
  void newPost(wallPost p);
  void deletePost(int i);
  string getUsername();
  void setUsername(string t);
  string WallToString();
  void readWall(string t);
  LinkedList<wallPost>* getLL();
  
};

#endif  
