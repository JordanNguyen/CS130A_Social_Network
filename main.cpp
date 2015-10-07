#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
<<<<<<< HEAD
#include "NodeT.cpp"

int main(int argc, char *argv[])
{
	NodeT<int> *test = new NodeT<int>(5);
	test->printNodeT();
	test->setValue(7);
	test->printNodeT();
=======
#include "Node.h"

int main(int argc, char *argv[])
{
	Node<string> *test = new Node<string>("test");
	test->printNode();
>>>>>>> 4b7777928ba6c4c7fd8cbf0fa90ddce67e6880f7
	return 0;
}
