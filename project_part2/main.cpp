#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <fstream>
//#include "LinkedList.h"
//#include "wallPost.h"
//#include "wall.h"
//#include "user.h"
//#include "userNetwork.h"
//#include "socialNetwork.h"
#include "Array.h"
//using namespace std;

int main(int argc, char *argv[])
{
	
  //socialNetwork sn;
  // sn.welcome();
  Array<int> *a = new Array<int>();
  a->insert(0,5);
  a->insert(1,8);
  a->insert(2,4);
  a->insert(1,60);
  a->insert(4,100);
  a->insert(6,40);
  a->insert(7,21);

  a->remove(0);
  a->remove(0);
  a->set(0,23);
  a->set(1,24);
  a->set(3,69);
  a->set(5,222);
  return 0;
}
