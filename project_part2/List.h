#ifndef LIST_H
#define LIST_H

template class<T>
class list {

public:

	/* Inserts the item right before position pos, growing the list by 1
	*  pos must be between 0 and the current length of the list.
	*/
	virtual void insert(int pos, const T & item);

	/* Removes the element at position pos, shrinking the list by 1.
	*  pos must be between 0 and the current length of the list minus 1.
	*/
	virtual void remove(int pos);

	/* overwrites position pos in the list with item.
	*  does not change the length of the list.
	*  pos must be between 0 and the current length of the list minus 1.
	*/
	virtual void set(int pos, const T & item);

	/* returns the item at position pos, not changing the list.
	*  pos must be between 0 and the current length of the list minus 1.
	*/
	virtual T const & get(int pos) const;

};

#endif