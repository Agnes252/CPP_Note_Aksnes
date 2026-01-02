/*
    TestTuple.cpp
    A program that creates a Person tuple.

    2025.4.5
    Ruochen Bao
*/

#include <boost/tuple/tuple.hpp>	
#include <boost/tuple/tuple_io.hpp> 
#include <string>
#include <iostream>
using namespace std;

typedef boost::tuple<string, int, float> Person;

void Print(const Person& person)
{
	cout << "Name: " << person.get<0>() << "; Age: "
		<< person.get<1>() << "; Length: " << person.get<2>() << endl;
}

int main()
{
    using boost::tuple;
    cout.precision(4);

    // define Person tuple
    typedef boost::tuple<string, int, float> Person; // name, age, length

    // create person instance.
    Person p1 = boost::make_tuple(string("John"), 20, 1.84f);
	Person p2 = boost::make_tuple(string("Mary"), 21, 1.70f);
	Person p3 = boost::make_tuple(string("Alice"), 22, 1.65f);

    // Increment the age of one person.
	p1.get<1>() += 10;

	Print(p1);
	Print(p2);
	Print(p3);

    return 0;
}