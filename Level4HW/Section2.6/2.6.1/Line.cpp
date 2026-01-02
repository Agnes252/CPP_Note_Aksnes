/*
    Line.cpp

    Implementation of member functions in Line.hpp for class "Line"

    Test namespace.

    2025.3.20
    Ruochen Bao
*/

#include "Line.hpp"
#include "Point.hpp"
#include <sstream>

namespace Aksnes
{
    namespace CAD
    {
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

        // member assignment operator
        Line& Line::operator = (const Line& source)
        {
            // Avoid doing assign to myself
            if (this == &source)
                return *this;

            p1 = source.p1;
            p2 = source.p2;
            return *this;
        }

        // friend operator implementation
        ostream& operator << (ostream& os, const Line& line)// Send to ostream.
        {
            os << line.p1 << " - " << line.p2 <<endl; // Send to ostream
            return os;
        }
    }
}