/*
    LessThan.hpp
    A function object.

    2025.4.1
    Ruochen Bao
*/

#ifndef LessThan_HPP
#define LessThan_HPP

template <typename T> 
class LessThan
{
private:
	T limit;

public:
	// Constructors
	LessThan();
	LessThan(const T& t);
	LessThan(const LessThan<T>& source);

	// Destructor
	~LessThan();

	// Member operator overloading
	LessThan<T>& operator = (const LessThan<T>& source);
	int operator () (const T& t) const; // return (t < limit)
};

#endif