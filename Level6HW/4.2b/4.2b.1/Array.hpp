/*
    Array.hpp

    Header file for an array class.
    
    2025.3.24
    Ruochen Bao
*/

#ifndef Array_HPP
#define Array_HPP

template <typename T> class Array
{
private:
    int m_size; // size of the array
    T* m_data; // a dynamic array of Point objects
    static int static_m_size; // static member indicating the default size

public:
    // Constructors
    Array(); //default constructor
    Array(int size); //allocate by size constructor
    Array(const Array<T>& arr); //copy constructor

    virtual ~Array(); // destructor

    // member operator overloading
    Array<T>& operator = (const Array<T>& arr); // assignment operator overloading
    T& operator [] (int index); // [] operator
    const T& operator[](int index) const; // allow for processing const Array object
 
    // getters & setter
    void SetElement(int index, const T& newT); // setter
    const T& GetElement (int index) const; // getter

    static int DefaultSize();
    static void DefaultSize(int size);

    };

#endif
