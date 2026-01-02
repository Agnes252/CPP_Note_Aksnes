/*
    EuroOption.cpp
    Implementation of the EuroOption class.

    2025.4.19
    Ruochen Bao
*/

#include "EuroOption.hpp"
#include "IllegalParamsException.hpp"
#include <boost/math/distributions/normal.hpp>
#include <cmath>
#include <iostream>

using namespace std;
using namespace boost::math;

double EuroOption::CallPrice() const
{ // call price
    return ::CallPrice(T, K, sigma, r, S, b);
}

double EuroOption::PutPrice() const
{ // put price
    return ::PutPrice(T, K, sigma, r, S, b);
}

double EuroOption::CallDelta() const
{ // call delta
    return ::CallDelta(T, K, sigma, r, S, b);
}

double EuroOption::PutDelta() const
{ // put delta
    return ::PutDelta(T, K, sigma, r, S, b);
}

double EuroOption::CallGamma() const
{ // call gamma
    return ::CallGamma(T, K, sigma, r, S, b);
}

double EuroOption::PutGamma() const
{ // put gamma
    return ::PutGamma(T, K, sigma, r, S, b);
}

double EuroOption::CallVega() const
{ // call vega
    return ::CallVega(T, K, sigma, r, S, b);
}

double EuroOption::PutVega() const
{ // put vega
    return ::PutVega(T, K, sigma, r, S, b);
}

double EuroOption::CallTheta() const
{ // call theta
    return ::CallTheta(T, K, sigma, r, S, b);
}

double EuroOption::PutTheta() const
{ // put theta
    return ::PutTheta(T, K, sigma, r, S, b);
}

void EuroOption::Init()
{ // Initialise all default values
    T = 0.25;
    K = 65;
    sigma = 0.30;
    r = 0.08;
    S = 60;
    b = r; // Black¨CScholes stock option model
}

void EuroOption::Copy(const EuroOption& source)
{ // Copy all values

    Option::Copy(source); // copy option type
    T = source.T;
    K = source.K;
    sigma = source.sigma;
    r = source.r;
    S = source.S;
    b = source.b;
}

EuroOption::EuroOption() : Option()
{ // Default constructor
    Init();  // Initialise all default values
}

EuroOption::EuroOption(const EuroOption& source) : Option(source)
{ // Copy constructor

    Copy(source);
}

EuroOption::EuroOption(const enum OptionType& newOptionType) : Option(newOptionType)
{ // Constructor with new option type

    Init();
}

EuroOption::EuroOption(const struct EuropeanOptionData& optionData) : Option()
{ // Constructor with option data

    T = optionData.T;
    K = optionData.K;
    sigma = optionData.sigma;
    r = optionData.r;
    S = optionData.S;
    b = optionData.b;
}

EuroOption::~EuroOption()
{ // Destructor
}

EuroOption& EuroOption::operator = (const EuroOption& source)
{
    Option::operator = (source);

    if (this == &source)
    {
        return *this;
    }

    Copy(source);

    return *this;
}

double EuroOption::CallToPut(double c) const
{ // Use put-call parity to calculate put price
    return c + (K * exp(-r * T)) - S;
}

double EuroOption::PutToCall(double p) const
{ // Use put-call parity to calculate call price
    return p + S - (K * exp(-r * T));
}

bool EuroOption::ParityCheck(double c, double p, double tolerance) const
{
    double lhs = c + (K * exp(-r * T));
    double rhs = p + S;
    return fabs(lhs - rhs) < tolerance; // returns true if parity is approximately satisfied
}

