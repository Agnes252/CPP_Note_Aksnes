/*
    TestRandomGenerator.cpp
    Simulate dice throwing.

    2025.4.5
    Ruochen Bao
*/

#include <boost/random.hpp> // Convenience header file
#include <iostream>
#include<map>
#include <ctime>			// std::time
using namespace std;

int main()
{
    // Throwing dice.
    // Mersenne Twister.
	boost::random::mt19937 myRng;

	// Set the seed.
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));

	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> six(1, 6);
    
    // create a map that holds the frequency of each outcome
    map<int, long> statistics; // Structure to hold outcome + frequencies
    int outcome; // Current outcome

    // get input (number of trails)
    cout << "How many darts to throw? "; long N; cin >> N; cout << endl;

    for (int i = 0; i < N; i++)
	{
		outcome = six(myRng);
		++statistics[outcome];
	}

	for (int i = 1; i <= 6; i++)
	{
		cout << "Trial " << i << " has " << (double)statistics[i] / (double)N * 100 << "% outcomes" << endl;
	}
}

