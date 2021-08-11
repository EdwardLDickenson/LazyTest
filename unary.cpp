#include "lazytest.hpp"

int main(int argc, char *argv[])
{
	TestSuite suite("unary.csv");
	TestGroup unary("Unary Comparators");

	bool isFalse = false;
	bool isTrue = true;
	short shortZero = 0;
	unsigned ushortZero = 0;
	int intZero = 0;
	unsigned int uintZero = 0;
	long longZero = 0;
	unsigned long ulongZero = 0;
	float floatZero = 0;
	double doubleZero = 0;

	//	Boolean values
	unary.isTrue(isFalse);
	unary.isFalse(isTrue);
	unary.isTrue(isTrue);
	unary.isFalse(isFalse);

	//	Shorts
	unary.isZero(shortZero + 1);
	unary.isZero(shortZero);
	unary.isZero(shortZero - 1);

	unary.isOne(shortZero);
	unary.isOne(shortZero + 1);
	unary.isOne(shortZero - 1);

	//	Unsigned Shorts
	unary.isZero(ushortZero + 1);
	unary.isZero(ushortZero);

	unary.isOne(ushortZero);
	unary.isOne(ushortZero + 1);

	//	Integers
	unary.isZero(intZero + 1);
	unary.isZero(intZero);
	unary.isZero(intZero - 1);

	unary.isOne(intZero);
	unary.isOne(intZero + 1);
	unary.isOne(intZero - 1);

	//	Unsigned Integers
	unary.isZero(uintZero + 1);
	unary.isZero(uintZero);

	unary.isOne(uintZero);
	unary.isOne(uintZero + 1);

	//	Longs
	unary.isZero(longZero + 1);
	unary.isZero(longZero);
	unary.isZero(longZero - 1);

	unary.isOne(longZero);
	unary.isOne(longZero + 1);
	unary.isOne(longZero - 1);

	//	Unsigned Long
	unary.isZero(longZero + 1);
	unary.isZero(ulongZero);

	unary.isOne(longZero);
	unary.isOne(ulongZero + 1);

	//	Floats
	unary.isZero(floatZero + 1);
	unary.isZero(floatZero);
	unary.isZero(floatZero - 1);

	unary.isOne(floatZero);
	unary.isOne(floatZero + 1);
	unary.isOne(floatZero - 1);

	//	Double
	unary.isZero(doubleZero + 1);
	unary.isZero(doubleZero);
	unary.isZero(doubleZero - 1);

	unary.isOne(doubleZero);
	unary.isOne(doubleZero + 1);
	unary.isOne(doubleZero - 1);

	suite.addGroup(unary);
	suite.run();
	suite.write();
}
