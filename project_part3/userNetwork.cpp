#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <fstream>
#include <list>
#include "userNetwork.h"
using namespace std;

userNetwork::userNetwork()
{
  users = new list<user>;
}

userNetwork::~userNetwork()
{
  delete users;
}

void userNetwork::addUser(user u)
{
  string un = u.getUsername();
  std::list<user>::iterator it;	

  for (it = users->begin(); it != users->end(); ++it)
    {
      if (it->getUsername() == un)
	{
	  cout << "Username " << un << " already taken." << endl;
	  return;
	}
    }

  users->push_back(u);
  //cout << "New user successfully created!" << endl;
}

void userNetwork::deleteUser(int index)
{
  std::list<user>::iterator it;
  int i = 0;
  for (it = users->begin(), i = 0; i < index; ++i, ++it);
  users->erase(it);
  return;
}

/*void userNetwork::deleteUser(string t) 
  {
 	
  
  //empty list
  if (users->empty())
  return;
  //single entry
  if (users->getHead() == users->getTail() && users->getHead()->getData().getUsername() == t)
  {
  //Node<user> *temp = users->getHead();
  //delete temp;
  users->setHead(NULL);
  users->setTail(NULL);
  return;
  }

  //delete head
  if (users->getHead()->getData().getUsername() == t)
  {
  Node<user> *temp = users->getHead();
  users->setHead(users->getHead()->getNext());
  delete temp;
  return;
  }

  //delete tail
  if (users->getTail()->getData().getUsername() == t)
  {
  Node<user> *temp = users->getTail();
  users->setTail(users->getTail()->getPrev());
  users->getTail()->setNext(NULL);
  delete temp;
  return;
  }

  //anything else
  else
  {
  Node<user> *temp = users->getHead();
  while (temp != NULL)
  {
  if (temp->getData().getUsername() == t)
  {
  temp->getPrev()->setNext(temp->getNext());
  temp->getNext()->setPrev(temp->getPrev());
  delete temp;
  }
  temp = temp->getNext();
  }
  }

  return;
  }
*/

void userNetwork::printUsernames()
{
  if (users->empty())
    {
      cout << "empty user network" << endl;
      return;
    }

  std::list<user>::iterator it;
  for (it = users->begin(); it != users->end(); ++it)
    {
      cout << it->getUsername() << endl;
    }
}

bool userNetwork::checkUsername(string usr)
{
  std::list<user>::iterator it;
  for (it = users->begin(); it != users->end(); ++it)
    {
      if (it->getUsername() == usr)
	return true;
    }

  return false;
}

bool userNetwork::checkRealName(string rn)
{
  std::list<user>::iterator it;
  for (it = users->begin(); it != users->end(); ++it)
    {
      if (it->getRealName() == rn)
	return true;
    }

  return false;

}

int userNetwork::getUserIndex(string usr)
{
  std::list<user>::iterator it;
  int i = 0;
  for (it = users->begin(); it != users->end(); ++it)
    {
      if (it->getUsername() == usr)
	return i; 
      i++;
    }

  return -1;
}

bool userNetwork::checkLogin(string usr, string pw)
{
  std::list<user>::iterator it;
  
  for (it = users->begin(); it != users->end(); ++it)
    {
      if (it->getUsername() == usr)
	{
	  if (it->getPassword() == pw)
	    return true;
	  else
	    return false;
	}
    }
  return false;
}

user* userNetwork::getUser(string usr)
{
  std::list<user>::iterator it;
  
  for (it = users->begin(); it != users->end(); ++it)
    {
      if (it->getUsername()==usr)
      {
		return &(*it);
	  }
    }
    return &(*it);
}

user* userNetwork::getUserRealName(string usr)
{
	
  //user temp;
  std::list<user>::iterator it;
  
  for (it = users->begin(); it != users->end(); ++it)
    {
      if (it->getRealName()==usr)
		{
			// temp = *it;
			// return &temp;
			return &(*it);
		}
    }
 //  	temp = *it;
	// return &temp;
	return &(*it);
}

