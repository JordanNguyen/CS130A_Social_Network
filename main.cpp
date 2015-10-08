#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(int argc, char *argv[])
{
	//Node<string> *test = new Node<string>("test");
	//test->printNode();

	LinkedList<int> *test = new LinkedList<int>;
	test->addTail(100);
	test->addTail(101);
	test->addTail(103);
	test->addTail(104);
	test->addTail(6969);
	test->getHead()->printNode();
	test->getTail()->printNode();
	test->getTail()->getPrev()->printNode();
	test->getTail()->getPrev()->getPrev()->printNode();
	test->getTail()->getPrev()->getPrev()->getPrev()->printNode();

	return 0;
}
