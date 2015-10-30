#ifndef SOCIALNETWORK_H
#define SOCIALNETWORK_H
#include "user.h"
#include "LinkedList.h"
#include "userNetwork.h"
#include "List.h"

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
  void newPost(Node<user> *usr);
  void deletePost(Node<user> *usr);
  void userPage(Node<user> *usr);
  void changeInfo(Node<user> *usr);
  void friendMenu(Node<user> *usr);
  void deleteFriend(Node<user> *usr);
  void displayWall(Node<user> *usr);

};

#endif
