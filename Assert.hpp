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
	string compareType;
	string errmsg;

public:

	Assert(string msg, T x, T y);

	void equal();
	void unequal();
	void lessThan();
	void greaterThan();
	void lessThanEqual();
	void greaterThanEqual();
	void isNull();
	void notNull();

	bool passed();
	bool failed();
	bool getResult();
	string getType();

	string getMessage();
	string getComparison();
	T getA();
	T getB();
};

enum Comparator {
	equal,
	unequal,
	lesserThan,
	greaterThan,
	lessThanEqual,
	greaterThanEqual,
	isNull,
	notNull
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

template<class T> void Assert<T>::lessThan()
{
	compareType = '<';
	canCompare = true;
}

template<class T> void Assert<T>::greaterThan()
{
	compareType = '>';
	canCompare = true;
}

template<class T> void Assert<T>::greaterThanEqual()
{
	compareType = ">=";
	canCompare = true;
}

template<class T> void Assert<T>::lessThanEqual()
{
	compareType = "<=";
	canCompare = true;
}

template<class T> void Assert<T>::isNull()
{
	compareType = "Ø";
	canCompare = true;
}

template<class T> void Assert<T>::notNull()
{
	compareType = "!Ø";
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

	if (compareType == '<')
	{
		return a < b;
	}

	if (compareType == '>')
	{
		return a > b;
	}

	if (compareType == "<=")
	{
		return a <= b;
	}

	if (compareType == ">=")
	{
		return a >= b;
	}

	if (compareType == "Ø")
	{
		return a == NULL;
	}

	if (compareType == "!Ø")
	{
		return a != NULL;
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

template<class T> string Assert<T>::getType()
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

	cout << a << endl;

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


