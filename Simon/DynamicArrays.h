#pragma once


template<class A>
class DynamicArrays
{
public:
	DynamicArrays(); // constructor  
	DynamicArrays(const DynamicArrays &a); // copy constructor  
	~DynamicArrays(); // distructor  
	DynamicArrays& operator = (const DynamicArrays &a); // assignment operator  

	A& operator [] (unsigned int index); // get array item  
	void Add(const A &item); // Add item to the end of array  

	unsigned int GetSize(); // get size of array (elements) 
	void SetSize(unsigned int newsize); // set size of array (elements) 
	void Clear(); // clear array 
	void Delete(unsigned int pos); // delete array item  
	void* getptr(); // get void* pointer to array data 

	enum exception { MEMFAIL }; // exception enum  

private:
	A * array; // pointer for array's memory  
	unsigned int size; // size of array (elemets) 
	unsigned int realsize; // actual size of allocated memory   

	const static int dyn_array_step = 128; // initial size of array memory (elements) 
	const static int dyn_array_mult = 2; // multiplier (enlarge array memory  
										 // dyn_array_mult times  ) 
};