/********************************************
*** PLEASE PUT YOUR NAME IN THE SPACE BELOW:
***Jonathan Armknecht, Project 2
***
********************************************/

// You may modify only the private portion of this class declaration.
// Do not modify the following:
//   * The class name
//   * Constructor definitions
//   * Method definitions

#pragma once

// Please do not modify the value of this constatnt.  Use this value
// as the max size for the ArrayList class's capacity.
const int ARRAYLIST_MAX = 256;

class ArrayList
{
private:
	// Declare your private variables here.  You'll need:
	// 1. An array to store your data.
	// 2. A field to keep track of how many items are in your list.
	int data[ARRAYLIST_MAX];
	size_t count;


public:
	////////////////////////////////////////////////////////////////////////////
	// constructor
	// -------------------------------------
	// Initializes a new ArrayList.
	//
	// Parameters:
	//     (none)
	//
	// Things to test:
	//   * Make sure the count is zero.
	ArrayList();


	////////////////////////////////////////////////////////////////////////////
	// Append
	// -------------------------------------
	// This method should add a value to the end of the ArrayList.  If the 
	// ArrayList already contains ARRAYLIST_MAX items, do nothing and return a 
	// value of false, otherwise return a value of true.
	//
	// Parameters:
	//     value: The new value to be added to the ArrayList.
	//
	// Return value:
	//     true, if the value was added to the end of the ArrayList.  false, if 
	//     the ArrayList is at capacity and already contains ARRAYLIST_MAX items.
	//
	// Example:
	//     Suppose your ArrayList contained {2, 4, 6}.  If you call this method 
	//     and pass in an 8, your ArrayList will contain {2, 4, 6, 8}.
	//
	// Things to test:
	//   * Add an item to an empty ArrayList.
	//   * Add an item to an ArrayList that contains fewer than ARRAYLIST_MAX 
	//     items.
	//   * Add an item to an ArrayList that contains ARRAYLIST_MAX items.
	bool Append(int value);


	////////////////////////////////////////////////////////////////////////////
	// Clear
	// -------------------------------------
	// Resets the ArrayList instance back to its blank state.
	//
	// Parameters:
	//     (none)
	//
	// Return value:
	//     (void)
	// 
	// Example:
	//     Suppose I've added 2, 4, 6, and 8 to the ArrayList.  After I call the
	//     Clear() method, the Count() method will return 0, and any calls to 
	//     GetValue will fail.
	//
	// Test cases:
	//   * Add some items to the list, then call Clear().  Make sure GetCount()
	//     returns 0.
	//   * After calling Clear(), make sure GetValue(), InsertAt(), RemoveAt(),
	//     and SetValue() all throw an error if you try to get at the data that
	//     was cleared.
	void Clear();


	////////////////////////////////////////////////////////////////////////////
	// GetCapacity
	// -------------------------------------
	// This method should return the maximum capacity for your list.
	//
	// Parameters:
	//     (none)
	//
	// Return value:
	//     Whatever ARRAYLIST_MAX is set to.
	// 
	// Example:
	//     This method should always return the value of ARRAYLIST_MAX.
	//
	// Test cases:
	//     Not much to test, just make sure it does what it needs to.
	size_t GetCapacity();


	////////////////////////////////////////////////////////////////////////////
	// GetCount
	// -------------------------------------
	// This method should provide a count of how many items are currently stored
	// in the ArrayList.  
	//
	// Parameters:
	//     (none)
	//
	// Return value:
	//     A count of how many items are stored in the ArrayList.
	// 
	// Example:
	//     If I added 2, 3, 5, 7, and 11 to the ArrayList, this method should 
	//     return a value of 5.
	//
	// Test cases:
	//   * Get count of a newly-created ArrayList.
	//   * Add some items, and read back the expected count.
	//   * Add some items, insert some items, remove some items, then make sure 
	//     the count is always updated.
	size_t GetCount();


