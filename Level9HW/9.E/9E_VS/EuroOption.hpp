/*
    EuroOption.hpp
    Clarification of the EuroOption class.

    2025.4.19
    Ruochen Bao
*/

#ifndef EUROPEAN_OPTION_HPP
#define EUROPEAN_OPTION_HPP

#include "Option.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class EuroOption : public Option
{
private:
    // Option price
    double CallPrice() const;
    double PutPrice() const;
    // Greeks' formulas
    double CallDelta() const;
    double PutDelta() const;
    double CallGamma() const;
    double PutGamma() const;
    double CallVega() const;
    double PutVega() const;
    double CallTheta() const;
    double PutTheta() const;

protected:
    void Init();// Initialise all default values
    void Copy(const EuroOption& source);// Copy all values

public:
    // Option parameters
    double S; // Underlying asset price
    double K; // Strike price
    double r; // Risk-free interest rate
    double T; // Maturity date 
    double sigma; // Volatility of underlying asset
    double b; // Cost of carry

public:
    // Constructors and destructor
    EuroOption(); // Default constructor
    EuroOption(const EuroOption& source); // Copy constructor
    EuroOption(const enum OptionType& newOptionType); // Constructor with parameters
    EuroOption(const struct EuropeanOptionData& optionData); // Constructor with option data
    virtual ~EuroOption(); // Destructor

    // Member operator overloading
    EuroOption& operator = (const EuroOption& source);

    // Additional functions that calculate option prices and sensitivities
    double CallToPut(double c) const; // Use put-call parity to calculate put price
    double PutToCall(double p) const; // Use put-call parity to calculate call price
    bool ParityCheck(double c, double p, double tolerance = 1e-6) const; // Check if put-call parity holds
    vector<vector<double>> MatrixPricer(const vector<EuropeanOptionData>& paramList, const OptionType optType = Call, const GreeksType greekType = None) const; // Calculate option prices for a batch of parameters
    double PriceWithS(double newS) const; // Calculate option price with given underlying asset price
    double PriceWithK(double newT) const; // Calculate option price with given strike price
    double PriceWithT(double newT) const; // Calculate option price with given maturity date
    double PriceWithR(double newR) const; // Calculate option price with given risk-free interest rate
    double PriceWithSigma(double newSigma) const; // Calculate option price with given volatility
    double DeltaDiff(double S, double h) const; // Calculate delta using finite difference method
    double GammaDiff(double S, double h) const; // Calculate gamma using finite difference method
};

struct EuropeanOptionData
{
    double T; // Expiry time
    double K; // Strike price
    double sigma; // volatility
    double r; // Risk free interest rate
    double S; // Current price of the underlying asset
    double b; // Cost of carry
};

// Global Functions
vector<double> GenerateMeshArray(double begin, double end, int n);
vector<EuropeanOptionData> ExpandVecS(const vector<double>& VecS);
double CallPrice(double T, double K, double sigma, double r, double S, double b);
double PutPrice(double T, double K, double sigma, double r, double S, double b);
double CallDelta(double T, double K, double sigma, double r, double S, double b);
double PutDelta(double T, double K, double sigma, double r, double S, double b);
double CallGamma(double T, double K, double sigma, double r, double S, double b);
double PutGamma(double T, double K, double sigma, double r, double S, double b);
double CallVega(double T, double K, double sigma, double r, double S, double b);
double PutVega(double T, double K, double sigma, double r, double S, double b);
double CallTheta(double T, double K, double sigma, double r, double S, double b);
double PutTheta(double T, double K, double sigma, double r, double S, double b);

#endif // EUROPEAN_OPTION_HPP