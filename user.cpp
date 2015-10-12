#include <cstdlib>
#include <cstido>
#include <iostream>
#include "wallPost.h"
#include "wall.h"
#include "User.h"
using namespace std;

user::user()
{
  username = "";
  password = "";
  realName = "";
  age = 0;
}

user::~user() {

}

void user::setUsername(string t) {
  username = t;
}

void user::setPassword(string t) {
  password = t;
}

void user::setRealName(string t) {
  realName = t;
}

void user::setAge(int i) {
  age = i;
}

string user::userInfo() {
  string info;
  info = "\n" + "username: " + username + "\n"
  + "password: " + password + "\n" + "real name: "
  + realName + "\n" + "age: " + age + "\n";

  std::cout << info;
  return info;
}
