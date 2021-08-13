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
	unary.isTrue(isFalse, "Test false is not true");
	unary.isFalse(isTrue, "Test true is not false");
	unary.isTrue(isTrue, "Test true is true");
	unary.isFalse(isFalse, "Test false is false");

	//	Shorts
	unary.isZero(shortZero + 1, "Test 1s is not 0s");
	unary.isZero(shortZero, "Test  0s is 0s");
	unary.isZero(shortZero - 1, "Test -1S is not 0s");

	unary.isOne(shortZero, "Test 0s is not 1s");
	unary.isOne(shortZero + 1, "Test 1s is 1s");
	unary.isOne(shortZero - 1, "Test -1s is not 1s");

	//	Unsigned Shorts
	unary.isZero(ushortZero + 1, "Test 1us is not 0us");
	unary.isZero(ushortZero, "Test 0us is 0us");

	unary.isOne(ushortZero, "Test 0us is not 1us");
	unary.isOne(ushortZero + 1, "Test 1us is 1us");

	//	Integers
	unary.isZero(intZero + 1, "Test 1i is not 0i");
	unary.isZero(intZero, "Test 0i is 0i");
	unary.isZero(intZero - 1, "Test -1 is not 0i");

	unary.isOne(intZero, "Test 0i is not 1i");
	unary.isOne(intZero + 1, "Test 1i is 1i");
	unary.isOne(intZero - 1, "Test -1i is 1i");

	//	Unsigned Integers
	unary.isZero(uintZero + 1, "Test 1ui is not 0ui");
	unary.isZero(uintZero, "Test 0ui is 0ui");

	unary.isOne(uintZero, "Test 0ui is not 1ui");
	unary.isOne(uintZero + 1, "Test 1ui is 1ui");

	//	Longs
	unary.isZero(longZero + 1, "Test 1l is not 0l");
	unary.isZero(longZero, "Test 0l is 0l");
	unary.isZero(longZero - 1, "Test -1l is not 0l");

	unary.isOne(longZero, "Test 0l is not 1l");
	unary.isOne(longZero + 1, "Test 1l is 1l");
	unary.isOne(longZero - 1, "Test -1l is not 1l");

	//	Unsigned Long
	unary.isZero(ulongZero + 1, "Test 1ul is not 0ul");
	unary.isZero(ulongZero, "Test 0ul is not 0ul");

	unary.isOne(ulongZero, "Test 0ul is not 1ul");
	unary.isOne(ulongZero + 1, "Test 1ul is 1ul");

	//	Floats
	unary.isZero(floatZero + 1, "Test 1f is not 0f");
	unary.isZero(floatZero, "Test 0f is 0f");
	unary.isZero(floatZero - 1, "Test -1f is not 0f");

	unary.isOne(floatZero, "Test 0f is not 1f");
	unary.isOne(floatZero + 1, "Test 1f is 1f");
	unary.isOne(floatZero - 1, "Test -1f is not 1f");

	//	Double
	unary.isZero(doubleZero + 1, "Test 1d is not 0d");
	unary.isZero(doubleZero, "Test 0d is 0d");
	unary.isZero(doubleZero - 1, "Test -1d is not 0d");

	unary.isOne(doubleZero, "Test 0d is not 1d");
	unary.isOne(doubleZero + 1, "Test 1d is 1d");
	unary.isOne(doubleZero - 1, "Test -1d is not 1d");

	suite.addGroup(unary);
	suite.run();
	suite.write();
}