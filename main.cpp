#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <fstream>
#include "LinkedList.h"
#include "wallPost.h"
#include "wall.h"
#include "user.h"
using namespace std;

int main(int argc, char *argv[])
{
	//Node<string> *test = new Node<string>("test");
	//test->printNode();
	/*
	LinkedList<string> *test = new LinkedList<string>;
	test->addTail("one");
	test->addTail("two");
	test->addTail("three");
	test->addTail("four");
	test->addTail("five");
	test->getHead()->printNode();
	test->getHead()->getNext()->printNode();
	test->getHead()->getNext()->getNext()->printNode();
	test->getHead()->getNext()->getNext()->getNext()->printNode();
	test->getTail()->printNode();

	cout << "there are " << test->getCount() << " nodes" << endl;
	cout << "removing node index 2" << endl;

	test->remove(2);
	test->getHead()->printNode();
	test->getHead()->getNext()->printNode();
	test->getHead()->getNext()->getNext()->printNode();
	test->getTail()->printNode();
	cout << "there are " << test->getCount() << " nodes" << endl;

	test->remove(-1);
	test->remove(5);
	test->remove(0);
	test->getHead()->printNode();
	cout << "there are " << test->getCount() << " nodes" << endl;

	delete test;
	return 0;
	*/

	//wallPost test("Here is my post", "Isla Vista");
	//test.getPost();
  
  //wall *test = new wall();
  //wallPost post1("Here is my first post", "Isla Vista");
  //wallPost post2("Here is another post!", "Goleta, CA");
  //wallPost post3("Im going to get deleted!", "Hell");
  //test->newPost(post1);
  //test->newPost(post2);
  //test->newPost(post3);
  //cout << "number of posts: " << test->getLL()->getCount() << endl;
  //test->getLL()->getHead()->getData().getPost();
  //test->getLL()->getTail()->getData().getPost();
  //test->displayWall();
  //test->deletePost(2);
  //test->displayWall();
  //cout << "number of posts: " << test->getLL()->getCount() << endl;
  //test->getLL()->getTail()->getData().getPost();
  //test->deletePost(0);
  //test->getLL()->getTail()->getData().getPost();
  //cout << "number of posts: " << test->getLL()->getCount() << endl;

  user newUser("jordannguyen","password","Jordan Nguyen","3/11/95");
  wallPost post1("test post", "iv");
  wallPost post2("another test post", "csil");
  newUser.addToWall(post1);
  newUser.addToWall(post2);
  wallPost post3("dont delete me!!!", "ucsb");
  newUser.addToWall(post3);
  //newUser.getWall().displayWall();
  //newUser.deleteWallPost(1);
  //newUser.getWall().displayWall();
  string info = newUser.userInfo();

  ofstream outfile;
  outfile.open("userInfo.txt");
  outfile << info << endl;
  outfile.close();
  
  return 0;
}
