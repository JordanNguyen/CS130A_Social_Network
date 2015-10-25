#ifndef ARRAY_H
#define ARRAY_H
#include "List.h"

template <class T> class Array: public List<T> {

 private:

  T *pa;        // pointer to the beginning of array type T
  int length;   // length of available spots in array
  int nextOpen; // next open index of array

  
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
      pa = new T[1];
      pa[0] = 0;
      length = 1;
      nextOpen = 0;
      
    }

  //1 arg constructor
  Array(T item)
    {
      pa = new T[1];
      pa[0] = item;
      length = 2;
      nextOpen = 1;
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
    if (pos >= length || pos < 0)
      {
      std::cout << "Invalid index. Must be between 0 and "
		<< length - 1 << std::endl;
      }

    // empty array
    // (pos == 0 && nextOpen == 0)
      //
	//[0] = item;
	//ngth = 1;
	//xtOpen = 1;
	//

    // delcare new array with more space
    T *pnew = new T[length * 2];
    for (int i = 0; i < length*2; i++)
      {
	if (i < pos)
	  pnew[i] = pa[i];
	if (i == pos)
	  pnew[i] = item;
	if (i > pos && i <= length)
	  pnew[i] = pa[i-1];
	if (i > pos && i > length)
	  pnew[i] = 0;
	std::cout<< pnew[i] << std::endl;
      }

    // set pa = to new bigger array
    delete [] pa;
    pa = pnew;
    length = length*2;
    std::cout<<"end of array"<<std::endl;
    return;
    
  }

  	/* Removes the element at position pos, shrinking the list by 1.
	*  pos must be between 0 and the current length of the list minus 1.
	*/
  void remove(int pos)
  {
    return;
  }

	/* overwrites position pos in the list with item.
	*  does not change the length of the list.
	*  pos must be between 0 and the current length of the list minus 1.
	*/
  void set(int pos, const T & item)
	{
	  return;
	}

	/* returns the item at position pos, not changing the list.
	*  pos must be between 0 and the current length of the list minus 1.
	*/
  //T const & get(int pos) const
  
  
};

#endif
