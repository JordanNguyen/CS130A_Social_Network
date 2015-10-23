#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <fstream>
#include "LinkedList.h"
#include "wallPost.h"
#include "wall.h"
#include "user.h"
#include "userNetwork.h"
#include "socialNetwork.h"
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
  // wallPost post1("Here is my first post", "Isla Vista");
  // wallPost post2("Here is another post!", "Goleta, CA");
  // wallPost post3("Im going to get deleted!", "Hell");
  // test->newPost(post1);
  // test->newPost(post2);
  // test->newPost(post3);
  // test->displayWall();
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

  // user newUser("jordannguyen","password","Jordan Nguyen","3/11/95");
  // wallPost post1("test post", "iv");
  // wallPost post2("another test post", "csil");
  // newUser.addToWall(post1);
  // newUser.addToWall(post2);
  // wallPost post3("dont delete me!!!", "ucsb");
  // newUser.addToWall(post3);
  //newUser.getWall().displayWall();
  //newUser.deleteWallPost(1);
  //newUser.getWall().displayWall();
  // string info = newUser.userInfo();
  // cout << info << endl;

  //ofstream outfile;
  //outfile.open("userInfo.txt");
  //outfile << info << endl;
  //outfile.close();

  //delete test;

  //string testing = "Post 1\n10:30\nIV\n \nPost 2\n9:20\nGoleta\n \nPost 3\n4:30\nthe beach\n \n";
  
  //test->readWall(testing);
  //cout << "number of posts: " << test->getLL()->getCount() << endl;
  //cout << test->WallToString();

  // string userinfo = "Jordannguyen\npassword\nJordan Nguyen\n03/11/95\n  \nI am making my first post\n";
  // userinfo += "10:50 AM\nGoleta\n \nHere is another post\n3:14 PM\nCA\n \n";
  // user newUser(userinfo);
  // cout << newUser.userInfo() << endl;

  //userNetwork *un = new userNetwork();
  //un->readUsers("userNetworkInput.txt");
  //un->printUsernames();
  //user newUser("jnguyen","password1","Jordan Nguyen","March 3");
  //user newUser1("bwicka","password2","Brandon Wicka","Oct 13");
  //wallPost post1("Here is my first post!", "Isla Vista");
  //newUser.addToWall(post1);
  //wallPost post2("I love coding", "CodersSB");
  //newUser.addToWall(post2);
  //wallPost post3("I like coding a lot too", "Goleta");
  //newUser1.addToWall(post3);
  //user newUser2("billy","password3","realname","march 3");
  //user newUser3("billy","password4","realname","march 3");
  //user newUser4("jojo","password4","realname","march 3");
  //un->addUser(newUser);
  //un->addUser(newUser1);
  //un->writeUserNetwork();
  //un->addUser(newUser2);
  //un->addUser(newUser3);
  //un->addUser(newUser4);
  //out << un->getULL()->getTail()->getData().getUsername() << endl;
  //cout << un->getULL()->getTail()->getPrev()->getData().getUsername() << endl;
  //un->printUsernames();
  //un->deleteUser("user2");
  //cout << un->getULL()->getHead()->getData().userInfo() << endl;
  //cout << un->getULL()->getHead()->getNext()->getData().userInfo() << endl;
  //cout << un->getULL()->getTail()->getData().userInfo() << endl;
  //un->printUsernames();
  //un->deleteUser("jordannguyen");
  //un->printUsernames();
  //un->deleteUser("user3");
  //un->printUsernames();
  //cout << un->getULL()->getTail()->getData().getUsername() << endl;
  //un->deleteUser("user1");
  //un->printUsernames();
  //cout << un->getULL()->getHead()->getData().userInfo() << endl;
  //un->deleteUser("bwicka");
  //cout << un->getULL()->getHead()->getData().userInfo() << endl;
  //cout << un->getULL()->getHead()->getNext()->getData().getPassword() << endl;
  //cout << un->getULL()->getTail()->getData().getPassword() << endl;

  return 0;
}
