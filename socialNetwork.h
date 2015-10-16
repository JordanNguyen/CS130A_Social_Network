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
  void start();
  void createNewUser();
  bool checkUsername(string un);

};

#endif
