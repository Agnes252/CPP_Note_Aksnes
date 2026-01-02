/*
	OptionException.hpp
	Exception class for handling option-related errors.

	2025.4.19
	Ruochen Bao
*/

#ifndef OptionException_HPP
#define OptionException_HPP

#include <iostream>
using namespace std;

class OptionException
{
public:
	// Constructor 
	OptionException()
	{
	}

	// Destructor
	virtual ~OptionException()
	{
	}

	virtual string GetMessage() const = 0;
};

#endif