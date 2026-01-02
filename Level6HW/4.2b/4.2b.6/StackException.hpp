/*
    StackException.hpp

    Base and derived class for stack exception.

    2025.3.30
    Ruochen Bao
*/

#ifndef StackException_HPP
#define StackException_HPP

#include <sstream>
#include <iostream>
using namespace std;

class StackException
{
public:
	// Constructor and destructor
	StackException()
	{ 
	}

	virtual ~StackException()
	{ 
	}

	virtual string GetMessage() = 0;
};

class StackFullException : public StackException
{
public:
	// Constructors and destructor
	StackFullException() : StackException()
	{ 
	}

	~StackFullException()
	{ 
	}

	string GetMessage()
	{
		stringstream stream;
		stream << "Stack full exception.";
		return stream.str();
	}
};

class StackEmptyException : public StackException
{
public:
	// Constructors and destructor
	StackEmptyException() : StackException()
	{ 
	}

	~StackEmptyException()
	{ 
	}

	string GetMessage()
	{
		stringstream stream;
		stream << "Stack empty exception.";
		return stream.str();
	}
};

#endif