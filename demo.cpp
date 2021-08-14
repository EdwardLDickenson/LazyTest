#include "lazytest.hpp"

//	This demo intentionally causes error to demonstrate the functionality of
//	LazyTest and ancillary tools. It also provides a functional example of
//	how to use the library.

int main(int argc, char *argv[])
{
	TestSuite lazy("demo.csv");
	TestGroup testGroup("Test Group");

	testGroup.equal("These are equal", "These are equal", "Compare two identical string literals to see if they are equal to each other");
	testGroup.equal("These are unequal,", "but LazyTest expects them to be equal", "Compare two unequal string literals to make sure they are not equal to each other");

	testGroup.unequal("These are", "unequal", "Compare two unequal string literals to make sure they are unequal");
	testGroup.unequal("These are equal, but LazyTest expects them to be unequal", "These are equal, but LazyTest expects them to be unequal",
	"Compare two equal string literals to make sure they are unequal");

	testGroup.equal("Adding two or more assertions of the same value and type,", "should still count as two separate assertions", "Add two identical assertions 1st");
	testGroup.equal("Adding two or more assertions of the same value and type,", "should still count as two separate assertions", "Add two identical assertions 2nd");

	testGroup.equal(25, 25, "Test the equality operator");
	testGroup.equal(25, 52, "Check integer inequality");
	testGroup.equal(52, 25, "Make sure the order of operands does not change the result of an equality assertion");

	testGroup.unequal(25, 25, "Test the inequality operator");
	testGroup.unequal(25, 52, "These quantities are unequal and this should not be .csv file");
	testGroup.unequal(52, 25, "Make sure the order of operands does not change the result of an inequality assertion. This should not be in the .csv file");

	testGroup.lessThan(25, 25, "25 is equal to 25, 25 is not less than 25");
	testGroup.lessThan(25, 52, "25 is less than 52 and this should not be in the .csv file");
	testGroup.lessThan(52, 25, "52 is greater than 25. This tests the order of operands for the less than assertion");

	testGroup.lessThanEqual(25, 25, "25 is equal to 25 so this assertion should not appear in the .csv file");
	testGroup.lessThanEqual(25, 52, "25 is less than 52 so this assertion should not appear in the .csv file");
	testGroup.lessThanEqual(52, 25, "Check the order of operands for less than equal assertion");

	testGroup.greaterThan(25, 25, "25 is equal to 25, 25 is not greater than 25");
	testGroup.greaterThan(25, 52, "25 is less than 52, not greater");
	testGroup.greaterThan(52, 25, "52 is greater than 25 so this should not appear in the .csv file");

	testGroup.greaterThanEqual(25, 25, "25 is equal to 25 so this should not appear in the .csv file");
	testGroup.greaterThanEqual(25, 52, "25 is less than 52 not greater than 52");
	testGroup.greaterThanEqual(52, 25, "52 is greater than 25 so this should not appear in the .csv file");

	lazy.addGroup(testGroup);
	lazy.run();
	lazy.write();

	return 0;
}



//	TODO:
//
//	Improve the reporting functionality
//
//  The file extension: .csv should be turned on automatically for all files
//  unless overridden.
//  Comma separated value is the only supported file format currently planned
//
//
