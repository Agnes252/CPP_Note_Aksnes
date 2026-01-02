/*
    4.2b.4.cpp
    Test program for Stack class.

    2025.3.30
    Ruochen Bao
*/

#include "Stack.cpp"
#include <iostream>
using namespace std;

int main()
{
    // Test defalut constructor.
	Stack<int> s0;

    // Test Push().
    cout << "Test Push():" << endl;
	for (int i = 0; i < 11; i++)
	{
		try
		{
			s0.Push(i);
		}
		catch (ArrayException& ex)
		{
			cout << ex.GetMessage() << endl;
		}
	}

    // Test copy constructor.
	Stack<int> s1(s0);

	// Test assignment operator.
	Stack<int> s2 = s0;

	// Test Pop().
    cout << "Test Pop():" << endl;
	for (int i = 0; i < 11; i++)
	{
		try
		{
			cout << s1.Pop() << endl;
		}
		catch (ArrayException& ex)
		{
			cout << ex.GetMessage() << endl;
		}
	}
}