#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <fstream>
#include "userNetwork.h"
using namespace std;

userNetwork::userNetwork()
{
  users = new LinkedList<user>;
}

userNetwork::~userNetwork()
{
  delete users;
}

void userNetwork::addUser(user u)
{
	string un = u.getUsername();
	Node<user> *temp = users->getHead();
	
	while (temp != NULL)
	{
		if (un == temp->getData().getUsername())
		{
			cout << "Username " << un << " already taken." << endl;
			return;
		}
		temp = temp->getNext();
	}

  	users->addTail(u);
}

void userNetwork::deleteUser(string t) 
{
 	
  
 	//empty list
  	if (users->getHead() == NULL && users->getTail() == NULL)
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

void userNetwork::printUsernames()
{
	if (users->getHead() == NULL)
	{
		cout << "empty user network" << endl;
		return;
	}

	Node<user> *temp = users->getHead();
	while (temp != NULL)
	{
		cout << temp->getData().getUsername() << endl;
		temp = temp->getNext();
	}
}

LinkedList<user>* userNetwork::getULL()
{
	return users;
}

void userNetwork::writeUserNetwork()
{
	if (users->getHead() == NULL)
	{
		cout << "Error: No users to write" << endl;
		return;
	}

	ofstream outfile;
	outfile.open("userNetwork.txt");

	// need username, pw, realname, dob, and all wallposts
	string wholeUserNetwork = "";
	Node<user> *temp = users->getHead();
	while (temp != NULL)
	{
		outfile << temp->getData().userInfo() << endl;
		temp = temp->getNext();
	}

	outfile.close();
	return;
	
}

void userNetwork::readUsers()
{
	ifstream infile("userNetworkInput.txt");
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
				wallPost newPost(wp,top,loc);
				newUser.addToWall(newPost);
			}
			userToken.erase(0, posPost + postDelim.length());
			
			
		}
		addUser(newUser);
		s.erase(0, posUser + userDelim.length());
	}		

	infile.close();
}
	





