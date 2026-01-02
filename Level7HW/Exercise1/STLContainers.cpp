/*
    STLContainers.cpp
    
    Test list, vector and map.

    2025.3.31
    Ruochen Bao
*/

#include <iostream>
#include <list>
#include <vector>
#include <map>
using namespace std;

int main()
{
	// A list
	list<int> l;
	l.push_back(10);
    l.push_front(20);
    l.push_back(30);

	cout << "The first element: " << l.front()
		<< ", the last element: " << l.back() << endl;

	// A vector
	vector<double> v(3); // initialise vector size to 3
	for (int i = 0; i < 5; i++) 
	{
		v.push_back(i + 0.1); // vector grow
	}

	for (int i = 0; i < v.size(); i++) 
	{
		cout << v[i] << ", "; // access through index operator
	}

    cout<<endl;

	// A map
	map<string, double> map1;
	string str[4] = { "a", "b", "c", "d" };
	
	for (int i = 0; i < 4; i++)
	{
		map1[str[i]] = i; // maps strings to doubles
	}

	for (int i = 0; i < map1.size(); i++)
	{
		cout << str[i] << " maps to " << map1[str[i]] << endl; // access through index operator
	}
}