	////////////////////////////////////////////////////////////////////////////
	// GetValue
	// -------------------------------------
	// This should get a value at the position indicated by pos.  
	//
	// Parameters:
	//     pos: Index of the value that I want to read.
	//
	// Return value:
	//     The value at the indicated position.  If pos is greater than or equal 
	//     to the current count, this method should return a value of zero 
	//     (we'll learn how to do better error handling in a future lecture).
	// 
	// Example:
	//     For instance, if I have an array of {8, 3, 7, 2}, and I want to get 
	//     the value at position 3, this method should return a value of 2.  
	//
	// Test cases:
	//   * The count starts at 0, so GetValue(0) should return the first item,
	//     GetValue(1) should return the second item, etc.
	//   * Make sure if pos >= the current count of items, you return a zero.
	int GetValue(size_t pos);


	////////////////////////////////////////////////////////////////////////////
	// InsertAt
	// -------------------------------------
	// This method should insert a new element into the array.  The value for
	// pos can be less than or equal to GetCount.  If pos is equal to GetCount,
	// then this method will append the item to the end of the array.  If pos
	// is less than GetCount, then this method will scroll all the elements 
	// right, starting at pos, and insert the new element.  
	//
	// Parameters:
	//     pos: position where you want to insert the new number.
	//     value: the number to be inserted.
	//
	// Return value:
	//     If capacity to insert a new value, return a false.  Otherwise return 
	//     a value of true.
	// 
	// Example:
	//     For example, if I have an array of {7, 3, 8, 2}, and I want to insert 
	//     the value 6 at position 2, I will end up with {7, 3, 6, 8, 2}.  
	//
	// Test cases:
	//   * For an empty list, call InsertAt(0, 100).  This should succeed.
	//   * Add some values, then insert into the middle at various places.  Make
	//     sure the values end up in the expected places, and all subsequent
	//     values are moved over.
	//   * Add values onto the end.  This should function just like Append(). 
	//   * Fill the ArrayList up to ARRAYLIST_MAX items, then try to insert into
	//     the middle or at the end.  This should fail.
	//   * Make sure count gets updated.
	bool InsertAt(size_t pos, int value); 


	////////////////////////////////////////////////////////////////////////////
	// RemoveAt
	// -------------------------------------
	// This method should remove a value from an arbitrary position in the list.
	// If the position is beyond the end of the list, then do nothing and return
	// a value of false.  If the position is less than the current count, then
	// remove the item and return a value of true.
	//
	// Parameters:
	//     pos: position where you want to remove a number.
	//
	// Return value:
	//     True if the value was successfully removed.  False if pos is beyond 
	//     current count of items.
	// 
	// Example:
	//     When removing an item, you MUST NOT leave a hole in the array.  You 
	//     must copy the trailing elements over one space.  For example, if my 
	//     array has values {7, 3, 8, 2}, and I want to remove the value at 
	//     position 1, I need to move the 8 and the 2 each one element to the 
	//     left, so I have {7, 8, 2}.
	//
	// Test cases
	//   * Try to remove from an empty list.
	//   * Add some items, then call clear, then call RemoveAt.
	//   * Calling RemoveAt for a value >= GetCount() does nothing and returns
	//     a value of false.
	bool RemoveAt(size_t pos);


	////////////////////////////////////////////////////////////////////////////
	// SetValue
	// -------------------------------------
	// This method should replace a value at a given position.  The value in pos
	// MUST be less than the current count of items in the array.  
	//
	// Parameters:
	//     pos: position where you want to set a number.
	//     value: the new value that you want to set.
	//
	// Return value:
	//     If pos is >= the current count, return a value of false.  Otherwise 
	//     return a value of true.  
	//
	// Example:
	//      For example, if I have an array containing {7, 3, 8, 2}, and I want 
	//      to set the value at position 1 to 100, I will have {7, 100, 8, 2}.
	//
	// Test cases:
	//    * Calling SetValue for any element on an empty ArrayList will fail 
	//      with a return value of false.
	//    * Calling SetValue for any value of pos that is >= GetCount() will 
	//      fail.
	bool SetValue(size_t pos, int value);
};
