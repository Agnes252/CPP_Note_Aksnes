/*
    OutOfBoundsException.hpp

    Base class for array exception.

    2025.3.23
    Ruochen Bao
*/

#ifndef OutOfBoundsException_HPP
#define OutOfBoundsException_HPP

#include "ArrayException.hpp"
#include <sstream>
#include <iostream>
using namespace std;

class OutOfBoundsException : public ArrayException
{
private:
    int m_index;
public:
    // constructors and destructor
    OutOfBoundsException() : ArrayException()
    { // default constructor
    }
    
    OutOfBoundsException(int index) : ArrayException()
    { // constructor that catch error index
        m_index = index;
    }

    virtual ~OutOfBoundsException()
    {
    }

    string GetMessage()
	{
		stringstream stream;
		stream << "Index " << m_index << " is out of bound.";
		return stream.str();
	}

};

#endif