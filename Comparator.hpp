#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

enum Comparator {
	//	Unary operators
	isNull,
	notNull,

	//	Binary operators
	equal,
	unequal,
	lessThan,
	greaterThan,
	lessThanEqual,
	greaterThanEqual
	//isType
};

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
		case::Comparator::isNull:
			return "Ø";
		break;
		case::Comparator::notNull:
			return "!Ø";
		break;
	}
}

#endif	//	COMPARATOR_HPP



//	TODO:
//
//
//


