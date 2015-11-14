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
  void postOnFriendWall(user *usr);
  void deleteFriend(user *usr);
  void otherUsersWall(user *usr);
  void deleteUser(user *usr); //need to edit this, fixed for now
  void displayWall(user *usr);
  void searchUser(user *usr); //need to edit this, fixed for now
  void sendFriendRequest(user *usr); //need to edit this, fixed for now
  void manageRequests(user *usr); //need to fix this also, fixed for now
  void respondToPost(user *usr);

};

#endif
