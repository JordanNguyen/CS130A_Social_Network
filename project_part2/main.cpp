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
using namespace std;

int main(int argc, char *argv[])
{
	
  //socialNetwork sn;
  // sn.welcome();
  // Array<string> *a = new Array<string>();
  // a->insert(0,"test");
  // a->insert(1,"another one");
  // a->insert(2,"i just got inserted");
  // a->insert(3,"next");
  // a->insert(4,"where did i go?");
  // a->insert(2,"hi");
  // a->insert(0,"df");
  // a->insert(5,"im in eighth");
  // a->insert(9,"dsfds");
  // a->insert(6,"i caused the array to double");

  // a->remove(0);
  // a->remove(0);
  // a->remove(2);
  // a->set(0,"i got changed");
  // a->set(2,"i got changed too");
  // a->set(3,"haha");
  // a->set(5,"testing");
  // a->get(10);
  // a->get(0);

  Array<int> *a = new Array<int>();
  a->insert(0,1);
  a->insert(1,2);
  a->insert(2,4);
  a->insert(4,2);
  a->insert(3,10);
  return 0;
}
