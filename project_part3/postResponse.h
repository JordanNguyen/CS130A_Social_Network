#ifndef POSTRESPONSE_H
#define POSTRESPONSE_H
using namespace std;

class postResponse {

 private:

  string text;
  string timeOfPost;
  string author;

 public:

  postResponse();
  postResponse(string t, string a);
  postResponse(string t, string top, string a);
  ~postResponse();

  void setText(string t);
  string getText();
  string getAuthor();
  string getRespDisp();
  string getRespWrite();
};

#endif
