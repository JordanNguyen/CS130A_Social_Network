#ifndef WALLPOST_H
#define WALLPOST_H
using namespace std;

class wallPost {

private:

	string text;
	//time of post
	string location;

public:

	wallPost();
	wallPost(string t, string l);
	~wallPost();

	void printPost();
	string getText();
	void setText(string t);
	//get time
	string getLocation();
	void setLocation(string l);

};

#endif