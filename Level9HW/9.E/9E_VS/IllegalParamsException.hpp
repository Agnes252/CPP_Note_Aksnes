/*
    IllegalParamsException.hpp
    Exception class for illegal parameters.

    2025.4.19
    Ruochen Bao
*/
#ifndef ILLEGAL_PARAMS_EXCEPTION_HPP
#define ILLEGAL_PARAMS_EXCEPTION_HPP

#include "OptionException.hpp"
#include <iostream>
#include <sstream>
using namespace std;

class IllegalParamsException : public OptionException
{
private:
    string m_err_par; // Error message

public:
    // Constructors and destructor
    IllegalParamsException() : OptionException()
    { // Default constructor
    }

    IllegalParamsException(const string& err_par) : OptionException()
    { // Constructor accepting erroneous function name
        m_err_par = err_par;
    }

    virtual ~IllegalParamsException()
    { // Destructor
    }

    // Get error message
    virtual string GetMessage() const override
    {
        ostringstream oss;
        oss << "Error: Parameter " << m_err_par << " is illegal." << endl;
        return oss.str();
    }
};

#endif