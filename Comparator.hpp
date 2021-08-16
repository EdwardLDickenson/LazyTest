#pragma once

#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

enum Comparator {
	//	Unary operators
	isTrue,
	isFalse,
	isZero,
	isOne,
	isMax,

	//	Binary operators
	equal,
	unequal,
	lessThan,
	greaterThan,
	lessThanEqual,
	greaterThanEqual
	//isType
};

//  Should create a unicode/multicharacter version of this function.
//  For example the <= sign could be replaced with a single character.
//  But that would hurt compatibility while helping readability.
string getComparatorString(Comparator compareType)
{
	switch(compareType)
	{
		case Comparator::equal:
			return "==";
		break;
		case::Comparator::unequal:
			return "!=";
		break;
		case::Comparator::lessThan:
			return "<";
		break;
		case::Comparator::greaterThan:
			return ">";
		break;
		case::Comparator::lessThanEqual:
			return "<=";
		break;
		case::Comparator::greaterThanEqual:
			return ">=";
		break;
		case Comparator::isTrue:
			return "is True";
		break;
		case Comparator::isFalse:
			return "is False";
		break;
		case Comparator::isZero:
			return "==";
		break;
		case Comparator::isOne:
			return "==";
		break;
		case Comparator::isMax:
			return " is Max ";
		break;
	}

	//	This return statement is used for debug purposes
	return "Bad or missing comparison. Check the Comparator enum, testGroup, or Assert class";
}

#endif	//	COMPARATOR_HPP



//	TODO:
//
//
//
