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
#include <boost/tuple/tuple.hpp>	
#include <boost/tuple/tuple_io.hpp> 
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    ofstream outFile("outputA.txt");
    cout << "European Option Prices and Greeks" << endl;
    outFile << "European Option Prices and Greeks" << endl;

    // Store Batch 1 to Batch 4 data in a vector (T, K, sigma, r, S)
	typedef boost::tuple<double, double, double, double, double> TupleFive;
	vector<TupleFive> vecBatch;
	vecBatch.push_back(boost::make_tuple(1.65, 122.0, 0.43, 0.045, 102.0));
	vecBatch.push_back(boost::make_tuple(1.0, 100.0, 0.2, 0.0, 100.0));
	vecBatch.push_back(boost::make_tuple(1.0, 10.0, 0.50, 0.12, 5.0));
	vecBatch.push_back(boost::make_tuple(30.0, 100.0, 0.30, 0.08, 100.0));
	
    ///////////////// Option Prices /////////////////
    cout << "Part 1: Option Prices" << endl;
    outFile << "Part 1: Option Prices" << endl;
    double T, K, sigma, r, S, b; // Option parameters
	double C, P; // Call and put prices
	int n = 41; // Number of points in the mesh array

    // generate a monotonically increasing array of option parameters
    vector<double> vecS = GenerateMeshArray(10.0, 50.0, n);
	vector<double> vecT = GenerateMeshArray(0.1, 1.0, n);
	vector<double> vecSigma = GenerateMeshArray(0.1, 1.0, n);

	for (int i = 0; i < vecBatch.size(); ++i)
	{
        cout << "[ Batch " << i + 1 << " ]" << endl;
        outFile << "[ Batch " << i + 1 << " ]" << endl;

		// A.1.a)
		// Use global functions to calculate option prices.
        cout << "A.1.a" << endl;
        outFile << "A.1.a" << endl;

        cout << "Use global functions to calculate option prices: " << endl;
        outFile << "Use global functions to calculate option prices: "<< endl;
		T = vecBatch[i].get<0>();
        K = vecBatch[i].get<1>();
        sigma = vecBatch[i].get<2>();
        r = vecBatch[i].get<3>();
        S = vecBatch[i].get<4>();
		b = r;
        
        cout << "Parameters (T,K,sigma,r,S): " << T << " " << K << " " << sigma << " " << r << " " << S << endl;
        outFile << "Parameters (T,K,sigma,r,S):" << T << " " << K << " " << sigma << " " << r << " " << S << endl;

		C = CallPrice(T, K, sigma, r, S, b);
		P = PutPrice(T, K, sigma, r, S, b);
		cout << "Batch " << i + 1 << ": C = " << C << ", P = " << P << endl;
		outFile << "Batch " << i + 1 << ": C = " << C << ", P = " << P << endl;

		// Use instances of EuroOption class with default constructor.
        cout << "Use instances of EuroOption class to calculate option prices: "<< endl;
        outFile << "Use instances of EuroOption class to calculate option prices: "<< endl;
		EuroOption option0;
		option0.T = T;
		option0.K = K;
		option0.sigma = sigma;
		option0.r = r;
		option0.S = S;
		option0.b = b;
		cout << "Batch " << i + 1 << ": C = " << option0.Price();
		outFile << "Batch " << i + 1 << ": C = " << option0.Price();
		option0.ChangeOptionType(); // Change option type to put
		cout << ", P = " << option0.Price() << endl << endl;
		outFile << ", P = " << option0.Price() << endl << endl;

		// A.1.b)
		// Use put-call parity to calculate option prices, then check the parity.
        cout << "A.1.b" << endl;
        outFile << "A.1.b" << endl;
        cout << "Use put-call parity to calculate option prices, then check the parity." << endl;
        outFile << "Use put-call parity to calculate option prices, then check the parity." << endl;

		cout << "Batch " << i + 1 << ":" << endl << "C = " << option0.PutToCall(option0.Price()) ;
		outFile << "Batch " << i + 1 << ":" << endl << "C = " << option0.PutToCall(option0.Price());
		option0.ChangeOptionType(); // Change option type to call
		cout << ", P = " << option0.CallToPut(option0.Price()) << endl;
		outFile << ", P = " << option0.CallToPut(option0.Price()) << endl;
        cout << "Check parity: " << option0.ParityCheck(C, P)<< endl << endl; // default tolerance = 1e-6
        outFile << "Check parity: " << option0.ParityCheck(C, P) << endl << endl; // default tolerance = 1e-6
    
        // A.1.c)
        // Compute prices for a range of underlying value.
        cout << "A.1.c" << endl;
        outFile << "A.1.c" << endl;

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
            cout << "Batch " << i + 1 << ": S = " << vecS[j] << ", C = " << vecC1[j] << ", P = " << vecP1[j] << endl;
            outFile << "Batch " << i + 1 << ": S = " << vecS[j] << ", C = " << vecC1[j] << ", P = " << vecP1[j] << endl;
        }
        cout << endl;
        outFile << endl;
    }
    
    // A.1.d)
    // input a matrix of option parameters and receive a matrix of option prices
    cout << "A.1.d" << endl;
    outFile << "A.1.d" << endl;
    cout << "Input a matrix of option parameters and receive a matrix of option prices." << endl;
    outFile << "Input a matrix of option parameters and receive a matrix of option prices." << endl;

    EuroOption option; // create a default EuroOption object (call option)
    
    vector<EuropeanOptionData> paramsBatch = {
        {0.25, 65.0, 0.30, 0.08, 60.0, 0.08},
        {1.0, 100.0, 0.2, 0.0, 100.0, 0.0},
        {1.0, 10.0, 0.50, 0.12, 5.0, 0.12},
        {30.0, 100.0, 0.30, 0.08, 100.0, 0.08}
    }; // Use Batch 1 to Batch 4 data as an example; (T, K, sigma, r, S, b)
    
    vector<vector<double>> pricesBatch = option.MatrixPricer(paramsBatch, Call); // Call option prices
    //vector<vector<double>> pricesBatchPut = option.BatchPrice(paramsBatch, Put); // Put option prices
    // vector<vector<double>> pricesBatch = option.BatchPrice(paramsBatch, option.optionType); // Option prices based on option type
    for (int j = 0; j < pricesBatch.size(); ++j)
    {
        cout << "Batch " << j + 1 << ": C = " << pricesBatch[j][0] << endl ;
        outFile << "Batch " << j + 1 << ": C = " << pricesBatch[j][0] << endl ;
    }
    cout << endl << endl << endl;
    outFile << endl << endl << endl;


    ///////////////// Option Greeks /////////////////
    cout << "Part 2: Option Greeks" << endl ;
    outFile << "Part 2: Option Greeks" << endl ;

    // A.2.a)
    // Calculate future option delta and gamma.
    cout << "A.2.a" << endl;
    outFile << "A.2.a" << endl;
    cout << "Calculate future option delta and gamma. " << endl;
    outFile << "Calculate future option delta and gamma. " << endl; 
    
    T = 1.65;
	K = 122;
	sigma = 0.43;
	r = 0.045;
	S = 102;
	b = 0.0;

	cout << "Future call delta = " << CallDelta(T, K, sigma, r, S, b) << ", Future put delta = " << PutDelta(T, K, sigma, r, S, b) << endl;
	outFile << "Future call delta = " << CallDelta(T, K, sigma, r, S, b) << ", Future put delta = " << PutDelta(T, K, sigma, r, S, b) << endl;
	cout << "Future call gamma = " << CallGamma(T, K, sigma, r, S, b) << ", Future put gamma = " << PutGamma(T, K, sigma, r, S, b) << endl << endl;
	outFile << "Future call gamma = " << CallGamma(T, K, sigma, r, S, b) << ", Future put gamma = " << PutGamma(T, K, sigma, r, S, b) << endl << endl;

    // A.2.b)
    // Calculate future call delta price for a monotonically increasing range of S.
    cout << "A.2.b" << endl;
    outFile << "A.2.b" << endl;
    cout << "Calculate future call delta price for a monotonically increasing range of S." << endl;
    outFile << "Calculate future call delta price for a monotonically increasing range of S." << endl; 
    
    EuroOption futureOption; // define a call EuroOption object
	futureOption.T = T;
	futureOption.K = K;
	futureOption.sigma = sigma;
	futureOption.r = r;
	futureOption.S = S;
	futureOption.b = b;

    vector<double> vecCDelta, vecPDelta; // vectors to store delta results
    
    for (int i = 0; i < vecS.size(); ++i) // compute delta
	{
		futureOption.S = vecS[i];
		vecCDelta.push_back(futureOption.Delta());
		futureOption.ChangeOptionType();
		vecPDelta.push_back(futureOption.Delta());
		futureOption.ChangeOptionType();
	}

    for (int i = 0; i < vecCDelta.size(); ++i) // print results
	{
		cout << "S = " << vecS[i] << ", Future call delta = " << vecCDelta[i] << ", Future put delta = " << vecPDelta[i] << endl;
		outFile << "S = " << vecS[i] << ", Future call delta = " << vecCDelta[i] << ", Future put delta = " << vecPDelta[i] << endl;
	}
	cout << endl;
	outFile << endl;


    // A.2.c)
    // Calculate future call delta price for a monotonically increasing range of S.
    cout << "A.2.c" << endl;
    outFile << "A.2.c" << endl;
    cout << "Input a matrix of option parameters and receive a matrix of Greeks as the result." << endl;
    outFile << "Input a matrix of option parameters and receive a matrix of Greeks as the result."  << endl; 
    
    // expand vecS to a params matrix
    vector<EuropeanOptionData> paramsMatrix = ExpandVecS(vecS); // expand vecS to a params matrix

    // apply matrix pricer
    vector<vector<double>> deltasMatrix = futureOption.MatrixPricer(paramsMatrix, Call, Delta); // Call option Delta prices
    for (int j = 0; j < deltasMatrix.size(); ++j)
    {
        cout << "S = " << vecS[j] << ": Call Delta = " << deltasMatrix[j][0] << endl ;
        outFile << "S = " << vecS[j] << ": Call Delta = " << deltasMatrix[j][0] << endl ;
    }

    cout << endl ;
    outFile << endl ;

    vector<vector<double>> gammasMatrix = futureOption.MatrixPricer(paramsMatrix, Call, Gamma); // Call option Gamma prices
    for (int j = 0; j < gammasMatrix.size(); ++j)
    {
        cout << "S = " << vecS[j] << ": Call Gamma = " << gammasMatrix[j][0] << endl ;
        outFile << "S = " << vecS[j] << ": Call Gamma = " << gammasMatrix[j][0] << endl ;
    }

    cout << endl;
    outFile << endl;

    // A.2.d)
    // Use divided differences to approximate option sensitivities, 
    // and compare with the results of exact formula.
    cout << "A.2.d" << endl;
    outFile << "A.2.d" << endl;
    cout << "Calculate future option delta and gamma using divided differences." << endl;
    outFile << "Calculate future option delta and gamma using divided differences." << endl;

    vector<double> hValues = {0.1, 0.01, 0.001}; // Different h values for testing
    const double EPSILON = 1e-12; // tolerance to avoid printing insignificant errors

    futureOption.T = 0.5;
	futureOption.K = 100.0;
	futureOption.sigma = 0.36;
	futureOption.r = 0.1;
	futureOption.S = 105.0;
	futureOption.b = 0.0; // params set to the same as in A.2.a)

    cout << "Difference threshold : " << EPSILON << endl << endl;
    outFile << "Difference threshold : " << EPSILON << endl << endl;

    for (double h: hValues)
    {
        cout.precision(8);

        cout << "[ h = " << h << " ]"<< endl;
        outFile << "[ h = " << h << " ]"<< endl;
        futureOption.optionType = Call;
        
        // Single-point calculation
        cout << "Single-point calculation:" << endl;
        outFile << "Single-point calculation:" << endl;
        double callDeltaExact = futureOption.Delta();
        double callDeltaDiff = futureOption.DeltaDiff(futureOption.S, h);
        double callGammaExact = futureOption.Gamma();
        double callGammaDiff = futureOption.GammaDiff(futureOption.S, h);

        futureOption.ChangeOptionType();

        double putDeltaExact = futureOption.Delta();
        double putDeltaDiff = futureOption.DeltaDiff(futureOption.S, h);
        double putGammaExact = futureOption.Gamma();
        double putGammaDiff = futureOption.GammaDiff(futureOption.S, h);

        cout << "Future call delta (exact) = " << callDeltaExact << ", (divided diff) = " << callDeltaDiff 
            << ", difference = " << fabs(callDeltaExact - callDeltaDiff) << endl; 
        outFile << "Future call delta (exact) = " << callDeltaExact << ", (divided diff) = " << callDeltaDiff 
            << ", difference = " << fabs(callDeltaExact - callDeltaDiff) << endl;

        cout << "Future put delta (exact) = " << putDeltaExact << ", (divided diff) = " << putDeltaDiff 
            << ", difference = " << fabs(putDeltaExact - putDeltaDiff) << endl;
        outFile << "Future put delta (exact) = " << putDeltaExact << ", (divided diff) = " << putDeltaDiff 
            << ", difference = " << fabs(putDeltaExact - putDeltaDiff) << endl;

        cout << "Future call gamma (exact) = " << callGammaExact << ", (divided diff) = " << callGammaDiff 
            << ", difference = " << fabs(callGammaExact - callGammaDiff) << endl;
        outFile << "Future call gamma (exact) = " << callGammaExact << ", (divided diff) = " << callGammaDiff 
            << ", difference = " << fabs(callGammaExact - callGammaDiff) << endl;

        cout << "Future put gamma (exact) = " << putGammaExact << ", (divided diff) = " << putGammaDiff 
            << ", difference = " << fabs(putGammaExact - putGammaDiff) << endl << endl;
        outFile << "Future put gamma (exact) = " << putGammaExact << ", (divided diff) = " << putGammaDiff 
            << ", difference = " << fabs(putGammaExact - putGammaDiff) << endl << endl;
        
        // Compute for a range of S
        cout << "Compute for a range of S:" << endl;
        outFile << "Compute for a range of S:" << endl;
        vector<double> vecCDeltaExact, vecPDeltaExact;
        vector<double> vecCDeltaDiff, vecPDeltaDiff;

        for (size_t i = 0; i < vecS.size(); ++i) // computation
        {
            futureOption.optionType = Call;
            futureOption.S = vecS[i];
            
            double callDeltaE = futureOption.Delta();
            double callDeltaD = futureOption.DeltaDiff(vecS[i], h);
            vecCDeltaExact.push_back(callDeltaE);
            vecCDeltaDiff.push_back(callDeltaD);

            futureOption.ChangeOptionType();

            double putDeltaE = futureOption.Delta();
            double putDeltaD = futureOption.DeltaDiff(vecS[i], h);
            vecPDeltaExact.push_back(putDeltaE);
            vecPDeltaDiff.push_back(putDeltaD);
        }

        for (size_t i = 0; i < vecS.size(); ++i) // comparison
        {
            double diffCall = fabs(vecCDeltaExact[i] - vecCDeltaDiff[i]);
            double diffPut  = fabs(vecPDeltaExact[i] - vecPDeltaDiff[i]);

            cout << "S = " << vecS[i] << ", Call delta exact = " << vecCDeltaExact[i]<< ", Call delta diff = " << vecCDeltaDiff[i];
            outFile << "S = " << vecS[i] << ", Call delta exact = " << vecCDeltaExact[i]<< ", Call delta diff = " << vecCDeltaDiff[i];

            if (diffCall > EPSILON)
            {
                cout << ", difference = " << diffCall;
                outFile << ", difference = " << diffCall;
            }
            else
            {
                cout << ", difference smaller than threshold";
                outFile << ", difference smaller than threshold";
            }

            cout << endl;
            outFile << endl;

            cout << "S = " << vecS[i] <<", Put delta exact = " << vecPDeltaExact[i] << ", Put delta diff = " << vecPDeltaDiff[i];
            outFile << "S = " << vecS[i] <<", Put delta exact = " << vecPDeltaExact[i] << ", Put delta diff = " << vecPDeltaDiff[i];

            if (diffPut > EPSILON)
            {
                cout << ", difference = " << diffPut;
                outFile << ", difference = " << diffPut;
            }
            else
            {
                cout << ", difference smaller than threshold";
                outFile << ", difference smaller than threshold";
            }

            cout << endl;
            outFile << endl;
        }
        cout << endl;
        outFile << endl;
    }

	outFile << "End of outputA.txt" << flush;
    outFile.close();
}