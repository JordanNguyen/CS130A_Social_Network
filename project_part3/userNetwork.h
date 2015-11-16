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
  void writeUserNetwork(const char* path);
  void writeFriends(const char* path, int option);
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
  void degreeOfSeparation(string usr1, string usr2);
  bool checkVisited(string u, list<string> l);
  void generateUsers();
  void findDegreeOne(string usr);
  void findDegreeTwo(string usr, list<string> d1);
  void findDegreeThree(string usr, list<string> d1, list<string> d2);
};

#endif

  
