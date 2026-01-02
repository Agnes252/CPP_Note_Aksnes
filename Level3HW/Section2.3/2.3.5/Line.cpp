/*
    Line.cpp

    Implementation of member functions in Line.hpp for class "Line"

    Constant functions, arguments and passing by reference are set if applicable.

    2025.3.15
    Ruochen Bao
*/

#include "Line.hpp"
#include "Point.hpp"
#include <sstream>

// constructors
Line::Line() : p1(0, 0), p2(0, 0)
{
}

Line::Line(const Point& p1, const Point& p2) : p1(p1), p2(p2)
{
}

Line::Line(const Line& line) : p1(line.p1), p2(line.p2)
{
}

// destructor
Line::~Line()
{
}

// Accessing functions
const Point& Line::P1() const
{
    return p1;
}

const Point& Line::P2() const
{
    return p2;
}

// Modifiers
void Line::P1(const Point& newp1)
{
    p1 = newp1;
}

void Line::P2(const Point& newp2)
{
    p2 = newp2;
}

// line length calculation
double Line::Length() const
{
    return p1.Distance(p2);
}

// line description
string Line::ToString() const
{
    stringstream stream;

	stream << "Line: " << p1.ToString() << "-" << p2.ToString(); // print line description
	return stream.str();
}

