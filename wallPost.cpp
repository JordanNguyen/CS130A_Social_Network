#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "wallPost.h"
using namespace std;

wallPost::wallPost() 
{
	text = "";
	location = "";
}

wallPost::wallPost(string t, string l) 
{
	text = t;
	location = l;
}

wallPost::~wallPost() {

}

void wallPost::printPost()
{
	std::cout << text << endl
	<< "Time of post: " << endl
	<< "Location: " << location << endl;
}

string wallPost::getText()
{
	return text;
}

void wallPost::setText(string t)
{
	text = t;
}

string wallPost::getLocation()
{
	return location;
}

void wallPost::setLocation(string l)
{
	location = l;
}

