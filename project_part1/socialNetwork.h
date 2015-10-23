#ifndef SOCIALNETWORK_H
#define SOCIALNETWORK_H
#include "user.h"
#include "LinkedList.h"
#include "userNetwork.h"

class socialNetwork {
  
 private:
  userNetwork *un;

 public:
  socialNetwork();
  ~socialNetwork();
  void welcome();
  void start();
  void createNewUser();
  void login();
  void userPage(Node<user> *usr);
  void displayWall(Node<user> *usr);

};

#endif
