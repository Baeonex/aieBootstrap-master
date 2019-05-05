#include "DynamicArrays.h"


template <class A>
DynamicArrays<A>::DynamicArrays()
{
	realsize = dyn_array_step; // First, allocate step  
							   // for dyn_array_step items 
	size = 0;
	array = (A *)malloc(realsize * sizeof(A));

	if (array == NULL)
		throw MEMFAIL;
}


template <class A>
DynamicArrays<A>::~DynamicArrays()
{
	if (array)
	{
		free(array); // Freeing memory  
		array = NULL;
	}
}


template <class A>
DynamicArrays<A>::DynamicArrays(const DynamicArrays &a)
{
	array = (A *)malloc(sizeof(A)*a.realsize);
	if (array == NULL)
		throw MEMFAIL;

	memcpy(array, a.array, sizeof(A)*a.realsize);
	// memcpy call -- coping memory contents  
	realsize = a.realsize;
	size = a.size;
}


template <class A>
DynamicArrays<A>& DynamicArrays<A>::operator = (const DynamicArrays &a)
{
	if (this == &a) // in case somebody tries assign array to itself  
		return *this;

	if (a.size == 0) // is other array is empty -- clear this array  
		Clear();

	SetSize(a.size); // set size  

	memcpy(array, a.array, sizeof(A)*a.size);

	return *this;
}

template <class A>
unsigned int DynamicArrays<A>::GetSize()
{
	return size; // simply return size 
}


template <class A>
void DynamicArrays<A>::SetSize(unsigned int newsize)
{
	size = newsize;

	if (size != 0)
	{
		// change array memory size  
		// if new size is larger than current  
		// or new size is less then half of the current  
		if ((size > realsize) || (size < realsize / 2))
		{
			realsize = size;
			array = (A *)realloc(array, sizeof(A)*size);

			if (array == NULL)
				throw MEMFAIL;
		}
	}
	else
		Clear();
}

template <class A>
void DynamicArrays<A>::Delete(unsigned int pos)
{
	if (size == 1) // If array has only one element  
		Clear(); // than we clear it, since it will be deleted  
	else
	{
		// otherwise, shift array elements  
		for (unsigned int i = pos; i<size - 1; i++)
			array[i] = array[i + 1];

		// decrease array size 
		size--;
	}
}

template <class A>
void DynamicArrays<A>::Clear() // clear array memory  
{
	size = 0;
	array = (A *)realloc(array, sizeof(A)*dyn_array_step);
	// set initial memory size again  
	realsize = dyn_array_step;
}

template <class A>
void* DynamicArrays<A>::getptr()
{
	return array; // return void* pointer  
}

template <class A>
A& DynamicArrays<A>::operator [] (unsigned int index)
{
	return array[index]; // return array element  
}

template <class A>
void DynamicArrays<A>::Add(const A &item)
{
	size++;

	if (size > realsize)
	{
		realsize *= dyn_array_mult;

		array = (A *)realloc(array, sizeof(A)*realsize);

		if (array == NULL)
			throw MEMFAIL;
	}

	array[size - 1] = item;
}