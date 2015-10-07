#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
#include "NodeT.cpp"

int main(int argc, char *argv[])
{
	NodeT<int> *test = new NodeT<int>(5);
	test->printNodeT();
	test->setValue(7);
	test->printNodeT();
	return 0;
}