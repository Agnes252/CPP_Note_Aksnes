/*
    Option.hpp
    Clarification of the Option class.

    2025.4.19
    Ruochen Bao
*/

#ifndef OPTION_HPP
#define OPTION_HPP

#include <iostream>
using namespace std;


enum OptionType
{
    Put, Call
};

enum GreeksType
{
    Delta, Gamma, Vega, Theta, None
};

class Option
{
private:
    // Option price
    virtual double CallPrice() const = 0;
    virtual double PutPrice() const = 0;
    // Greeks' formulas
    virtual double CallDelta() const;
    virtual double PutDelta() const;
    virtual double CallGamma() const;
    virtual double PutGamma() const;
    virtual double CallVega() const;
    virtual double PutVega() const;
    virtual double CallTheta() const;
    virtual double PutTheta() const;

protected:
    virtual void Init(); // initialise all default values
    virtual void Copy(const Option& source); // copy all default values

public:
    enum OptionType optionType; // Option type, Call or Put
    enum GreeksType greekType; // Greeks type, Delta, Gamma, Vega or Theta

    Option(); // Default constructor; Default to call option
    Option(const Option& source); // Copy constructor
    Option(const OptionType& optionType); // Constructor with option type
    virtual ~Option(); // Destructor

    // Member operator overloading
    Option& operator = (const Option& source);

    // Calculate option price and greeks
    double Price() const;
    double Delta() const;
    double Gamma() const;
    double Vega() const;
    double Theta() const;

    // Modifier functions
    void ChangeOptionType(); // Change option type
};

#endif