#ifndef POSTRESPONSE_H
#define POSTRESPONSE_H
uing namespace std;

class postResponse {

 private:

  string text;
  string timeOfPost;
  string author;

 public:

  postResponse();
  postResponse(string t, string a);
  ~wallPost();

  void setText(string t);
  string getText();
  string getAuthor();
  string getRespDisp();
  string getRespWrite();
};

#endif
