#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <list>
#include "wallPost.h"
using namespace std;

wallPost::wallPost() 
{
	text = "";
	postlocation = "";
	author = "";
	
	time_t currentTime;
	struct tm *timeinfo;
	time(&currentTime);
	timeinfo = localtime(&currentTime);
	timeOfPost = asctime(timeinfo);
	timeOfPost.erase(timeOfPost.end()-1);
	timeOfPost.erase(timeOfPost.end()-1);
}

wallPost::wallPost(string t, string l, string a) 
{
	text = t;
	postlocation = l;
	author = a;
	time_t currentTime;
	struct tm *timeinfo;
	time(&currentTime);
	timeinfo = localtime(&currentTime);
	timeOfPost = asctime(timeinfo);
	timeOfPost.erase(timeOfPost.end()-1);
	timeOfPost.erase(timeOfPost.end()-1);

}

wallPost::wallPost(string t, string l) 
{
	text = t;
	postlocation = l;
	author = "";
	time_t currentTime;
	struct tm *timeinfo;
	time(&currentTime);
	timeinfo = localtime(&currentTime);
	timeOfPost = asctime(timeinfo);
	timeOfPost.erase(timeOfPost.end()-1);
	timeOfPost.erase(timeOfPost.end()-1);

}


wallPost::~wallPost() {

}

string wallPost::getPost()
{
	string wholePost;
	wholePost = text + "\n" + "Time of post: " + timeOfPost + "\n" +
	"Author: " + author + "\n\n";

	//std::cout << wholePost;
	return wholePost;
       
}

string wallPost::getPostWrite()
{
	string wholePost;
	wholePost = text + "\n" + timeOfPost + "\n" + author + "\n" + "[/endpost]";
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

string wallPost::getPostLocation()
{
	return postlocation;
}

void wallPost::setPostLocation(string l)
{
	postlocation = l;
}

string wallPost::getAuthor()
{
	return author;
}

void wallPost::setAuthor(string t)
{
	author = t;
}

