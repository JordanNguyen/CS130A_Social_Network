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

	return 0;
}
