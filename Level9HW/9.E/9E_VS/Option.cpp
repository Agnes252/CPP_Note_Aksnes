/*
    Option.cpp
    Implementation of the Option class.

    2025.4.19
    Ruochen Bao
*/

#include "Option.hpp"
#include "NoImplementException.hpp"
#include "IllegalParamsException.hpp"

#include <iostream>
#include <cmath>

using namespace std;

double Option::CallDelta() const
{
    throw NoImplementException("CallDelta()");
}

double Option::PutDelta() const
{
    throw NoImplementException("PutDelta()");
}
double Option::CallGamma() const
{
    throw NoImplementException("CallGamma()");
}

double Option::PutGamma() const
{
    throw NoImplementException("PutGamma()");
}

double Option::CallVega() const
{
    throw NoImplementException("CallVega()");
}
double Option::PutVega() const
{
    throw NoImplementException("PutVega()");
}

double Option::CallTheta() const
{
    throw NoImplementException("CallTheta()");
}

double Option::PutTheta() const
{
    throw NoImplementException("PutTheta()");
}

void Option::Init()
{
    // Default values for option parameters
}

void Option::Copy(const Option& source)
{
    // Copy option parameters from source
    this->optionType = source.optionType;
}

Option::Option()
{
    Init();
    optionType = Call; // Default to call option
}

Option::Option(const Option& source)
{
    Copy(source); // Copy default values
}

Option::Option(const enum OptionType& optionType)
{ // constructor with option type
    Init();
    this->optionType = optionType; // Set option type
}

Option::~Option()
{
    // Destructor
}

// Assignment operator
Option& Option::operator = (const Option& source)
{
    if (this == &source) // Avoid self-assignment
    {
        return *this; // Copy default values
    }

    Copy(source); // Copy default values

    return *this; // Return the current object
}

// Functions that calculate option prices and sensitivities
double Option::Price() const
{
    if (optionType == Call)
    {
        return CallPrice(); // Calculate call option price
    }
    else
    {
        return PutPrice(); // Calculate put option price
    }
}

double Option::Delta() const
{
    if (optionType == Call)
    {
        return CallDelta(); // Calculate call option delta
    }
    else
    {
        return PutDelta(); // Calculate put option delta
    }
}

double Option::Gamma() const
{
    if (optionType == Call)
    {
        return CallGamma(); // Calculate call option gamma
    }
    else
    {
        return PutGamma(); // Calculate put option gamma
    }
}

double Option::Vega() const
{
    if (optionType == Call)
    {
        return CallVega(); // Calculate call option vega
    }
    else
    {
        return PutVega(); // Calculate put option vega
    }
}

double Option::Theta() const
{
    if (optionType == Call)
    {
        return CallTheta(); // Calculate call option theta
    }
    else
    {
        return PutTheta(); // Calculate put option theta
    }
}

// Modifier functions
void Option::ChangeOptionType()
{
    optionType = ((optionType == Call) ? Put : Call);
}