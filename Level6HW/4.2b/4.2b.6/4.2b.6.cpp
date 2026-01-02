/*
    4.2b.6.cpp
    Test program for Stack class.

    Modifications:
    2025/3/30 Throw stack exception.
	2025/3/30 Value template argument.
		Now only stacks with the same size template argument can be copied/assigned

    2025.3.30
    Ruochen Bao
*/

#include "Stack.cpp"
#include <iostream>
using namespace std;

int main()
{
    // Test defalut constructor.
	Stack<int, 10> s0;

    // Test Push().
    cout << "Test Push():" << endl;
	for (int i = 0; i < 11; i++)
	{
		try
		{
			s0.Push(i);
		}
		catch (StackException& ex)
		{
			cout << ex.GetMessage() << endl;
		}
	}

    // Test copy constructor.
	Stack<int, 10> s1(s0); // 

	// Test assignment operator.
	Stack<int, 10> s2 = s0;

	// Test Pop().
    cout << "Test Pop():" << endl;
	for (int i = 0; i < 11; i++)
	{
		try
		{
			cout << s1.Pop() << endl;
		}
		catch (StackException& ex)
		{
			cout << ex.GetMessage() << endl;
		}
	}
}