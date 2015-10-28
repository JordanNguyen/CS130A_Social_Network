#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <fstream>
#include <stdexcept>
#include "LinkedList.h"
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
  LinkedList<string> *a = new LinkedList<string>();
  a->insert(0,"iguodala");
  //a->printList();
  a->insert(1,"jimmy");
  a->insert(2,"westbrook");
  a->insert(3,"KD");
  a->insert(4,"draymond");
  a->insert(2,"klay");
  a->insert(0,"steph");
  a->insert(5,"lebron");
  a->printList();
  // a->insert(9,"dsfds");
  // a->insert(6,"i caused the array to double");

  a->remove(0);
  a->remove(0);
  a->remove(1);
  //a->remove(2);
  //a->remove(3);
  //a->remove(-1);
  //a->remove(4);
  a->printList();
  a->set(4,"BIG DICK DRAY!!!!!");
  //a->set(6, "fuck me");
  a->printList();
  // a->set(2,"i got changed too");
  // a->set(3,"haha");
  // a->set(5,"testing");
  // a->get(10);
  // a->get(3);
  try{
      a->get(8);
  }

  catch (const std::out_of_range& e){
  std::cout<< "Index was out of range" << std::endl;
  return 0;
  }

  return 0;
}
