#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <fstream>
#include <stdexcept>
#include <list>
#include "wallPost.h"
#include "wall.h"
#include "user.h"
//#include "userNetwork.h"
//#include "socialNetwork.h"
using namespace std;

int main(int argc, char *argv[])
{
	
  //socialNetwork sn;
  //sn.welcome();

  user test("TheWiz", "password",
    "Jordan Nguyen", "03/11/1995");
  wallPost post1("Test post", "isla vista");
  wallPost post2("Test post number 2", "goleta");
  wallPost post3("third post", "ucsb");
  test.addToWall(post1);
  test.addToWall(post2);
  test.addToWall(post3);

  cout<<test.userInfo()<<endl;

  cout<<test.userInfoWrite()<<endl;

  test.addFriend("Young Thug");
  test.addFriend("Justin Bieber");
  test.addFriend("Steph Curry");

  //cout<<test.friendListWrite(0)<<endl;

  if (test.hasRequests())
    cout<<"You have friend requests"<<endl;
  else
    cout<<"You have no friend requests"<<endl;

  test.addRequest("Drake");
  test.addRequest("Meek Mill");
  test.addRequest("Blender");
  cout<<test.displayFriends()<<endl;
  cout<<test.displayRequests()<<endl;



  if (test.checkRequest("Ddake"))
    cout<<"Drake has already sent you a friend request"<<endl;



  //std::cout<<test.WallToString();
  //std::cout<<"deleting"<<std::endl;
  //test.deletePost(1);
  // std::cout<<test.WallToString();
  // std::cout<<"testing other write method"<<std::endl;
  // std::cout<<test.WallToStringWrite()<<std::endl;
  // test.deletePost(0);
  // test.deletePost(0);
  // std::cout<<test.WallToString();


  return 0;
}
