#ifndef USER_H
#define USER_H
using namespace std;
#include "wallPost.h"
#include "wall.h"
class user {
  
 private:
  wall w;
  string username;
  string password;
  string realName;
  int age;

 public:
  user();
  ~user();
  void setUsername(string t);
  void setPassword(string t);
  void setRealName(string t);
  void setAge(int i);
  void addtoWall(wallPost *w);
  void deletePost(wallPost *w);
  string userInfo();
  void readUser();
};

#endif
