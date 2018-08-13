#pragma once

#ifndef ASSERT_HPP
#define ASSERT_HPP

#include "TestSuite_deps.hpp"

//==============================================================================
//===	Definition	============================================================
//==============================================================================

template<class T> class Assert
{
private:

	T a;
	T b;
	bool canCompare;
	char compareType;
	string errmsg;

public:

	Assert(string msg, T x, T y);

	void equal();
	void unequal();

	bool passed();
	bool failed();
	bool getResult();
	char getType();

	string getMessage();
	string getComparison();
	T getA();
	T getB();
};

template<class T> Assert<T>::Assert(string msg, T x, T y)
{
	canCompare = false;
	compareType = '?';
	errmsg = msg;

	a = x;
	b = y;
}

template<class T> void Assert<T>::equal()
{
	compareType = '=';
	canCompare = true;
}

template<class T> void Assert<T>::unequal()
{
	compareType = '!';
	canCompare = true;
}

template<class T> bool Assert<T>::getResult()
{
	if (compareType == '=')
	{
		return a == b;
	}

	if (compareType == '!')
	{
		return a != b;
	}
}

template<class T> bool Assert<T>::passed()
{
	if (!canCompare)
	{
		throw 0;
	}

	return false;
}

template<class T> bool Assert<T>::failed()
{
	if (!canCompare)
	{
		throw 0;
	}

	return true;
}

template<class T> string Assert<T>::getMessage()
{
	return errmsg;
}

template<class T> char Assert<T>::getType()
{
	if (!canCompare)
	{
		throw 0;
	}

	return compareType;
}

template<class T> string Assert<T>::getComparison()
{
	stringstream result;

	//cout << a << endl;

	result << "(\"";
	result << a;
	result << "\"";
	result << compareType;
	result << "\"";
	result << b;
	result << "\")";

	return result.str();;
}

template<class T> T Assert<T>::getA()
{
	if (!canCompare)
	{
		throw 0;
	}

	return a;
}

template<class T> T Assert<T>::getB()
{
	if (!canCompare)
	{
		throw 0;
	}

	return b;
}

#endif	//	TESTSUITE_HPP



//	TODO:
//
//
//