void userNetwork::removeFriend(string usr1, string usr2)
{
  user* temp1 = getUser(usr1);
  user* temp2 = getUser(usr2);

  if (checkUsername(usr1) && checkUsername(usr2))
    {
      temp1->getFriends()->remove(usr2);
      temp2->getFriends()->remove(usr1);
      std::cout << "*******************************" << std::endl;
      std::cout << "Your friend has been deleted." << std::endl;
      std::cout << "*******************************" << std::endl;
      return;
    }

  else
    std::cout<<"Could not delete friend."<<std::endl;
   
  return;
  
}

list<user>* userNetwork::getUserList()
{
  return users;
}

//write to userNetworkInput.txt in the correct format to be read back
void userNetwork::writeUserNetwork()
{

  ofstream outfile;
  outfile.open("userNetworkInput.txt");

  //string wholeUserNetwork = "";
  std::list<user>::iterator it;
  
  for (it = users->begin(); it != users->end(); ++it)
    {
      outfile << it->userInfoWrite();
      outfile << it->getWall().WallToStringWrite();
      outfile << "[/enduser]\n";
    }

  outfile.close();
  return;
}

// option 0 = friends list
// option 1 = friend requests
void userNetwork::writeFriends(int option)
{
  if (users->empty())
    {
      cout << "Error: No users to write" << endl;
    }

  ofstream outfile;
  if (option == 0)
    outfile.open("friendList.txt");
  else if (option == 1)
    outfile.open("friendRequests.txt");

  std::list<user>::iterator it;
  for (it = users->begin(); it != users->end(); ++it)
    {
      outfile << it->friendListWrite(option);
      outfile << "[/enduser]\n";
    }

  outfile.close();
  return;

}

void userNetwork::readUsers(const char* filename)
{
  ifstream infile(filename);
  //ifstream infile(file);
  string s = "";
  s.assign( (istreambuf_iterator<char>(infile) ), (istreambuf_iterator<char>() ));

  // delimiters to parse string
  string userDelim = "[/enduser]\n";
  string infoDelim = "[/endinfo]";
  string postDelim = "[/endwallposts]";
  string eachPost  = "[/endpost]";
  string newlDelim = "\n";

  // byte size
  size_t posUser = 0;
  size_t posInfo = 0;
  size_t posPost = 0;
  size_t pos1    = 0;
  size_t pos2    = 0;
  size_t pos3    = 0;

  // tokens to split up string
  string userToken;
  string infoToken;
  string postToken;
  string token1;
  string token2;
  string token3;

  // counters
  int infoCounter = 0;
  int postCounter = 0;

  // data members to save to usernetwork
  string un;  //username
  string pw;  //passwowrd
  string rn;  //real name
  string dob; //date of birth
  string wp;  //wall post
  string top; //time of post
  string loc; //location

  // find the end of first user
  while ((posUser = s.find(userDelim)) != string::npos) 
    {
      //save all the text to userToken
      userToken = s.substr(0, posUser);
      //cout << userToken << endl;
      //read in userToken and find the end of user info
      while ((posInfo = userToken.find(infoDelim)) != string::npos )
	{
	  infoToken = userToken.substr(0,posInfo);
	  //cout << infoToken << endl;
	  //parse through the user info
	  infoCounter = 0;
	  while ((pos1 = infoToken.find(newlDelim)) != string::npos)
	    {
	      token1 = infoToken.substr(0,pos1);
	      //cout << token1 << endl;
	      //cout << infoCounter << endl;
	      if (infoCounter == 0)
		{
		  un = token1;
		  //cout << un << endl;
		}
	      if (infoCounter == 1)
		{	
		  pw = token1;
		  //cout << pw << endl;
		}
	      if (infoCounter == 2)
		{
		  rn = token1;
		  //cout << rn << endl;
		}

	      infoCounter++;
	      infoToken.erase(0, pos1+newlDelim.length());
	    }
	  dob = token1;
	  //cout << dob << endl;
	  //user newUser(un,pw,rn,dob);
	  userToken.erase(0, posInfo + infoDelim.length());
			
			
	}
      user newUser(un,pw,rn,dob);
		
      //start parsing through the wall posts
      while ((posPost = userToken.find(postDelim)) != string::npos)
	{
	  //get the whole string of wall posts per each user
	  postToken = userToken.substr(0, posPost);
	  //parse through the wall posts and divide it into individual posts
			
	  while ((pos2 = postToken.find(eachPost)) != string::npos)
	    {
	      // get each individual post
	      token2 = postToken.substr(0,pos2);
	      //cout << token2 << endl;
	      postCounter = 0;
	      while ((pos3 = token2.find(newlDelim)) != string::npos)
		{
		  //divide up each post into parts separated by newlines
		  token3 = token2.substr(0,pos3);
		  //cout<<token3<<endl<<endl;
		  //cout << postCounter  << endl;
		  if (postCounter == 1)
		    {	
		      wp = token3;
		      //cout << wp << endl << endl;
		    }
		  if (postCounter == 2)
		    {
		      top = token3;
		      //cout << top << endl << endl;
		    }
					
		  postCounter++;
		  token2.erase(0, pos3+newlDelim.length());
		}

	      loc = token3;
	      //cout << loc << endl << endl;
	      postToken.erase(0,pos2+eachPost.length());
	      wallPost newPost(wp,top,loc); //we chagned this line
	      newUser.addToWall(newPost);
	    }
	  userToken.erase(0, posPost + postDelim.length());
			
			
	}
      addUser(newUser);
      s.erase(0, posUser + userDelim.length());
    }		

  infile.close();
}
	
