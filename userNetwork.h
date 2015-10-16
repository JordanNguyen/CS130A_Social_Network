#ifndef USERNETWORK_H
#define USERNETWORK_H
#include "user.h"
#include "LinkedList.h"
using namespace std;

class userNetwork {
 private:
  LinkedList<user> *users;

 public:
  userNetwork();
  ~userNetwork();
  void addUser(user u);
  void deleteUser(string t);
  void writeUserNetwork();
  void readUsers(const char* filename);
  void printUsernames();
  bool checkUsername(string user, string pw);
  LinkedList<user>* getULL();

};

#endif

  
