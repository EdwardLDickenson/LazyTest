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
        //  Ø is not 0. It is empty set
		case::Comparator::isNull:
			return "u8\2205";
		break;
        //  Ø is not 0. It is empty set
		case::Comparator::notNull:
			return "!u8\2205";
		break;
	}
	
	// This return statement seems unlikely
	return "NULL comparator?";
}

#endif	//	COMPARATOR_HPP



//	TODO:
//
//
//


