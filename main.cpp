#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(int argc, char *argv[])
{
	//Node<string> *test = new Node<string>("test");
	//test->printNode();

	LinkedList<string> *test = new LinkedList<string>;
	test->addTail("Here is the head");
	test->addTail("1");
	test->addTail("2");
	test->addTail("3");
	test->addTail("Tail here");
	test->getHead()->printNode();
	test->getTail()->printNode();
	test->getTail()->getPrev()->printNode();
	test->getTail()->getPrev()->getPrev()->printNode();
	test->getTail()->getPrev()->getPrev()->getPrev()->printNode();

	return 0;
}
