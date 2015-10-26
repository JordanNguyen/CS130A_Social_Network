#ifndef ARRAY_H
#define ARRAY_H
#include "List.h"

template <class T> class Array: public List<T> {

 private:

  T *pa;          // pointer to the beginning of array type T
  int length;     // length of available spots in array
  int nextOpen; // next open index of array
  //int spotsTaken; // number of spots taken in array

  
 public:

  //no arg constructor
  Array()
    {
      // allocate new memory for array
      /*
      pa = new T[10];
      for (int i = 0; i < 10; i++)
	pa[i] = 0;
      
      length = 10;
      nextOpen = 0;
      */
      pa = new T[2];
      length = 2;
      nextOpen = 0;
      //spotsTaken = 0;
      //nextOpen = 0;
      
    }

  //1 arg constructor
  Array(T item)
    {
      pa = new T[1];
      pa[0] = item;
      nextOpen = 1;
      length = 2;
      //spotsTaken = 1;
      //nextOpen = 1;
    }

  //destructor
  ~Array()
    {
      delete [] pa;
    }

  // overwrite [] operator just in case
  /*
  T& operator[] (int index)
    {
      T *newA;
      if (index >= length)
	{
	  // allocate more space if trying
	  // to access above length
	  newA = new T[index + 10];
	  for (int i = 0; i < nextOpen; i++)
	    newA[i] = pa[i];
	  for (int j = nextOpen; j < index + 10; j++)
	    newA[j] = 0;
	  length = index+10;
	  delete [] pa;
	  pa = newA;
	}

      if (index > nextOpen)
	nextOpen = index + 1;
      return *(pa + index);
    }
  */
  
  /* Inserts the item right before position pos, growing the list by 1
   *  pos must be between 0 and the current length of the list.
   */
  void insert(int pos, const T & item)
  {
    if (pos > nextOpen || pos < 0)
      {
      std::cout << "Invalid index. Must be between 0 and "
		<< nextOpen  << std::endl;
      return;
      }

    // inserting into array when there is still space, dont
    // allocate more space
    if (nextOpen < length)
      {
	T *pnew = new T[length];
	for (int i = 0; i < nextOpen+1; i++)
	  {
	    if (i < pos)
	      pnew[i] = pa[i];
	    if (i == pos)
	      pnew[i] = item;
	    if (i > pos && i < nextOpen+1)
	      pnew[i] = pa[i-1];
	    std::cout<< pnew[i] << std::endl;
	  }
	nextOpen++;
	delete [] pa;
	pa = pnew;
      }
    

    // delcare new array with more space when necessary
    // if you insert to the array and there is no more space

    else if (nextOpen  == length)
      {
	T *pnew = new T[length * 2];
	std:: cout<<"array length has doubled" <<std::endl;
	for (int i = 0; i < nextOpen+1; i++)
	  {
	    if (i < pos)
	      pnew[i] = pa[i];
	    if (i == pos)
	      pnew[i] = item;
	    if (i > pos && i < nextOpen+1)
	      pnew[i] = pa[i-1];
	    std::cout<< pnew[i] << std::endl;
	  }
	delete [] pa;
	pa = pnew;
	length = length*2;
	nextOpen++;
       }

    std::cout<<"end of array"<<std::endl;
    return;
    
  }

  	/* Removes the element at position pos, shrinking the list by 1.
	*  pos must be between 0 and the current length of the list minus 1.
	*/
  void remove(int pos)
  {
    if (pos < 0 || pos > nextOpen)
      {
	std::cout << "Invalid index. Must be between 0 and "
		<< nextOpen - 1 << std::endl;
	return;
      }

   
    // create a new array of length - 1
    // copy current array into new one, except for deleted position

    T *pnew = new T[length-1];
    for (int i = 0; i < nextOpen-1; i++)
      {
	if (i < pos)
	  pnew[i] = pa[i];
	if (i >= pos)
	  pnew[i] = pa[i + 1];
	//std::cout << pnew[i] << std::endl;
      }

    delete [] pa;
    pa = pnew;
    length--;
    std::cout << "deletion complete" << std::endl;
    nextOpen--;
    return;

    
  }

	/* overwrites position pos in the list with item.
	*  does not change the length of the list.
	*  pos must be between 0 and the current length of the list minus 1.
	*/
  void set(int pos, const T & item)
  {
    if (pos < 0 || pos > nextOpen)
      {
	std::cout << "Invalid index. Must be between 0 and "
		  << nextOpen - 1 << std::endl;
	return;
      }

    pa[pos] = item;
    for (int i = 0; i < nextOpen; i++)
      std::cout<< pa[i] << std::endl;
    return;
  }

	/* returns the item at position pos, not changing the list.
	*  pos must be between 0 and the current length of the list minus 1.
	*/
  T const & get(int pos) const
  {
    try
      {
	if (pos < 0 || pos >= length)
	  {
	    // std::cout << "Invalid index. Must be between 0 and "
	    //	      << length - 1 << std::endl;
	    throw pos;
	  }
      }

    catch (int e)
      {
	std::cout << "An exception occured. Invalid input " << e << std::endl;
	return 0;
      }

    std::cout << "Returned: " << pa[pos] << std::endl;
    return pa[pos];
    
  }
  
  
};

#endif
