#ifndef LINK_H
#define LINK_H

template <class T> class NodeT {
  private:
	T data;
	NodeT<T> *prev;
	NodeT<T> *next;
	//static int count;

  public:
	NodeT(T value);
	NodeT();
	~NodeT();

	void setValue(T value);
	void setNext(NodeT *next);
	T getValue();
	NodeT *getPrev();
	NodeT *getNext();
	static int getCount();

	void printNodeT();
};

#endif
