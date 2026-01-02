/*
    PerpetualAmeOption.cpp
    Implementation of the PerpetualAmeOption class.

    2025.4.19
    Ruochen Bao
*/

#include "PerpetualAmeOption.hpp"
#include "IllegalParamsException.hpp"
#include <boost/math/distributions/normal.hpp>
#include <cmath>
#include <iostream>

using namespace std;
using namespace boost::math;

double PerpetualAmeOption::CallPrice() const
{ // call price
    return ::PerpetualCall(K, sigma, r, S, b);
}

double PerpetualAmeOption::PutPrice() const
{ // put price
    return ::PerpetualPut(K, sigma, r, S, b);
}

void PerpetualAmeOption::Init()
{ // Initialise all default values
	K = 100.0;
	sigma = 0.1;
	r = 0.1;
	S = 110.0;
	b = 0.02; 
}

void PerpetualAmeOption::Copy(const PerpetualAmeOption &source)
{ // Copy all values

    Option::Copy(source); // copy option type
    K = source.K;
    sigma = source.sigma;
    r = source.r;
    S = source.S;
    b = source.b;
}

PerpetualAmeOption::PerpetualAmeOption() : Option()
{ // Default constructor
    Init();  // Initialise all default values
}

PerpetualAmeOption::PerpetualAmeOption(const PerpetualAmeOption& source) : Option(source)
{ // Copy constructor

    Copy(source); 
}

PerpetualAmeOption::PerpetualAmeOption(const enum OptionType& newOptionType) : Option(newOptionType)
{ // Constructor with new option type

    Init(); 
}

PerpetualAmeOption::PerpetualAmeOption(const struct PerpetualAmeOptionData& optionData) : Option()
{ // Constructor with option data
    K = optionData.K;
    sigma = optionData.sigma;
    r = optionData.r;
    S = optionData.S;
    b = optionData.b;
}

PerpetualAmeOption::~PerpetualAmeOption()
{ // Destructor
}

PerpetualAmeOption& PerpetualAmeOption::operator = (const PerpetualAmeOption &source)
{
    Option::operator = (source);

    if (this == &source) 
    {
        return *this;
    }

    Copy(source);

	return *this;
}

vector<vector<double>> PerpetualAmeOption::MatrixPricer(const vector<PerpetualAmeOptionData>& paramList, const OptionType optType) const // Calculate option prices for a batch of parameters
{
    vector<vector<double>> prices; // store results
    for (const auto& params : paramList)
    {
        vector<double> row;
        
        if (optType == Call)
        {
            row.push_back(::PerpetualCall(params.K, params.sigma, params.r, params.S, params.b));
        }
        else if (optType == Put)
        {
            row.push_back(::PerpetualPut(params.K, params.sigma, params.r, params.S, params.b));
        }
        else
        {
            IllegalParamsException ex("OptionType");
            throw (std::cout << ex.GetMessage(), ex);
        }

        prices.push_back(row);
    }

    return prices;
}

double PerpetualAmeOption::PriceWithS(double newS) const // Calculate option price with given underlying asset price
{
    if (optionType == Call)
    {
        return ::PerpetualCall(K, sigma, r, newS, b);
    }
    else if (optionType == Put)
    {
        return ::PerpetualPut(K, sigma, r, newS, b);
    }
    else
    {
        IllegalParamsException ex("optionType");
        throw (std::cout << ex.GetMessage(), ex);
    }
}


double PerpetualAmeOption::PriceWithK(double newK) const // Calculate option price with given strike price
{
    if (optionType == Call)
    {
        return ::PerpetualCall(newK, sigma, r, S, b);
    }
    else if (optionType == Put)
    {
        return ::PerpetualPut(newK, sigma, r, S, b);
    }
    else
    {
        IllegalParamsException ex("optionType");
        throw (std::cout << ex.GetMessage(), ex);
    }
}

double  PerpetualAmeOption::DeltaDiff(double S, double h) const
{
    if (h <= 0.0)
    {
        IllegalParamsException ex("h");
        throw (std::cout << ex.GetMessage(), ex);
    }
    return (PriceWithS(S + h) - PriceWithS(S - h)) / (2.0 * h); // central difference method
}

