#ifndef SOCIALNETWORK_H
#define SOCIALNETWORK_H
#include "user.h"
#include "userNetwork.h"
#include <list>

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
  void checkRequest(user *usr);
  void newPost(user *usr);
  void deletePost(user *usr);
  void userPage(user *usr);
  void changeInfo(user *usr);
  void friendMenu(user *usr);
  void deleteFriend(user *usr);
  void deleteUser(user *usr); //need to edit this
  void displayWall(user *usr);
  void searchUser(user *usr); //need to edit this
  void sendFriendRequest(user *usr); //need to edit this
  void manageRequests(user *usr); //need to fix this also

};

#endif
