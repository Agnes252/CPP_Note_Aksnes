/*
	NoImplementException.hpp
	Exception class for unimplemented functions.

	2025.4.19
	Ruochen Bao
*/


#ifndef NoImplementException_HPP
#define NoImplementException_HPP

#include "OptionException.hpp"
#include <sstream>
#include <iostream>
using namespace std;

class NoImplementException : public OptionException
{
private:
	string m_functionName;

public:
	// Constructors and destructor
	NoImplementException() : OptionException()
	{ // Default constructor
	}

	NoImplementException(string functionName) : OptionException()
	{ // Constructor accepting erroneous function name

		m_functionName = functionName;
	}

	virtual ~NoImplementException()
	{ // Destructor
	}

	virtual string GetMessage() const override
	{
		stringstream oss;
		oss << "Error: No implementation of function " << m_functionName << " in the derived class. ";
		return oss.str();
	}
};

#endif