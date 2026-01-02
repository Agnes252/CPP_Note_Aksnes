/*
    STLIterators.cpp
    
    Test two Sum() functions with list, vector and map.

    2025.3.31
    Ruochen Bao
*/

#include <iostream>
#include <list>
#include <vector>
#include <map>
using namespace std;

// Sum of the elements in a container
template <typename T> double Sum(const T& t)
{
    typename T::const_iterator i;
    double sum = 0.0;

    // iterate t to get sum
    for (i = t.begin(); i!=t.end(); ++i)
    {
        sum += *i;
    }
    return sum;
}

// Sum of the elements in a map
template <typename T1, typename T2> 
double Sum(const map<T1, T2>& t)
{
    typename map<T1, T2>::const_iterator i;
    double sum = 0.0;

    // iterate t to get sum
    for (i = t.begin(); i!=t.end(); ++i)
    {
        sum += (i->second);
    }
    return sum;
}

// Sum between two iterators in a container 
template <typename T>
double Sum(const typename T::const_iterator& start, const typename T::const_iterator& end)
{
	typename T::const_iterator i;
	double sum = 0.0;

	// Iterate the container
	for (i = start; i != end; ++i)
	{
		sum += *i;
	}

	return sum;
}

// Sum between two iterators in a map
template <typename T1, typename T2>
double Sum(const typename map<T1, T2>::const_iterator& start, const typename map<T1, T2>::const_iterator& end)
{
	typename map<T1, T2>::const_iterator i;
	double sum = 0.0;

	// Iterate the container
	for (i = start; i != end; ++i)
	{
		sum += i->second;
	}

	return sum;
}

int main()
{
    // sum of a list
    list<int> l;
	l.push_back(10);
    l.push_front(20);
    l.push_back(30); //  l = [20,10,30]
    cout << "test list:" << Sum(l) << "," <<
        Sum<list<int>>(++l.begin(), --l.end())<<endl;

    // sum of a vector
    vector<double> v; 
	for (int i = 0; i < 5; i++) 
	{
		v.push_back(i + 0.1); // vector grow
	} // v = [0.1, 1.1, 2.1, 3.1, 4.1]
    cout << "test vector:" << Sum(v) << "," <<
        Sum<vector<double>>(++v.begin(), --v.end())<<endl;

    // sum of a map
    map<string, double> map1;
	string str[4] = { "a", "b", "c", "d" };
	
	for (int i = 0; i < 4; i++)
	{
		map1[str[i]] = i; // maps strings to doubles
	} // map1 = {"a":0, "b":1, "c":2, "d":3}
    cout << "test map:" << Sum(map1) << "," <<
        Sum<string, double>(++map1.begin(), --map1.end())<<endl;
}