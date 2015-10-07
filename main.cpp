#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "Node.h"

int main(int argc, char *argv[])
{
	Node<string> *test = new Node<string>("test");
	test->printNode();
	return 0;
}
