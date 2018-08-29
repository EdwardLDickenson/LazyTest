#pragma once

#ifndef ASSERT_HPP
#define ASSERT_HPP

#include "TestSuite_deps.hpp"

//==============================================================================
//===	Definition	============================================================
//==============================================================================

enum Comparator {
	equal,
	unequal,
	lessThan,
	greaterThan,
	lessThanEqual,
	greaterThanEqual,
	isNull,
	notNull
};

template<class T> class Assert
{
private:

	T a;
	T b;
	bool canCompare;
	//string compareType;
	Comparator compareType;

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

template<class T> Assert<T>::Assert(string msg, T x, T y)
{
	canCompare = false;
	//compareType = '?';
	errmsg = msg;

	a = x;
	b = y;
}

template<class T> void Assert<T>::equal()
{
	compareType = Comparator::equal;
	canCompare = true;
}

template<class T> void Assert<T>::unequal()
{
	compareType = Comparator::unequal;
	canCompare = true;
}

template<class T> void Assert<T>::lessThan()
{
	compareType = Comparator::lessThan;
	canCompare = true;
}

template<class T> void Assert<T>::greaterThan()
{
	compareType = Comparator::greaterThan;
	canCompare = true;
}

template<class T> void Assert<T>::lessThanEqual()
{
	compareType = Comparator::lessThanEqual;
	canCompare = true;
}

template<class T> void Assert<T>::greaterThanEqual()
{
	compareType = Comparator::greaterThanEqual;
	canCompare = true;
}

template<class T> void Assert<T>::isNull()
{
	compareType = Comparator::isNull;
	canCompare = true;
}

template<class T> void Assert<T>::notNull()
{
	compareType = Comparator::notNull;
	canCompare = true;
}

template<class T> bool Assert<T>::getResult()
{
	if (compareType == Comparator::equal)
	{
		return a == b;
	}

	if (compareType == Comparator::unequal)
	{
		return a != b;
	}

	if (compareType == Comparator::lessThan)
	{
		return a < b;
	}

	if (compareType == Comparator::greaterThan)
	{
		return a > b;
	}

	if (compareType == Comparator::lessThanEqual)
	{
		return a <= b;
	}

	if (compareType == Comparator::greaterThanEqual)
	{
		return a >= b;
	}

	if (compareType == Comparator::isNull)
	{
		return a == NULL;
	}

	if (compareType == Comparator::notNull)
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

	string cmp;

	switch(compareType)
	{
		case Comparator::equal:
			cmp = "=";
		break;
		case::Comparator::unequal:
			cmp = "!=";
		break;
		case::Comparator::lessThan:
			cmp = "<";
		break;
		case::Comparator::greaterThan:
			cmp = "";
		break;
		case::Comparator::lessThanEqual:
			cmp = "<=";
		break;
		case::Comparator::greaterThanEqual:
			cmp = ">=";
		break;
		case::Comparator::isNull:
			cmp = "Ø";
		break;
		case::Comparator::notNull:
			cmp = "!Ø";
		break;
	}

	return cmp;
}

template<class T> string Assert<T>::getComparison()
{
	stringstream result;

	cout << a << endl;

	result << "(\"";
	result << a;
	result << "\"";
	result << getType();
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


