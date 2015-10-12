#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include "wallPost.h"
using namespace std;

wallPost::wallPost() 
{
	text = "";
	location = "";
	
	time_t currentTime;
	struct tm *timeinfo;
	time(&currentTime);
	timeinfo = localtime(&currentTime);
	timeOfPost = asctime(timeinfo);
}

wallPost::wallPost(string t, string l) 
{
	text = t;
	location = l;
	time_t currentTime;
	struct tm *timeinfo;
	time(&currentTime);
	timeinfo = localtime(&currentTime);
	timeOfPost = asctime(timeinfo);
	cout << "wallPost created!" << endl;
}

wallPost::~wallPost() {

}

string wallPost::getPost()
{
	string wholePost;
	wholePost = text + "\n" + "Time of post: " + timeOfPost
	+ "Location: " + location + "\n";

	//std::cout << wholePost;
	return wholePost;
       
}

string wallPost::getText()
{
	return text;
}

void wallPost::setText(string t)
{
	text = t;
}

string wallPost::getTimeOfPost()
{
	return timeOfPost;
}

void wallPost::setTimeOfPost(string t)
{
	timeOfPost = t;
}

string wallPost::getLocation()
{
	return location;
}

void wallPost::setLocation(string l)
{
	location = l;
}

