#ifndef WALL_H
#define WALL_H
#include "wallPost.h"
#include <list>
using namespace std;

class wall {

 private:
  list<wallPost> *wp; 
  string username;

 public:
  wall();
  ~wall();
  void newPost(wallPost p);
  void deletePost(int i);
  string getUsername();
  void setUsername(string t);
  //void insertPost(int pos, wallPost p);
  //void setPost(int pos, wallPost p);
  wallPost getPost(int pos);
  string WallToString();
  string WallToStringWrite();
  void readWall(string t);
  list<wallPost>* getList();
  //Node<wallPost>* getHead();
  
};

#endif  
