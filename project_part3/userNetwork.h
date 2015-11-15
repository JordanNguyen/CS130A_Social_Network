#ifndef USERNETWORK_H
#define USERNETWORK_H
#include "user.h"
#include <list>
using namespace std;

class userNetwork {
 private:
  list<user> *users;

 public:
  userNetwork();
  ~userNetwork();
  void addUser(user u);
  void deleteUser(string name);
  void writeUserNetwork();
  void writeFriends(int option);
  void readUsers(const char* filename);
  void readFriends(const char* filename, int option);
  void printUsernames();
  bool checkUsername(string usr);
  bool checkRealName(string rn);
  int getUserIndex(string usr);
  bool checkLogin(string usr, string pw);
  user* getUser(string usr);
  user* getUserRealName(string usr);
  void removeFriend(string usr1, string usr2);
  list<user>* getUserList();
  void degreeOfSeparation(string usr1);
};

#endif

  