double  PerpetualAmeOption::GammaDiff(double S, double h) const
{
    if (h <= 0.0)
    {
        IllegalParamsException ex("h");
        throw (std::cout << ex.GetMessage(), ex);
    }
    return (PriceWithS(S + h) - 2.0 * PriceWithS(S) + PriceWithS(S - h)) / (h * h); // central difference method
}

// Global Functions
vector<double> GenerateMeshArray(double begin, double end, int n)
{
    if (n <= 0)
    {
        IllegalParamsException ex("n");
        throw (std::cout << ex.GetMessage(), ex);
    }
    vector<double> vec;
	double step = (end - begin) / (n - 1);
	for (int i = 0; i < n; i++)
	{
		vec.push_back(begin + step * i);
	}

	return vec;
}

vector<PerpetualAmeOptionData> ExpandVecS(const vector<double>& VecS)
{
    vector<PerpetualAmeOptionData> paramsMatrix;
        
    double K_default = 100.0;
    double sigma_default = 0.1;
    double r_default = 0.1;
    double b_default = 0.02;

    for (size_t i = 0; i < VecS.size(); ++i) {
        PerpetualAmeOptionData param = 
        {
            K_default,
            sigma_default,
            r_default,
            VecS[i],    // use elements in vecS
            b_default
        };
        paramsMatrix.push_back(param);
    }
    return paramsMatrix;
}

double PerpetualCall(double K, double sigma, double r, double S, double b = NAN)
{
    normal_distribution<> normalDist(0, 1);

    if (std::isnan(b)) 
    {
        b = r; // Default to risk-free rate if b is not provided
    }

    if (S <= 0.0)
    {
        IllegalParamsException ex("S");
        throw (std::cout << ex.GetMessage(), ex);
    }

    if (K <= 0.0)
    {
        IllegalParamsException ex("K");
        throw (std::cout << ex.GetMessage(), ex);
    }

    if (sigma <= 0.0)
    {
        IllegalParamsException ex("sigma");
        throw (std::cout << ex.GetMessage(), ex);
    }

    double sig2 = sigma * sigma;
    double fac = b / sig2 - 0.5;
    fac *= fac;

    double disc = fac + 2.0 * r / sig2;
    if (disc < 0.0) 
    {
        disc = 0.0; // Protection against negative sqrt arg
    }

    double y1 = 0.5 - b / sig2 + sqrt(disc);

    if (fabs(y1 - 1.0) < 1e-6)
    {
        return S; // Avoid division by (y1 - 1)
    }

    double fac2 = ((y1 - 1.0) * S) / (y1 * K);

    if (fac2 <= 0.0)
    {
        return 0.0; // Avoid pow of negative/zero base
    }

    // Additional overflow check
    if (fac2 > 1e6)
    {
        return S; // Result likely to explode, cap to intrinsic value
    }

    double c = K * pow(fac2, y1) / (y1 - 1.0);

    return c;
}

double PerpetualPut(double K, double sigma, double r, double S, double b = NAN)
{
    normal_distribution<> normalDist(0, 1);

    if (std::isnan(b)) 
    {
        b = r; // Default to risk-free rate if b is not provided
    }

    if (S <= 0.0)
    {
        IllegalParamsException ex("S");
        throw (std::cout << ex.GetMessage(), ex);
    }

    if (K <= 0.0)
    {
        IllegalParamsException ex("K");
        throw (std::cout << ex.GetMessage(), ex);
    }

    if (sigma <= 0.0)
    {
        IllegalParamsException ex("sigma");
        throw (std::cout << ex.GetMessage(), ex);
    }

    double sig2 = sigma * sigma;
    double fac = b / sig2 - 0.5;
    fac *= fac;

    double disc = fac + 2.0 * r / sig2;
    if (disc < 0.0)
    {
        disc = 0.0; // Protection against negative sqrt argument
    }

    double y2 = 0.5 - b / sig2 - sqrt(disc);

    if (fabs(y2) < 1e-6)
    {
        return S; // Avoid division by 0
    }

    double fac2 = ((y2 - 1.0) * S) / (y2 * K);

    if (fac2 <= 0.0)
    {
        return 0.0; // Avoid invalid pow base
    }

    // Additional overflow check
    if (fac2 > 1e6)
    {
        return S; // Cap if base is too large
    }

    double p = K * pow(fac2, y2) / (1.0 - y2);

    return p;
}

