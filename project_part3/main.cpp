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
#include "userNetwork.h"
#include "socialNetwork.h"
using namespace std;

int main(int argc, char *argv[])
{
	
  //socialNetwork sn;
  //sn.welcome();

  userNetwork un;

  user user1("Jordan", "p", "p", "123");
  user user2("Sal", "p", "p", "123");
  user user3("Brian", "p", "p", "123");
  user user4("Table", "p", "p", "123");
  user user5("Folder", "p", "p", "123");
  user user6("Starbucks", "p", "p", "123");
  user user7("Stephen", "p", "p", "123");
  user user8("Lebron", "p", "p", "123");
  user user9("Billy", "p", "p", "123");
  user user10("MACBOOK", "p", "p", "123");
  user user11("DivyAgrawal", "p", "p", "123");

  un.addUser(user1);
  un.addUser(user2);
  un.addUser(user3);
  un.addUser(user4);
  un.addUser(user5);
  un.addUser(user6);
  un.addUser(user7);
  un.addUser(user8);
  un.addUser(user9);
  un.addUser(user10);
  un.addUser(user11);

  user1.addFriend(user2.getUsername());
  user1.addFriend(user3.getUsername());
  user1.addFriend(user4.getUsername());
  user2.addFriend(user1.getUsername());
  user3.addFriend(user1.getUsername());
  user4.addFriend(user1.getUsername());
  user1.addFriend(user11.getUsername());
  user11.addFriend(user1.getUsername());

  user4.addFriend(user5.getUsername());
  user5.addFriend(user4.getUsername());

  user5.addFriend(user6.getUsername());
  user6.addFriend(user5.getUsername());

  user6.addFriend(user7.getUsername());
  user6.addFriend(user8.getUsername());

  user7.addFriend(user6.getUsername());
  user8.addFriend(user6.getUsername());

  user8.addFriend(user9.getUsername());
  user9.addFriend(user8.getUsername());

  user9.addFriend(user10.getUsername());
  user10.addFriend(user9.getUsername());

  un.degreeOfSeparation(user1.getUsername());

  // userNetwork testNet;

  // user test("TheWiz", "password",
  //   "Jordan Nguyen", "03/11/1995");
  // wallPost post1("Test post", "isla vista");
  // wallPost post2("Test post number 2", "goleta");
  // wallPost post3("third post", "ucsb");
  // test.addToWall(post1);
  // test.addToWall(post2);
  // test.addToWall(post3);

  // user test2("username","password",
  // 	     "test name", "3423432");
  // user test3("anotherone", "wedabest",
  // 	     "dj khaled", "12345");
  // testNet.addUser(test);
  // testNet.addUser(test2);
  // testNet.addUser(test3);

  // testNet.writeUserNetwork();

  // if (testNet.checkUsername("username"))
  //   cout<<"username exists"<<endl;

  // if (testNet.checkRealName("dj khaled"))
  //   cout<<"dj khaled exists"<<endl;

  // cout << testNet.getUserIndex("TheWiz") << endl;

  // if (testNet.checkLogin("TheWiz", "password"))
  //     cout<<"Correct credentials"<<endl;

  // user* temp = testNet.getUser("TheWiz");

  // temp->setUsername("JordanTheWiz");

  // user *temp2 = testNet.getUser("anotherone");
  // temp2->setUsername("DEE JAY KHA LED");

  // testNet.writeUserNetwork();



  // cout<<test.userInfo()<<endl;

  // cout<<test.userInfoWrite()<<endl;

  // test.addFriend("Young Thug");
  // test.addFriend("Justin Bieber");
  // test.addFriend("Steph Curry");

  // //cout<<test.friendListWrite(0)<<endl;

  // if (test.hasRequests())
  //   cout<<"You have friend requests"<<endl;
  // else
  //   cout<<"You have no friend requests"<<endl;

  // test.addRequest("Drake");
  // test.addRequest("Meek Mill");
  // test.addRequest("Blender");
  // cout<<test.displayFriends()<<endl;
  // cout<<test.displayRequests()<<endl;



  // if (test.checkRequest("Ddake"))
  //   cout<<"Drake has already sent you a friend request"<<endl;



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