/* readFriends takes in a formated text file
 *  as well as an option to read a friend list or
 *  a friend request list. 
 *  0 = friends list, 1 = friend request
 */
void userNetwork::readFriends(const char* filename, int option)
{

  // read in input file
  ifstream infile(filename);
  string s = "";
  s.assign( (istreambuf_iterator<char>(infile) ), (istreambuf_iterator<char>() ));

  // delimiters to parse string
  string userDelim   = "[/enduser]\n";    //identifies end of user list
  string nameDelim   = "[/username]\n";   //identifies whose list you are looking at
  string frndDelim   = "[/endfriends]"; //identifies end of friend list (not necessary?)
  string newlDelim   = "\n";              //identifies end of each username

  // byte size
  size_t pos1 = 0;
  size_t pos2 = 0;
  size_t pos3 = 0;
  size_t pos4 = 0;
  size_t pos5 = 0;
  
  // tokens to split up string
  string userToken;
  string nameToken;
  string frndToken;
  string username;
  string frnd;

  // counters, dont think I need

  // data members saved
  string un; //username
  string fr; //friend

  // find the end of first user
  while ((pos1 = s.find(userDelim)) != string::npos)
    {
      //save all the text to userToken
      userToken = s.substr(0, pos1);
      user* temp; //changed this

      //read in userToken and find user name
      while ((pos2 = userToken.find(nameDelim)) != string::npos)
	{
	  // save the text to nameToken
	  nameToken = userToken.substr(0,pos2);

	  //get the user name
	  int counter = 0;
	  while ((pos3 = nameToken.find(newlDelim)) != string::npos)
	    {
	      if (counter == 0)
		username = nameToken.substr(0,pos3);

	      counter++;
	      nameToken.erase(0, pos3+newlDelim.length());
	    }

	  userToken.erase(0, pos2+nameDelim.length());
	}

      //set temp equal to the user so we can modify it
      temp = getUser(username); 

      //parse and find the friend delimiter
      while ((pos4 = userToken.find(frndDelim)) != string::npos)
	{
	  //save the string to friendToken
	  frndToken = userToken.substr(0,pos4);

	  // get friend names, save them to the appropriate linkedlist
	  while ((pos5 = frndToken.find(newlDelim)) != string::npos)
	    {
	      frnd = frndToken.substr(0,pos5);
	      if (frnd != "\n")
		{
		  if (option == 0)
		    temp->addFriend(frnd); //changed this
		  else if (option == 1)
		    temp->addRequest(frnd); //changed this
		}

	      frndToken.erase(0, pos5+newlDelim.length());
	    }

	  userToken.erase(0, pos4+frndDelim.length());
	}

      s.erase(0, pos1+userDelim.length());

    }

  infile.close();
}
	    




