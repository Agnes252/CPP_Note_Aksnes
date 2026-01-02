/*
    TestEuroOption.cpp
    Test program for the exact solution of European options.

    This program tests the EuroOption class and its methods for calculating option prices and Greeks.
    It generates a mesh array of underlying asset prices and calculates the option prices, deltas, gammas, vegas, and thetas for each price.
    It also uses parity check to verify the relationship between call and put prices.

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
#include "EuroOption.hpp"
#include "DatasimException.hpp"
#include "ExcelDriverLite.hpp"
#include "Utilities.hpp"
#include <boost/tuple/tuple.hpp>	
#include <boost/tuple/tuple_io.hpp> 
#include <iostream>
#include <vector>
#include <fstream>
#include <list>
using namespace std;

int main()
{
    // generate a monotonically increasing array of option parameters
    double start = 10.0;
    double end = 50.0;
	int n = 41; // number of elements in the mesh array
    vector<double> vecS = GenerateMeshArray(start, end, n);

    list<string> labels; // Names of each vector
    list<vector<double> > functionResult; // The list of option prices

    // Store Batch 1 to Batch 4 data in a vector (T, K, sigma, r, S)
    typedef boost::tuple<double, double, double, double, double> TupleFive;
    vector<TupleFive> vecBatch;
    vecBatch.push_back(boost::make_tuple(0.25, 65.0, 0.30, 0.08, 60.0));
    vecBatch.push_back(boost::make_tuple(1.0, 100.0, 0.2, 0.0, 100.0));
    vecBatch.push_back(boost::make_tuple(1.0, 10.0, 0.50, 0.12, 5.0));
    vecBatch.push_back(boost::make_tuple(30.0, 100.0, 0.30, 0.08, 100.0));

    ///////////////// Option Prices /////////////////
    double T, K, sigma, r, S, b; // Option parameters
    stringstream ss;
    string str;
   
    for (int i = 0; i < vecBatch.size(); ++i)
    {
        // Add column name.
        ss << i + 1;
        ss >> str;
        labels.push_back("Batch " + str + " Call");
        labels.push_back("Batch " + str + " Put");
        ss.clear();

        T = vecBatch[i].get<0>();
        K = vecBatch[i].get<1>();
        sigma = vecBatch[i].get<2>();
        r = vecBatch[i].get<3>();
        S = vecBatch[i].get<4>();
        b = r;

		EuroOption option0; // default call option EuroOption object
        option0.T = T;
        option0.K = K;
        option0.sigma = sigma;
        option0.r = r;
        option0.S = S;
        option0.b = b;
       
        EuroOption option1 = option0;
        option1.ChangeOptionType(); // Change option type to put

        // Compute prices for a range of underlying value.
        vector<double> vecC, vecP;
        for (int j = 0; j < vecS.size(); ++j)
        {
            vecC.push_back(option0.PriceWithS(vecS[j]));
            vecP.push_back(option1.PriceWithS(vecS[j]));
        }

		// Store the option prices in the list of vectors
        functionResult.push_back(vecC);
        functionResult.push_back(vecP);
       
    }

    cout << "Data has been created" << endl;

	// Write the data to excel
    try
    {
        ExcelDriver xl; xl.MakeVisible(true);
        xl.CreateChart(vecS, labels, functionResult, string("Graph 9.E"), string("Underlying Value of S"), string("Option Price"));
    }
    catch (DatasimException& e)
    {
        e.print();
    }


}