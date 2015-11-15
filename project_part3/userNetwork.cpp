#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <fstream>
#include <list>
#include <sstream>
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

void userNetwork::deleteUser(string name)
{
  std::list<user>::iterator it;
  for (it = users->begin(); it != users->end(); ++it)
    {
      if (it->getUsername() == name)
	{
	  users->erase(it);
	  return;
	}
    }
  
  return;
}


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
  //outfile.open("test.txt");

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
  string origPost  = "[/origpost]\n";
  string eachResp  = "[/endresp]\n";
  string allResp   = "[/endallresp]";
  string newlDelim = "\n";

  // byte size
  size_t posUser = 0;
  size_t posInfo = 0;
  size_t posPost = 0;
  size_t pos1    = 0;
  size_t pos2    = 0;
  size_t pos3    = 0;
  size_t pos4    = 0;
  size_t pos5    = 0;
  size_t pos6    = 0;
  size_t pos7    = 0;

  // tokens to split up string
  string userToken;
  string infoToken;
  string postToken;
  string token1;
  string token2;
  string token3;
  string token4;
  string token5;
  string token6;
  string token7;

  // counters
  int infoCounter = 0;
  int postCounter = 0;
  int respCounter = 0;

  // data members to save to usernetwork
  string un;  //username
  string pw;  //passwowrd
  string rn;  //real name
  string dob; //date of birth
  string wp;  //wall post
  string top; //time of post
  string author; //post author
  string rwp; //response post
  string rtop; //response time
  string raut; //response author

  user *newUser = NULL;
  wallPost *newpost = NULL;
  postResponse *newResp = NULL;

  // find the end of first user
        cout << "looking for userDelim" << endl;
  while ((posUser = s.find(userDelim)) != string::npos) 
    {
      //save all the text to userToken
      userToken = s.substr(0, posUser);

            cout << "looking for infoDelim" << endl;
      //read in userToken and find the end of user info
      while ((posInfo = userToken.find(infoDelim)) != string::npos )
	{
	  infoToken = userToken.substr(0,posInfo);

	  //parse through the user info
	  infoCounter = 0;
	  while ((pos1 = infoToken.find(newlDelim)) != string::npos)
	    {
	      token1 = infoToken.substr(0,pos1);

	      if (infoCounter == 0)
		{
		  un = token1;
		}
	      if (infoCounter == 1)
		{	
		  pw = token1;
		}
	      if (infoCounter == 2)
		{
		  rn = token1;
		}

	      infoCounter++;
	      infoToken.erase(0, pos1+newlDelim.length());
	    }
	  dob = token1;
	  userToken.erase(0, posInfo + infoDelim.length());        		
	}
      //create the new user
      //user newUser(un,pw,rn,dob);
      newUser = new user(un,pw,rn,dob);
      cout<<"user created"<<endl;
		
      //start parsing through the wall posts [/endwallposts]
      while ((posPost = userToken.find(postDelim)) != string::npos)
	{
	  //get the whole string of wall posts per each user
	  postToken = userToken.substr(0, posPost);
	  
	  //parse through the wall posts and divide it into individual posts [/endpost]
	  while ((pos2 = postToken.find(eachPost)) != string::npos)
	    {
	      // get each individual post
	      token2 = postToken.substr(0,pos2);

	      // find the original post by user, before responses [/origpost]
	      while ((pos3 = token2.find(origPost)) != string::npos)
		{
		  //divide up each post into parts separated by newlines
		  token3 = token2.substr(0,pos3);
		  postCounter = 0;
		  //divide up by newlines and get the post info \n
		  while ((pos4 = token3.find(newlDelim)) != string::npos)
		    {
		      token4 = token3.substr(0,pos4);
		      if (postCounter == 1)
			{	
			  wp = token4;
			}
		      if (postCounter == 2)
			{
			  top = token4;
			}
					
		      postCounter++;
		      token3.erase(0, pos4+newlDelim.length());
		    }
		  
		  author = token4;
		  token2.erase(0,pos3+origPost.length());
		  //wallPost newpost(wp,top,author);
		  newpost = new wallPost(wp,top,author);
		  newUser->addToWall(*newpost);
		  cout<<"wallpost added to user"<<endl;
		}
	      //newUser.addToWall(newPost);
	      
	      //find all responses
	      while ((pos5 = token2.find(allResp)) != string::npos)
		{
		  token5 = token2.substr(0,pos5);

		  //find each individual response
		  while ((pos6 = token5.find(eachResp)) != string::npos)
		    {
		      token6 = token5.substr(0,pos6);
		      respCounter = 0;
		      //divide up each response by newlines and get the response info
		      while ((pos7 = token6.find(newlDelim)) != string::npos)
			{
			  token7 = token6.substr(0,pos7);
			  if (respCounter == 0)
			    {
			      rwp = token7;
			    }
			  if (respCounter == 1)
			    {
			      rtop = token7;
			    }
			  respCounter++;
			  token6.erase(0, pos7+newlDelim.length());
			}
		      raut = token7;
		      token5.erase(0,pos6+eachResp.length());
		      newResp = new postResponse(rwp, rtop, raut);
		      newpost->addResponse(*newResp);
		      cout << "response added" <<endl;
		    }
		  token2.erase(0,pos5+allResp.length());
		  //postResponse newResp(rwp, rtop, raut);
		  //newpost.AddResponse(newResp);
		}
		  
	      postToken.erase(0, pos2 +  eachPost.length());
	    }
	   userToken.erase(0, posPost + postDelim.length());
	}
      addUser(*newUser);
      s.erase(0, posUser+userDelim.length());
      cout << "user added" <<endl;
    }
  infile.close();
  delete newUser;
  delete newpost;
  delete newResp;
  cout << "end of function" << endl;
  return;
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

void userNetwork::degreeOfSeparation(string usr1)
{
  //mark all the users as not visited
  list<string> visited;

  //created a queue for BFS
  list<string> queue;

  //marked the current user as visited and enqueue it
  visited.push_back(usr1);
  queue.push_back(usr1);

  // it will be used to get all adjacent vertices (friends) of a user
  std::list<string>::iterator it;

  while (!queue.empty())
  {
    //dequeue a user from queue and print it
    usr1 = queue.front();
    cout << usr1 << " ";
    queue.pop_front();

    //get all the adjacent vertices (friends) of the dequeued user usr1
    //if an adjacent user has not been visited, then mark it visited and enqueue it
    user *temp = getUser(usr1);
    for (it = temp->getFriends()->begin(); it != temp->getFriends()->end(); ++it)
    {
      //check if the friend has been visited or not yet
      if (!checkVisited(*it, visited))
      {
        visited.push_back(*it);
        queue.push_back(*it);
      }
    }
  }
  std::cout<<endl;  
}

bool userNetwork::checkVisited(string usr, list<string> ls)
{
  std::list<string>::iterator it;
  it = ls.begin();
  while (it != ls.end())
  {
    if (usr == *it)
      return true;
    ++it;
  }

  return false;
}

//generate 10,000 users
void userNetwork::generateUsers()
{
  int i = 1;
  string un, rn;
  string pw = "password";
  string dob = "11/14/15";

  for (i = 1; i <= 10000; i++)
  {
    ostringstream convert;
    convert << i;
    un = "user" + convert.str();
    rn = "First Last" + convert.str();
    user temp(un,pw,rn,dob);
    addUser(temp);
  }

}




