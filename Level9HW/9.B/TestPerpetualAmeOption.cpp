/*
    TestPerpetualAmeOption.cpp
    Test program for the exact solution of perpetual American options.

    This program tests the PerpetualAmeOption class and its methods for calculating option prices.
    It generates a mesh array of underlying asset prices and calculates the option prices.

    * Clarification of the cost of carry(b):
    If r is the risk-free interest and q is the continuous dividend yield, then
    a) Black-Scholes (1973) stock option model: b = r
    b) b = r - q Merton (1973) stock option model with continuous dividend yield
    c) b = 0 Black (1976) futures option model
    d) b = r - rf Garman and Kohlhagen (1983) currency option model, where rf is the
    'foreign' interest rate

    In this program, we use the Black-Scholes stock option model, so b = r.

    2025.4.19
    Ruochen Bao
*/

#include "Option.hpp"
#include "PerpetualAmeOption.hpp"
#include <boost/tuple/tuple.hpp>	
#include <boost/tuple/tuple_io.hpp> 
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    ofstream outFile("outputB.txt");
    cout << "Perpetual American Option Prices" << endl << endl;
    outFile << "Perpetual American Option Prices" << endl << endl;

    double K = 100.0;
    double sigma = 0.1;
    double r = 0.1;
    double S = 110.0;
    double b = 0.02; // Option parameters
	double C, P; // Call and put prices
	int n = 41; // Number of points in the mesh array
    vector<double> vecS = GenerateMeshArray(10.0, 50.0, n); // generate a monotonically increasing array of option parameters

    // B.b)
    // Use global functions to calculate option prices.
    cout << "B.b" << endl;
    outFile << "B.b" << endl;

    cout << "Use global functions to calculate perpetual American option prices: " << endl;
    outFile << "Use global functions to calculate perpetual American option prices: "<< endl;
    
    cout << "Parameters (K,sigma,r,S,b): " << K << " " << sigma << " " << r << " " << S << " " << b <<endl;
    outFile << "Parameters (K,sigma,r,S,b): " << K << " " << sigma << " " << r << " " << S << " " << b <<endl;

    C = PerpetualCall(K, sigma, r, S, b);
    P = PerpetualPut(K, sigma, r, S, b);
    cout << "C = " << C << ", P = " << P << endl;
    outFile << "C = " << C << ", P = " << P << endl;

    // Use instances of EuroOption class with default constructor.
    cout << "Use instances of PerpetualAmeOption class to calculate option prices: "<< endl;
    outFile << "Use instances of PerpetualAmeOption class to calculate option prices: "<< endl;
    PerpetualAmeOption option0;
    option0.K = K;
    option0.sigma = sigma;
    option0.r = r;
    option0.S = S;
    option0.b = b;
    cout << "C = " << option0.Price();
    outFile << "C = " << option0.Price();
    option0.ChangeOptionType(); // Change option type to put
    cout << ", P = " << option0.Price() << endl << endl;
    outFile << ", P = " << option0.Price() << endl << endl;

    // B.c)
    // Compute prices for a range of underlying value.
    cout << "B.c" << endl;
    outFile << "B.c" << endl;

    option0.optionType = Call;
    vector<double> vecC1, vecP1;
    for (int j = 0; j < vecS.size(); ++j)
    {
        vecC1.push_back(option0.PriceWithS(vecS[j]));
        option0.ChangeOptionType();
        vecP1.push_back(option0.PriceWithS(vecS[j]));
        option0.ChangeOptionType();
    }
    for (int j = 0; j < vecC1.size(); ++j)
    {
        cout << "S = " << vecS[j] << ", C = " << vecC1[j] << ", P = " << vecP1[j] << endl;
        outFile << "S = " << vecS[j] << ", C = " << vecC1[j] << ", P = " << vecP1[j] << endl;
    }
    cout << endl;
    outFile << endl;


    // B.d)
    // input a matrix of option parameters and receive a matrix of option prices
    cout << "B.d" << endl;
    outFile << "B.d" << endl;
    cout << "Input a matrix of option parameters and receive a matrix of option prices." << endl;
    outFile << "Input a matrix of option parameters and receive a matrix of option prices." << endl;


    // 1) define a vector of data struct, then apply the MatrixPricer()
    PerpetualAmeOption option; // create a default PerpetualAmeOption object (call option)
    
    vector<PerpetualAmeOptionData> paramsBatch = {
        {65.0, 0.30, 0.08, 60.0, 0.08},
        {100.0, 0.2, 0.0, 100.0, 0.0},
        {10.0, 0.50, 0.12, 5.0, 0.12},
        {100.0, 0.30, 0.08, 100.0, 0.08}
    }; // Use Batch 1 to Batch 4 data as an example; (K, sigma, r, S, b)
    
    
    vector<vector<double>> CallPrices = option.MatrixPricer(paramsBatch, Call); // Perpetual Call option prices
    vector<vector<double>> PutPrices = option.MatrixPricer(paramsBatch, Put); // Perpetual Put option prices
    //vector<vector<double>> pricesBatchPut = option.BatchPrice(paramsBatch, Put); // Put option prices
    // vector<vector<double>> pricesBatch = option.BatchPrice(paramsBatch, option.optionType); // Option prices based on option type
    for (int j = 0; j < CallPrices.size(); ++j)
    {
        cout << "Batch " << j + 1 << ": C = " << CallPrices[j][0] << ", P = " << PutPrices[j][0] << endl;
        outFile << "Batch " << j + 1 << ": C = " << CallPrices[j][0] << ", P = " << PutPrices[j][0] << endl;
    }
    cout << endl ;
    outFile << endl ;


    // 2) expand vecS to a params matrix, then apply the MatrixPricer()
    cout << "Compute for a range of S:" << endl;
    outFile << "Compute for a range of S:" << endl;
    vector<PerpetualAmeOptionData> paramsMatrix = ExpandVecS(vecS); // expand vecS to a params matrix

    // apply matrix pricer
    vector<vector<double>> CallPrices2 = option.MatrixPricer(paramsMatrix, Call); 
    for (int j = 0; j < CallPrices2.size(); ++j)
    {
        cout << "S = " << vecS[j] << ": C = " << CallPrices2[j][0] << endl ;
        outFile << "S = " << vecS[j] << ": C = " << CallPrices2[j][0] << endl ;
    }

    cout << endl;
    outFile << endl;

    // B.e)
    // Use divided differences to approximate option sensitivities.
    cout << "B.e" << endl;
    outFile << "B.e" << endl;
    cout << "Use divided differences to approximate option sensitivities." << endl << endl;
    outFile << "Use divided differences to approximate option sensitivities." << endl << endl;

    float h = 0.01;
	option0.K = K;
    option0.sigma = sigma;
    option0.r = r;
    option0.S = S;
    option0.b = b;// params set to the same as in B.b)
    cout.precision(8);

    cout << "[ h = " << h << " ]"<< endl;
    outFile << "[ h = " << h << " ]"<< endl;
    option.optionType = Call;
    
    // Single-point calculation
    cout << "Single-point calculation:" << endl;
    outFile << "Single-point calculation:" << endl;
    double callDeltaDiff = option0.DeltaDiff(option0.S, h);
    double callGammaDiff = option0.GammaDiff(option0.S, h);

    option0.ChangeOptionType();

    double putDeltaDiff = option0.DeltaDiff(option0.S, h);
    double putGammaDiff = option0.GammaDiff(option0.S, h);

    cout << "Perpetual call delta (divided diff) = " << callDeltaDiff 
        << ", Perpetual put delta (divided diff) = " << putDeltaDiff << endl;
    outFile << "Perpetual call delta (divided diff) = " << callDeltaDiff 
        << ", Perpetual put delta (divided diff) = " << putDeltaDiff << endl;

    cout << "Perpetual call gamma (divided diff) = " << callGammaDiff 
        << ", Perpetual put gamma (divided diff) = " << putGammaDiff << endl << endl;
    outFile << "Perpetual call gamma (divided diff) = " << callGammaDiff 
        << ", Perpetual put gamma (divided diff) = " << putGammaDiff << endl << endl;
    
    // Compute for a range of S
    cout << "Compute for a range of S:" << endl;
    outFile << "Compute for a range of S:" << endl;
    vector<double> vecCDeltaDiff, vecPDeltaDiff;

    for (size_t i = 0; i < vecS.size(); ++i) // computation
    {
        option0.optionType = Call;
        option0.S = vecS[i];
        
        double callDeltaD = option0.DeltaDiff(vecS[i], h);
        vecCDeltaDiff.push_back(callDeltaD);

        option0.ChangeOptionType();

        double putDeltaD = option0.DeltaDiff(vecS[i], h);
        vecPDeltaDiff.push_back(putDeltaD);
    }

    for (size_t i = 0; i < vecS.size(); ++i) // print results
    {

        cout << "S = " << vecS[i] << ", Call delta (divided diff) = " << vecCDeltaDiff[i] << ", Put delta (divided diff) = " << vecPDeltaDiff[i] << endl;
        outFile << "S = " << vecS[i] << ", Call delta (divided diff) = " << vecCDeltaDiff[i] << ", Put delta (divided diff) = " << vecPDeltaDiff[i] << endl;
    }

    outFile << "End of outputB.txt" << flush;
    outFile.close();
}