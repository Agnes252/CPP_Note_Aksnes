/*
    STLAlgorithms.cpp
    
    Test list, vector and map.

    2025.3.31
    Ruochen Bao
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "LessThan.cpp"
using namespace std;

// Global function checking if the input is less than a certain value.
int LessThanGlobal(double input)
{
	const double limit = 10.0;
	return input < limit;
}

int main()
{
    // create a list
    list<int> l;
	l.push_back(5);
    l.push_front(20);
    l.push_back(30);
    l.push_back(4);//  l = [20,5,30,4]

    // create a vector
    vector<double> v; 
	for (int i = 0; i < 5; i++) 
	{
		v.push_back(i + 0.1); // vector grow
	} // v = [0.1, 1.1, 2.1, 3.1, 4.1]

    // use the global function
    int result;
    result = count_if(l.begin(), l.end(), LessThanGlobal);
    cout << "The number of elements in list l that are less than 10 is " << result << endl;

    // use function object
    double limit = 10.0;
    result = count_if(v.begin(), v.end(), LessThan<double>(limit));
    cout << "The number of elements in vector v that are less than 10 is " << result << endl;

}