#ifndef WALLPOST_H
#define WALLPOST_H

class wallPost {

private:

	string text;
	//time of post
	string location;

public:

	wallPost();
	wallPost(string t, string l);
	~wallPost();

	string printPost();
	string getPost();
	void setPost(string t);
	//get time
	string getLocation();
	string setLocation(string l);

}