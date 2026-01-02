/*
    3.4.1.cpp

    Test program of the class Point, Line and Circle with main() function.

    Colon Syntax applied. 
    
    2025.3.22
    Ruochen Bao
*/

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // test
    Line l;

    // Conclusion: 
    // Colon syntax line constructor: point constructor/destructor is called twice.
    // Without Colon syntax: point constructor/destructor is called 4 times, assignment is called twice. 

    return 0;
}