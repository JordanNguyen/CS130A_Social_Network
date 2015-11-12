#ifndef ARRAY_H
#define ARRAY_H
#include "List.h"
#include <stdexcept>

template <class T> class Array: public List<T> {

 private:

  T *pa;          // pointer to the beginning of array type T
  int length;     // length of spots in array
  int nextOpen;   // next open index of array


  
 public:

  //no arg constructor
  Array()
    {

      pa = new T[2];
      length = 2;
      nextOpen = 0;
    }

  /* //1 arg constructor
  Array(T item)
    {
      pa = new T[1];
      pa[0] = item;
      nextOpen = 1;
      length = 2;
      //spotsTaken = 1;
      //nextOpen = 1;
    }
  */
  
  //destructor
  ~Array()
    {
      delete [] pa;
    }
  
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
	for (int i = 0; i <= nextOpen; i++)
	  {
	    if (i < pos)
	      pnew[i] = pa[i];
	    if (i == pos)
	      pnew[i] = item;
	    if (i > pos && i <= nextOpen)
	      pnew[i] = pa[i-1];
	    //std::cout<< pnew[i] << std::endl;
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
	//std:: cout<<"array length has doubled" <<std::endl;
	for (int i = 0; i <= nextOpen; i++)
	  {
	    if (i < pos)
	      pnew[i] = pa[i];
	    if (i == pos)
	      pnew[i] = item;
	    if (i > pos && i <= nextOpen)
	      pnew[i] = pa[i-1];
	    //std::cout<< pnew[i] << std::endl;
	  }
	delete [] pa;
	pa = pnew;
	length = length*2;
	nextOpen++;
       }

    //std::cout<<"end of array"<<std::endl;
    return;
    
  }

  	/* Removes the element at position pos, shrinking the list by 1.
	*  pos must be between 0 and the current length of the list minus 1.
	*/
  void remove(int pos)
  {
    if (pos < 0 || pos >= nextOpen)
      {
	std::cout << "Invalid index. Must be between 0 and "
		<< nextOpen - 1 << std::endl;
	return;
      }

   
    // create a new array of same length
    // copy current array into new one, except for deleted position

    T *pnew = new T[length];
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
    //std::cout << "deletion complete" << std::endl;
    nextOpen--;
    return;

    
  }

	/* overwrites position pos in the list with item.
	*  does not change the length of the list.
	*  pos must be between 0 and the current length of the list minus 1.
	*/
  void set(int pos, const T & item)
  {
    if (pos < 0 || pos >= nextOpen)
      {
	std::cout << "Invalid index. Must be between 0 and "
		  << nextOpen - 1 << std::endl;
	return;
      }

    pa[pos] = item;
    //for (int i = 0; i < nextOpen; i++)
    //std::cout<< pa[i] << std::endl;
    return;
  }

	/* returns the item at position pos, not changing the list.
	*  pos must be between 0 and the current length of the list minus 1.
	*/
  T const & get(int pos) const
  {
    if (pos < 0 || pos >= nextOpen)
      {
	throw std::out_of_range("Position out of acceptable range.");
      }

    std::cout << "Returned: " << pa[pos] << std::endl;
    return pa[pos];
    
  }

  void printArray()
  {
    for (int i = 0; i < nextOpen; i++)
      {
	if (i < nextOpen-1)
	  std::cout<< pa[i] << ", ";
	if (i == nextOpen-1)
	  std::cout<< pa[i] << std::endl;
      }
  }
  
};

#endif
