#include <vector>
#include <assert.h>

template <typename T>
class Stack 
{

public:
	// Write the following functions (cut & paste from E.cpp)
    void push(T const & data);      // push element
	void push(char const & data);   // when you push() a float it double pushes
    void pop();               // pop element
    T top() const;            // return top element
    bool empty() const;      // return whether the stack is empty
private:
    std::vector<T> elems;     // elements
};

// cut & paste from E.cpp

template <typename T>
void Stack<T>::push(T const & data)
{
	// push element
	Stack::elems.push_back(data);
}

void Stack<float>::push(float const & data)
{
	// when you push() a float it double pushes
	Stack::elems.push_back(data);
	Stack::elems.push_back(data);
}

template <typename T>
void Stack<T>::pop()
{
	// pop element
	Stack::elems.pop_back();
}

template <typename T>
T Stack<T>::top() const
{
	// return top element
	return Stack::elems[elems.size() - 1];
}

template <typename T>
bool Stack<T>::empty() const
{
	// return whether the stack is empty
	if (Stack::elems.size() == 0)
	{
		return true;
	}
	return false;
}


// Write a full class specialization for float
// in this class when you push() a float it double pushes
// in this class when you pop() it pops a singe element off the stack
// top() and empty() behave the same.

void F()
{
	// Cut & Paste from E.cpp for the general class template

	// Write a full class specialization for float
	// in this class when you push() a float it double pushes
	// in this class when you pop() it pops a singe element off the stack
	// top() and empty() behave the same.
	// cut & paste from E.cpp

// Do not change the code below -----------------------

			int val;
			bool bval;
			Stack<int> Stack_int;

			bval = Stack_int.empty();
			assert( bval == true );

			Stack_int.push( 5 );
			val = Stack_int.top();
			assert( val == 5 );

			bval = Stack_int.empty();
			assert( bval == false );

			Stack_int.push( 6 );
			val = Stack_int.top();
			assert( val == 6);

			Stack_int.push( 7 );
			val = Stack_int.top();
			assert( val == 7 );

			Stack_int.push( 8 );
			val = Stack_int.top();
			assert( val == 8 );

			Stack_int.pop();
			val = Stack_int.top();
			assert( val == 7 );

			Stack_int.pop();
			val = Stack_int.top();
			assert( val == 6);

			Stack_int.pop();
			val = Stack_int.top();
			assert( val == 5 );

			bval = Stack_int.empty();
			assert( bval == false );

			Stack_int.pop();
			bval = Stack_int.empty();
			assert( bval == true);

			// ----- float ---------------

			float fval;
			Stack<float> Stack_float;

			bval = Stack_float.empty();
			assert( bval == true );

			Stack_float.push( 55.0f );
			fval = Stack_float.top();
			assert( fval == 55.0f );

			bval = Stack_float.empty();
			assert( bval == false );

			Stack_float.push( 88.0f );
			fval = Stack_float.top();
			assert( fval == 88.0f );

			// ---- start to pop -------------
			Stack_float.pop();
			fval = Stack_float.top();
			assert( fval == 88.0f );
			
			bval = Stack_float.empty();
			assert( bval == false );

			Stack_float.pop();
			fval = Stack_float.top();
			assert( fval == 55.0f );

			bval = Stack_float.empty();
			assert( bval == false );

			Stack_float.pop();
			fval = Stack_float.top();
			assert( fval == 55.0f );

			bval = Stack_float.empty();
			assert( bval == false );

			Stack_float.pop();
			bval = Stack_float.empty();
			assert( bval == true );



// Do not change the code above -----------------------

}