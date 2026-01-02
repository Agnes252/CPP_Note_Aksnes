/*
    PerpetualAmeOption.hpp
    Clarification of the PerpetualAme class.

    2025.4.19
    Ruochen Bao
*/

#ifndef PERPETUAL_AMERICAN_OPTION_HPP
#define PERPETUAL_AMERICAN_OPTION_HPP

#include "Option.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class PerpetualAmeOption : public Option
{
private:
    // Option price
    double CallPrice() const;
    double PutPrice() const;

protected:
    void Init();// Initialise all default values
    void Copy(const PerpetualAmeOption &source);// Copy all values

public:
    // Option parameters
    double S; // Underlying asset price
    double K; // Strike price
    double r; // Risk-free interest rate
    double sigma; // Volatility of underlying asset
    double b; // Cost of carry

public:
    // Constructors and destructor
    PerpetualAmeOption(); // Default constructor
    PerpetualAmeOption(const PerpetualAmeOption& source); // Copy constructor
    PerpetualAmeOption(const enum OptionType& newOptionType); // Constructor with parameters
    PerpetualAmeOption(const struct PerpetualAmeOptionData& optionData); // Constructor with option data
    virtual ~PerpetualAmeOption(); // Destructor

    // Member operator overloading
    PerpetualAmeOption& operator = (const PerpetualAmeOption& source);

    // Additional functions that calculate option prices and sensitivities
    vector<vector<double>> MatrixPricer(const vector<PerpetualAmeOptionData>& paramList, const OptionType optType = Call) const; // Calculate option prices for a batch of parameters
    double PriceWithS(double newS) const; // Calculate option price with given underlying asset price
    double PriceWithK(double newT) const; // Calculate option price with given strike price
    double DeltaDiff(double S, double h) const; // Calculate delta using finite difference method
    double GammaDiff(double S, double h) const; // Calculate gamma using finite difference method
    
};

struct PerpetualAmeOptionData
{
	double K; // Strike price
	double sigma; // volatility
	double r; // Risk free interest rate
	double S; // Current price of the underlying asset
	double b; // Cost of carry
};

// Global Functions
vector<double> GenerateMeshArray(double begin, double end, int n);
vector<PerpetualAmeOptionData> ExpandVecS(const vector<double>& VecS);
double PerpetualCall(double K, double sigma, double r, double S, double b);
double PerpetualPut(double K, double sigma, double r, double S, double b);


#endif // EUROPEAN_OPTION_HPP