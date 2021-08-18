#pragma once

#ifndef ASSERT_HPP
#define ASSERT_HPP

#include "lazydeps.hpp"
#include "Comparator.hpp"

//	Error Codes
//
//	#10:	A == B crashed.  Either A or B is invalid, or the eqaulity operation cannot be performed
//	#11:	A != B crashed.  Either A or B is invalid, or the inequality operation cannot be performed
//	#12:	A < B crashed.  Either A or B is invalid, or the less than operator cannot be performed
//	#13:	A > B crashed.  Either A or B is invalid, or the greater than operator cannot be performed
//	#14:	A <= B crashed.  Either A or B is invalid, or the less than equal operator cannot be performed
//	#15:	A >= B crashed.  Either A or B is invalid, or the greater than equal operator cannot be performed
//	#16:	A == NULL crashed.  Either A is invalid, or the operation cannot be performed.
//	#17:	A != NULL crashed.  Either A is invalid, or the operation cannot be performed.

//==============================================================================
//===	Definition	============================================================
//==============================================================================

template<class T> class Assert
{
private:
	T a;
	T b;
	bool canCompare;
	bool passes;
	bool fails;
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
	void isTrue();
	void isFalse();
	void isZero();
	void isOne();
	void isMax();

	bool passed();
	bool failed();
	bool getResult();
	Comparator getType();
	void setType(Comparator type);

	string getMessage();
	string getComparison();
	T getA();
	T getB();
};

template<class T> Assert<T>::Assert(string msg, T x, T y)
{
	canCompare = false;
	passes = false;
	fails = true;
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

template<class T> void Assert<T>::isTrue()
{
	compareType = Comparator::isTrue;
	canCompare = true;
}

template<class T> void Assert<T>::isFalse()
{
	compareType = Comparator::isFalse;
	canCompare = true;
}

template<class T>
void Assert<T>::isZero()
{
	compareType = Comparator::isZero;
	canCompare = true;
}

template<class T>
void Assert<T>::isOne()
{
	compareType = Comparator::isOne;
	canCompare = true;
}

template<class T>
void Assert<T>::isMax()
{
	compareType = Comparator::isMax;
	canCompare = true;
}

template<class T>
bool Assert<T>::getResult()
{
	switch(compareType)
	{
		//	First 10 error codes are currently reserved and unassigned
		case Comparator::equal:
		{
			try
			{
				passes = a == b;
			}
			catch(...)
			{
				throw 10;
			}
		}break;
		case Comparator::unequal:
		{
			try
			{
				passes = a != b;
			}
			catch(...)
			{
				throw 11;
			}
		}break;
		case Comparator::lessThan:
		{
			try
			{
				passes = a < b;
			}
			catch(...)
			{
				throw 12;
			}
		}break;
		case Comparator::greaterThan:
		{
			try
			{
				passes = a > b;
			}
			catch(...)
			{
				throw 13;
			}
		}break;
		case Comparator::lessThanEqual:
		{
			try
			{
				passes = a <= b;
			}
			catch(...)
			{
				throw 14;
			}
		}break;
		case Comparator::greaterThanEqual:
		{
			try
			{
				passes = a >= b;
			}
			catch(...)
			{
				throw 15;
			}
		}break;
		case Comparator::isZero:
		{
			try
			{
				return a == b;
			}
			catch(...)
			{
				throw 20;
			}
		}break;
		case Comparator::isOne:
		{
			try
			{
				return a == b;
			}
			catch(...)
			{
				throw 20;
			}
		}break;
		case Comparator::isMax:
		{
			try
			{
				return a == b;
			}
			catch(...)
			{
				throw 21;
			}
		}break;
		case Comparator::isMin:
		{
			try
			{
				return a == b;
			}
			catch(...)
			{
				throw 22;
			}
		}break;

		default:
		{
			errmsg = "Comparison not supported";
		}break;
	}

	fails = !passes;
	return passes;
}

template<>
bool Assert<bool>::getResult()
{
	switch(compareType)
	{
		case Comparator::isTrue:
			try
			{
				passes = a && true;
			}
			catch(...)
			{
				throw 18;
			}break;
		case Comparator::isFalse:
			try
			{
				passes = a ^ true;
			}
			catch(...)
			{
				throw 19;
			}break;

		default:
		{
			errmsg = "LazyTest type conversion failed";
		}break;
	}

	fails = !passes;
	return passes;
}

template<class T> bool Assert<T>::passed()
{
	if (!canCompare)
	{
		throw 0;
	}

	return passes;
}

template<class T> bool Assert<T>::failed()
{
	if (!canCompare)
	{
		throw 1;
	}

	return fails;
}

template<class T> string Assert<T>::getMessage()
{
	return errmsg;
}

template<class T> Comparator Assert<T>::getType()
{
	if (!canCompare)
	{
		throw 0;
	}

	return compareType;
}

template<class T> void Assert<T>::setType(Comparator type)
{
	compareType = type;
}

template<class T> string Assert<T>::getComparison()
{
	stringstream result;

	result << "(\"";
	result << a;
	result << "\"";
	result << getComparatorString(compareType);
	result << "\"";
	result << b;
	result << "\")";

	return result.str();
}

template<> string Assert<bool>::getComparison()
{
	string aStr = "False ";
	string bStr = "False ";

	if(a)
	{
		aStr = "True ";
	}

	if(b)
	{
		bStr = "True ";
	}

	stringstream result;

	result << "(";
	result << aStr;
	result << getComparatorString(compareType);

	if(compareType != Comparator::isTrue && compareType != Comparator::isFalse)
	{
		result << "\"";
		result << bStr;
		result << "\"";
	}

	result << ")";

	return result.str();
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