vector<vector<double>> EuroOption::MatrixPricer(const vector<EuropeanOptionData>& paramList, const OptionType optType, const GreeksType greekType) const
{
    if (greekType == None) // compute prices vector
    {
        vector<vector<double>> prices; // store results
        for (const auto& params : paramList)
        {
            vector<double> row;

            if (optType == Call)
            {
                row.push_back(::CallPrice(params.T, params.K, params.sigma, params.r, params.S, params.b));
            }
            else if (optType == Put)
            {
                row.push_back(::PutPrice(params.T, params.K, params.sigma, params.r, params.S, params.b));
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

    else if (optType == Call)
    {
        vector<vector<double>> greeks; // store results
        for (const auto& params : paramList)
        {
            vector<double> row;

            if (greekType == GreeksType::Delta)
            {
                row.push_back(::CallDelta(params.T, params.K, params.sigma, params.r, params.S, params.b));
            }
            else if (greekType == GreeksType::Gamma)
            {
                row.push_back(::CallGamma(params.T, params.K, params.sigma, params.r, params.S, params.b));
            }
            else if (greekType == GreeksType::Vega)
            {
                row.push_back(::CallVega(params.T, params.K, params.sigma, params.r, params.S, params.b));
            }
            else if (greekType == GreeksType::Theta)
            {
                row.push_back(::CallTheta(params.T, params.K, params.sigma, params.r, params.S, params.b));
            }
            else
            {
                IllegalParamsException ex("GreeksType");
                throw (std::cout << ex.GetMessage(), ex);
            }

            greeks.push_back(row);
        }
        return greeks;
    }

    else
    {
        vector<vector<double>> greeks; // store results
        for (const auto& params : paramList)
        {
            vector<double> row;

            if (greekType == GreeksType::Delta)
            {
                row.push_back(::PutDelta(params.T, params.K, params.sigma, params.r, params.S, params.b));
            }
            else if (greekType == GreeksType::Gamma)
            {
                row.push_back(::PutGamma(params.T, params.K, params.sigma, params.r, params.S, params.b));
            }
            else if (greekType == GreeksType::Vega)
            {
                row.push_back(::PutVega(params.T, params.K, params.sigma, params.r, params.S, params.b));
            }
            else if (greekType == GreeksType::Theta)
            {
                row.push_back(::PutTheta(params.T, params.K, params.sigma, params.r, params.S, params.b));
            }
            else
            {
                IllegalParamsException ex("GreeksType");
                throw (std::cout << ex.GetMessage(), ex);
            }

            greeks.push_back(row);
        }
        return greeks;
    }
}


double EuroOption::PriceWithS(double newS) const
{
    if (optionType == Call)
    {
        return ::CallPrice(T, K, sigma, r, newS, b);
    }
    else
    {
        return ::PutPrice(T, K, sigma, r, newS, b);
    }
}

double EuroOption::PriceWithK(double newK) const
{
    if (optionType == Call)
    {
        return ::CallPrice(T, newK, sigma, r, S, b);
    }
    else
    {
        return ::PutPrice(T, newK, sigma, r, S, b);
    }
}

double EuroOption::PriceWithT(double newT) const
{
    if (optionType == Call)
    {
        return ::CallPrice(newT, K, sigma, r, S, b);
    }
    else
    {
        return ::PutPrice(newT, K, sigma, r, S, b);
    }
}

double EuroOption::PriceWithSigma(double newSigma) const
{
    if (optionType == Call)
    {
        return ::CallPrice(T, K, newSigma, r, S, b);
    }
    else
    {
        return ::PutPrice(T, K, newSigma, r, S, b);
    }
}

double EuroOption::PriceWithR(double newR) const
{
    if (optionType == Call)
    {
        return ::CallPrice(T, K, sigma, newR, S, b);
    }
    else
    {
        return ::PutPrice(T, K, sigma, newR, S, b);
    }
}

double EuroOption::DeltaDiff(double S, double h) const
{
    if (h <= 0.0)
    {
        IllegalParamsException ex("h");
        throw (std::cout << ex.GetMessage(), ex);
    }
    return (PriceWithS(S + h) - PriceWithS(S - h)) / (2.0 * h); // central difference method
}

double EuroOption::GammaDiff(double S, double h) const
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

vector<EuropeanOptionData> ExpandVecS(const vector<double>& VecS)
{
    vector<EuropeanOptionData> paramsMatrix;

    double T_default = 0.5;
    double K_default = 100.0;
    double sigma_default = 0.36;
    double r_default = 0.1;
    double b_default = 0.0;

    for (size_t i = 0; i < VecS.size(); ++i) {
        EuropeanOptionData param =
        {
            T_default,
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

double CallPrice(double T, double K, double sigma, double r, double S, double b = NAN)
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

    if (T <= 0.0)
    {
        IllegalParamsException ex("T");
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

    double d1 = (log(S / K) + (b + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    double callPrice = S * exp((b - r) * T) * cdf(normalDist, d1) - K * exp(-r * T) * cdf(normalDist, d2);
    return callPrice;
}

double PutPrice(double T, double K, double sigma, double r, double S, double b = NAN)
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

    if (T <= 0.0)
    {
        IllegalParamsException ex("T");
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


    double d1 = (log(S / K) + (b + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    double putPrice = K * exp(-r * T) * cdf(normalDist, -d2) - S * exp((b - r) * T) * cdf(normalDist, -d1);
    return putPrice;
}

double CallDelta(double T, double K, double sigma, double r, double S, double b)
{
    if (std::isnan(b))
    {
        b = r; // Default to risk-free rate if b is not provided
    }

    if (S <= 0.0)
    {
        IllegalParamsException ex("S");
        throw (std::cout << ex.GetMessage(), ex);
    }

    if (T <= 0.0)
    {
        IllegalParamsException ex("T");
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

    normal_distribution<> normalDist(0, 1);
    double d1 = (log(S / K) + (b + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    return exp((b - r) * T) * cdf(normalDist, d1);
}

double PutDelta(double T, double K, double sigma, double r, double S, double b)
{
    return CallDelta(T, K, sigma, r, S, b) - exp((b - r) * T);
}

double CallGamma(double T, double K, double sigma, double r, double S, double b)
{
    if (std::isnan(b))
    {
        b = r; // Default to risk-free rate if b is not provided
    }

    if (S <= 0.0)
    {
        IllegalParamsException ex("S");
        throw (std::cout << ex.GetMessage(), ex);
    }

    if (T <= 0.0)
    {
        IllegalParamsException ex("T");
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

    normal_distribution<> normalDist(0, 1);
    double d1 = (log(S / K) + (b + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    return exp((b - r) * T) * pdf(normalDist, d1) / (S * sigma * sqrt(T));
}

double PutGamma(double T, double K, double sigma, double r, double S, double b)
{
    return CallGamma(T, K, sigma, r, S, b);
}

double CallVega(double T, double K, double sigma, double r, double S, double b)
{
    if (std::isnan(b))
    {
        b = r; // Default to risk-free rate if b is not provided
    }

    if (S <= 0.0)
    {
        IllegalParamsException ex("S");
        throw (std::cout << ex.GetMessage(), ex);
    }

    if (T <= 0.0)
    {
        IllegalParamsException ex("T");
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

    normal_distribution<> normalDist(0, 1);
    double d1 = (log(S / K) + (b + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    return S * exp((b - r) * T) * pdf(normalDist, d1) * sqrt(T);
}

double PutVega(double T, double K, double sigma, double r, double S, double b)
{
    return CallVega(T, K, sigma, r, S, b);
}

double CallTheta(double T, double K, double sigma, double r, double S, double b)
{
    if (std::isnan(b))
    {
        b = r; // Default to risk-free rate if b is not provided
    }

    if (S <= 0.0)
    {
        IllegalParamsException ex("S");
        throw (std::cout << ex.GetMessage(), ex);
    }

    if (T <= 0.0)
    {
        IllegalParamsException ex("T");
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

    normal_distribution<> normalDist(0, 1);
    double d1 = (log(S / K) + (b + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    return -(S * exp((b - r) * T) * pdf(normalDist, d1) * sigma) / (2.0 * sqrt(T)) - (b - r) * S * exp((b - r) * T) * cdf(normalDist, d1) - r * K * exp(-r * T) * cdf(normalDist, d2);
}

double PutTheta(double T, double K, double sigma, double r, double S, double b)
{
    if (std::isnan(b))
    {
        b = r; // Default to risk-free rate if b is not provided
    }

    if (S <= 0.0)
    {
        IllegalParamsException ex("S");
        throw (std::cout << ex.GetMessage(), ex);
    }

    if (T <= 0.0)
    {
        IllegalParamsException ex("T");
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

    normal_distribution<> normalDist(0, 1);
    double d1 = (log(S / K) + (b + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    return -(S * exp((b - r) * T) * pdf(normalDist, d1) * sigma) / (2.0 * sqrt(T)) + (b - r) * S * exp((b - r) * T) * cdf(normalDist, -d1) + r * K * exp(-r * T) * cdf(normalDist, -d2);
}