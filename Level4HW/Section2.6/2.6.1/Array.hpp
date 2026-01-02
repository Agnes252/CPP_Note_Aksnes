/*
    Array.hpp

    Header file for an array class for Point objects.
    
    Test namespace.

    2025.3.20
    Ruochen Bao
*/

#ifndef Array_HPP
#define Array_HPP

#include "Point.hpp"
using namespace std;

namespace Aksnes
{
    namespace Containers
    {
        class Array
        {
        private:
            int m_size; // size of the array
            CAD::Point* m_data; // a dynamic array of Point objects

        public:
            // Constructors
            Array(); //default constructor
            Array(int size); //allocate by size constructor
            Array(const Array& arr); //copy constructor

            ~Array(); // destructor

            // member operator overloading
            Array& operator = (const Array& arr); // assignment operator overloading
            CAD::Point& operator [] (int index); // [] operator
            const CAD::Point& operator[](int index) const; // allow for processing const Array object
        
            // getters & setter
            int Size() const; // get size of the array
            void SetElement(int index, const CAD::Point& point); // setter
            const CAD::Point& GetElement (int index) const; // getter

        };
    }
} 

#endif
