#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <list>
#include "postResponse.h"
using namespace std;

postResponse::postResponse()
{
  text = "";
  timeOfPost = "";
  author = "";
}

postResponse::postResponse(string t, string a)
{
  text = t;
  author = a;
  time_t currentTime;
  struct tm *timeinfo;
  time(&currentTime);
  timeinfo = localtime(&currentTime);
  timeOfPost = asctime(timeinfo);
  timeOfPost.erase(timeOfPost.end()-1);
  timeOfPost.erase(timeOfPost.end()-1);
}

//constructor used when reading from file
postResponse::postResponse(string t, string top, string a)
{
  text = t;
  timeOfPost = top;
  author = a;
}
			   
postResponse::~postResponse()
{
  
}

void postResponse::setText(string t)
{
  text = t;
}

string postResponse::getText()
{
  return text;
}

string postResponse::getAuthor()
{
  return author;
}

string postResponse::getTime()
{
  return timeOfPost;
}

string postResponse::getRespDisp()
{
  string resp;
  resp += text + "\n";
  resp += "   Time of post: " + timeOfPost + "\n";
  resp += "   Author: " + author + "\n";

  return resp;
}

string postResponse::getRespWrite()
{
  string resp;
  resp = text + "\n" + timeOfPost + "\n" + author + "\n" + "[/endresp]";
  return resp;
}
