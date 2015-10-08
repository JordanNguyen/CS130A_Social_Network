#ifndef NODE_H
#define NODE_H

template <class T> class Node {
  private:
	T data;
	Node *prev;
	Node *next;

  public:
	Node(T v)
	  {
	    data = v;
	    prev = NULL;
	    next = NULL;
	    std::cout << "Node Created!" << std::endl;
	  }
	Node()
	  {
	    data = 0;
	    prev = NULL;
	    next = NULL;
	  }
	~Node() {}

	void setValue(T v)      {data = v;}
	void setNext(Node *n)   {next = n;}
	void setPrev(Node *p)   {prev = p;}
	T getData()             {return data;} 
	Node *getPrev()         {return prev;}
	Node *getNext()         {return next;}
	void printNode()        {std::cout << data << std::endl;}
};

#endif
