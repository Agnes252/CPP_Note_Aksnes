// HardCoded.cpp
//
// C++ code to price an option, essential algorithms.
//
// We take CEV model with a choice of the elaticity parameter
// and the Euler method. We give option price and number of times
// S hits the origin.
//
// (C) Datasim Education BC 2008-2011
//

#include "OptionData.hpp" 
#include "NormalGenerator.hpp"
#include "Range.cpp"
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <cmath>
#include <iostream>

template <class T> void print(const std::vector<T>& myList)
{  // A generic print function for vectors
	
	std::cout << std::endl << "Size of vector is " << myList.size() << "\n[";

	// We must use a const iterator here, otherwise we get a compiler error.
	typename std::vector<T>::const_iterator i;
	for (i = myList.begin(); i != myList.end(); ++i)
	{
			std::cout << *i << ",";

	}

	std::cout << "]\n";
}

// New function: SDED calculation
template <typename Type>
boost::tuple<Type, Type> SDSE(const std::vector<Type>& price, const Type& r, const Type& T)
{
	Type temp1(0);
	Type temp2(0);
	int M = price.size();
	for (int i = 0; i < M; ++i)
	{
		temp1 += price[i];
		temp2 += price[i] * price[i];
	}

	Type sd = sqrt((temp2 - (temp1 * temp1) / M) / (M - 1)) * exp(- r * T);
	Type se = sd / sqrt(M);

	// Return the standard deviation and standard error
	return boost::make_tuple(sd, se);
}

namespace SDEDefinition
{ // Defines drift + diffusion + data

	OptionData* data;				// The data for the option MC

	double drift(double t, double X)
	{ // Drift term
	
		return (data->r)*X; // r - D
	}

	
	double diffusion(double t, double X)
	{ // Diffusion term
	
		double betaCEV = 1.0;
		return data->sig * pow(X, betaCEV);
		
	}

	double diffusionDerivative(double t, double X)
	{ // Diffusion term, needed for the Milstein method
	
		double betaCEV = 1.0;
		return 0.5 * (data->sig) * (betaCEV) * pow(X, 2.0 * betaCEV - 1.0);
	}
} // End of namespace


int main()
{
	std::cout <<  "1 factor MC with explicit Euler\n";
	
	// Store Batch 1 to Batch 2 data in a vector.
	typedef boost::tuple<double, double, double, double, double> TupleFive;
	vector<TupleFive> vecBatch;
	vecBatch.push_back(boost::make_tuple(1.25,155,0.25,0.03,150));
	vecBatch.push_back(boost::make_tuple(1.00, 100.0, 0.20, 0.00, 100.0)); // T, K, sig, r, S
	
	// Vector to store the prices of put and call.
	vector<double> vecCallPrice, vecPutPrice;

	long N = 100;
	std::cout << "Number of subintervals in time: ";
	std::cin >> N;

	// V2 mediator stuff.
	long NSim = 50000;
	std::cout << "Number of simulations: ";
	std::cin >> NSim;

	for (int i = 0; i < vecBatch.size(); i++)
	{
		OptionData myOption;
		myOption.T = vecBatch[i].get<0>();
		myOption.K = vecBatch[i].get<1>();
		myOption.sig = vecBatch[i].get<2>();
		myOption.r = vecBatch[i].get<3>();
		myOption.type = 1; // set to call option
		double S_0 = vecBatch[i].get<4>();

		// Create the basic SDE (Context class).
		Range<double> range(0.0, myOption.T);
		double VOld = S_0;
		double VNew;

		std::vector<double> x = range.mesh(N);

		double k = myOption.T / double(N);
		double sqrk = sqrt(k);

		// Normal random number.
		double dW;
		// Call option price.
		double price_c = 0.0;
		// Put option price.
		double price_p = 0.0;

		// NormalGenerator is a base class.
		NormalGenerator* myNormal = new BoostNormal();

		using namespace SDEDefinition;
		SDEDefinition::data = &myOption;

		std::vector<double> res;
		int coun = 0; // Number of times S hits origin.

		// A.
		for (long i = 1; i <= NSim; ++i)
		{ // Calculate a path at each iteration
			
			if ((i/100000) * 100000 == i)
			{// Give status after each 1000th iteration

					std::cout << i << std::endl;
			}
		
			VOld = S_0;
			for (unsigned long index = 1; index < x.size(); ++index)
			{

				// Create a random number
				dW = myNormal->getNormal();
					
				// The FDM (in this case explicit Euler)
				VNew = VOld  + (k * drift(x[index-1], VOld))
							+ (sqrk * diffusion(x[index-1], VOld) * dW);

				VOld = VNew;

				// Spurious values
				if (VNew <= 0.0) coun++;
			}
				
			double tmp1 = myOption.myPayOffFunction(VNew);
			price_c += (tmp1)/double(NSim);
			vecCallPrice.push_back(tmp1);
			myOption.type = -1; // set to put option
			double tmp2 = myOption.myPayOffFunction(VNew);
			price_p += (tmp2)/double(NSim);
			vecPutPrice.push_back(tmp2);
			myOption.type = 1; // set to call option
		}

		// D. Finally, discounting the average price.
		price_c *= exp(-myOption.r * myOption.T);
		price_p *= exp(-myOption.r * myOption.T);

		// Cleanup; V2 use scoped pointer.
		delete myNormal;

		std::cout << "Price, after discounting: Call = " << price_c << ", Put = " << price_p << std::endl;
		std::cout << "Number of times origin is hit: " << coun << endl;

		// Print SD and SE.
		boost::tuple<double, double> tupleCall = SDSE<double>(vecCallPrice, myOption.r, myOption.T);
		boost::tuple<double, double> tuplePut = SDSE<double>(vecPutPrice, myOption.r, myOption.T);
		std::cout << "Batch " << i + 1 << ", Call: NT = " << N << ", NSIM = " << NSim
			<< ", SD = " << tupleCall.get<0>() << ", SE = " << tupleCall.get<1>() << endl;
		std::cout << "Batch " << i + 1 << ", Put: NT = " << N << ", NSIM = " << NSim
			<< ", SD = " << tuplePut.get<0>() << ", SE = " << tuplePut.get<1>() << endl;
	}


	return 0;
}