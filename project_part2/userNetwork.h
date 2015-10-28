#ifndef USERNETWORK_H
#define USERNETWORK_H
#include "user.h"
#include "LinkedList.h"
#include "List.h"
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
  bool checkUsername(string usr);
  bool checkLogin(string usr, string pw);
  Node<user>* getUserNode(string usr);
  LinkedList<user>* getULL();

};

#endif

  
