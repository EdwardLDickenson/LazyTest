#include "lazytest.hpp"

int main(int argc, char *argv[])
{
	TestSuite lazy("LazyTest Demo");
	TestGroup testGroup("Test Group");	

	testGroup.equal("These are equal", "These are equal");
	testGroup.equal("These are unequal, ", "but LazyTest expects them to be equal");

	testGroup.unequal("These are", "unequal");
	testGroup.unequal("These are equal, but LazyTest expects them to be unequal", "These are equal, but LazyTest expects them to be unequal");

	testGroup.equal("Adding two or more assertions of the same value and type, ", "should still count as two separate asssertions");
	testGroup.equal("Adding two or more assertions of the same value and type, ", "should still count as two separate asssertions");

	testGroup.equal(25, 25);
	testGroup.equal(25, 52);
	testGroup.equal(52, 25);

	testGroup.unequal(25, 25);
	testGroup.unequal(25, 52);
	testGroup.unequal(52, 25);

	testGroup.lessThan(25, 25);
	testGroup.lessThan(25, 52);
	testGroup.lessThan(52, 25);

	testGroup.lessThanEqual(25, 25);
	testGroup.lessThanEqual(25, 52);
	testGroup.lessThanEqual(52, 25);

	testGroup.greaterThan(25, 25);
	testGroup.greaterThan(25, 52);
	testGroup.greaterThan(52, 25);

	testGroup.greaterThanEqual(25, 25);
	testGroup.greaterThanEqual(25, 52);
	testGroup.greaterThanEqual(52, 25);

	lazy.addGroup(testGroup);
	lazy.run();
	lazy.write();
}



//	TODO:
//
//	Improve the reporting functionality
//
//


