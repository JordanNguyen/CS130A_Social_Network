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
  string dob;

 public:
  user();
  user(string u, string p, string r, string d);
  user(string info);
  ~user();
  void setUsername(string t);
  void setPassword(string t);
  void setRealName(string t);
  void setDOB(string t);
  string getUsername();
  string getPassword();
  void addToWall(wallPost w);
  void deleteWallPost(int i);
  wall getWall();
  string userInfo();
  //void readUser();
};

#endif
