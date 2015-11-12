#ifndef USER_H
#define USER_H
using namespace std;
#include "wallPost.h"
#include "wall.h"
#include <list>
class user {
  
 private:
  wall w;
  string username;
  string password;
  string realName;
  string dob;
  list<string> *friends;
  list<string> *requests;

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
  string getRealName();
  string getDob();
  void addToWall(wallPost w);
  void deleteWallPost(int i);
  wall getWall();
  string userInfo();
  string userInfoWrite();
  string friendListWrite(int option);
  void addFriend(string s);
  void addRequest(string s);
  string displayFriends();
  string displayRequests();
  list<string>* getFriends();
  list<string>* getRequests();
  bool hasRequests();
  bool checkRequest(string usr);
  
};

#endif
