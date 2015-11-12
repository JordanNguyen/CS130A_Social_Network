#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <fstream>
#include <stdexcept>
#include <list>
#include "wallPost.h"
#include "wall.h"
//#include "user.h"
//#include "userNetwork.h"
//#include "socialNetwork.h"
using namespace std;

int main(int argc, char *argv[])
{
	
  //socialNetwork sn;
  //sn.welcome();

  wall test;
  wallPost post1("Test post", "isla vista");
  wallPost post2("Test post number 2", "goleta");
  wallPost post3("third post", "ucsb");
  test.newPost(post1);
  test.newPost(post2);
  test.newPost(post3);

  std::cout<<test.WallToString();
  std::cout<<"deleting"<<std::endl;
  test.deletePost(1);
  std::cout<<test.WallToString();
  std::cout<<"testing other write method"<<std::endl;
  std::cout<<test.WallToStringWrite()<<std::endl;
  test.deletePost(0);
  test.deletePost(0);
  std::cout<<test.WallToString();


  return 0;
}
