// TestBSPDE1.cpp
//
// Testing 1 factor BS model.
//
// (C) Datasim Education BV 2005-2011
//

#include "FdmDirector.hpp"

#include <iostream>
#include <string>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
using namespace std;

#include "UtilitiesDJD/ExcelDriver/ExcelDriverLite.hpp"
#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include "UtilitiesDJD/ExceptionClasses/DatasimException.hpp"

enum OptionType
{
	Put,
	Call
};

namespace BS // Black Scholes
{
	double sig = 0.25;
	double K = 75.0;
	double T = 0.55;
	double r = 0.06;
	double D = 0.0; // aka q
	enum OptionType Type = Call; // Call or Put

	double mySigma(double x, double t)
	{

		double sigmaS = sig * sig;

		return 0.5 * sigmaS * x * x;
	}

	double myMu(double x, double t)
	{

		return (r - D) * x;

	}

	double myB(double x, double t)
	{

		return  -r;
	}

	double myF(double x, double t)
	{
		return 0.0;
	}

	double myBCL(double t)
	{
		if (Type == Call)
		{
			return 0.0;
		}
		else
		{
			return K * exp(-r * t);
		}
	}

	double myBCR(double t)
	{
		if (Type == Call)
		{
			return 5.0 * K; // Smax
		}
		else
		{
			return 0.0;
		}
	}

	double myIC(double x)
	{ // Payoff 

		if (Type == Call)
		{
			return max(x - K, 0.0);
		}
		else
		{
			return max(K - x, 0.0);
		}
	}

}


int main()
{
	// Store Batch 1 to Batch 4 data in a vector.
	typedef boost::tuple<double, double, double, double, double> TupleFive;
	vector<TupleFive> vecBatch;
	vecBatch.push_back(boost::make_tuple(0.55, 75, 0.25, 0.06, 59));
	vecBatch.push_back(boost::make_tuple(1.0, 100, 0.2, 0.0, 0.0));
	vecBatch.push_back(boost::make_tuple(1.0, 10, 0.50, 0.12, 0.0));
	vecBatch.push_back(boost::make_tuple(30.0, 100.0, 0.30, 0.08, 0.0));
	// Name of each column.
	stringstream ss;
	string str;
	// The list of option price vectors.


	using namespace ParabolicIBVP;

	// Assignment of functions
	sigma = BS::mySigma;
	mu = BS::myMu;
	b = BS::myB;
	f = BS::myF;
	BCL = BS::myBCL;
	BCR = BS::myBCR;
	IC = BS::myIC;

	int J = 5; int N = 10000 - 1; // k = O(h^2) !!!!!!!!!
	double Smax = 60.0;			// Magix

	list<vector<double>> functionResult; // store results
	list<string> labels; // chart labels
	vector<double> fdir_xarr;


	for (int i = 0; i < vecBatch.size(); i++)
	{
		cout << "Batch " << i + 1 << ", start FDM" << endl;
		ss << i + 1;
		ss >> str;
		ss.clear();

		

		// Load parameter value of the batch.
		BS::T = vecBatch[i].get<0>();
		BS::K = vecBatch[i].get<1>();
		BS::sig = vecBatch[i].get<2>();
		BS::r = vecBatch[i].get<3>();
		BS::D = vecBatch[i].get<4>();
		BS::Type = Call;

		labels.push_back("Batch " + str + " Call");
		labels.push_back("Batch " + str + " Put");

		// Calculate call option price.
		FDMDirector fdirCall(Smax, BS::T, J, N);
		fdirCall.doit();
		functionResult.push_back(fdirCall.current());

		// Calculate put option price.
		BS::Type = Put;
		FDMDirector fdirPut(Smax, BS::T, J, N);
		fdirPut.doit();
		functionResult.push_back(fdirPut.current());

		cout << "Batch " << i + 1 << " Finished\n";

		fdir_xarr = fdirCall.xarr;

		
	}

	// Write the data to excel
	try
	{
		ExcelDriver xl; xl.MakeVisible(true);
		xl.CreateChart(fdir_xarr, labels, functionResult, string("Graph 9.F"), string("Underlying Value of S"), string("Option Price"));
	}
	catch (DatasimException& e)
	{
		e.print();
	}
	

	return 0;
}
