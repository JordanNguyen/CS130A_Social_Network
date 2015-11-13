#ifndef WALLPOST_H
#define WALLPOST_H
using namespace std;

class wallPost {

private:

	string text;
	string timeOfPost;
	string author;

public:

	wallPost();
	wallPost(string t, string a);
	wallPost(string t, string top, string a);
	~wallPost();

	string getPost();
	string getPostWrite();
	string getText();
	string getAuthor();
	void setAuthor(string t);
	void setText(string t);
	string getTimeOfPost();
	void setTimeOfPost(string t);

};

#endif
