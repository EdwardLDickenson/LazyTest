#pragma once

#ifndef TESTGROUP_HPP
#define TESTGROUP_HPP

#include "lazydeps.hpp"
#include "Comparator.hpp"

class TestGroup
{
private:
	vector<function<bool()>> assertions;
	vector<string> messages;
	vector<size_t> failedTests;
	vector<clock_t> runtimes;
	vector<string> failedMessages;
	vector<string> failedComparisons;
	vector<string> comparisons;
	string groupName;
	size_t nfailed;
	bool passedAllTests;
	bool executed;

	string defaultMessage;

public:
	TestGroup(string name);

	size_t getSize();
	size_t getFailedSize();
	size_t getPassedSize();
	string getName();
	string getReport();
	clock_t getRuntime();

	template<class T> void addAssertion(Assert<T> assertion);
	void run();

	template<class T> void equal(T x, T y, string message = "");
	template<class T> void unequal(T x, T y, string message = "");
	template<class T> void lessThan(T x, T y, string message = "");
	template<class T> void greaterThan(T x, T y, string message = "");
	template<class T> void lessThanEqual(T x, T y, string message = "");
	template<class T> void greaterThanEqual(T x, T y, string message = "");
	template<class T> void isTrue(T x, string message = "");
	template<class T> void isFalse(T x, string message = "");
	template<class T> void isZero(T x, string message = "");
	template<class T> void isOne(T x, string message = "");
	void isMax(short x, string message = "");
	void isMax(unsigned short x, string message = "");
	void isMax(int x, string message = "");
	void isMax(unsigned int x, string message = "");
	void isMax(long x, string message = "");
	void isMax(unsigned long x, string message = "");
	void isMax(float x, string message = "");
	void isMax(double x, string message = "");
	void isMin(short x, string message = "");
	void isMin(unsigned short x, string message = "");
	void isMin(int x, string message = "");
	void isMin(unsigned int x, string message = "");
	void isMin(long x, string message = "");
	void isMin(unsigned long x, string message = "");
	void isMin(float x, string message = "");
	void isMin(double x, string message = "");

	bool passed();
	bool failed();

	vector<clock_t> getTimes();
	vector<string> getFailedMessages();
	vector<size_t> getFailedIndicies();
	vector<string> getFailedComparisons();
	vector<string> getComparisons();
};

TestGroup::TestGroup(string name)
{
	groupName = name;
	nfailed = 0;
	passedAllTests = true;
	executed = false;
	defaultMessage = "No specified error message";
}

template<class T>
void TestGroup::addAssertion(Assert<T> comparison)
{
	T a = comparison.getA();
	T b = comparison.getB();
	string msg = comparison.getMessage();
	Comparator cmp = comparison.getType();

	//	Using a lambda function allows us to create a list of assertions with
	//	different types. Without a similar feature we would probably end up
	//	using something like a heterogenous container, which is reasonably
	//	difficult to implement, to accomplish the same result. Because a vector
	//	of these lambda functions contains variables to be tested we can pass
	//	variables of different types from the front end of the library.


	function<bool()> getResultFunc = [=]()->bool{
		Assert<T> assertion(msg, a, b);
		assertion.setType(cmp);

		return assertion.getResult();
	};

	messages.push_back(comparison.getMessage());
	comparisons.push_back(comparison.getComparison());
	assertions.push_back(getResultFunc);
}

void TestGroup::run()
{
	executed = true;

	for(size_t i = 0; i < assertions.size(); ++i)
	{
		clock_t tmp = clock();

		bool testPassed = assertions[i](/*No parameters, but this is technically a function call*/);

		if(!testPassed)
		{
			passedAllTests = false;
			failedTests.push_back(i);

			failedMessages.push_back(messages[i]);
			failedComparisons.push_back(comparisons[i]);
			++nfailed;
		}

		clock_t runtime = clock() - tmp;
		runtimes.push_back(runtime);
	}
}

size_t TestGroup::getSize()
{
	return assertions.size();
}

size_t TestGroup::getFailedSize()
{
	return nfailed;
}

size_t TestGroup::getPassedSize()
{
	return assertions.size() - nfailed;
}

clock_t TestGroup::getRuntime()
{
	if (!executed)
	{
		throw 1;
	}

	clock_t sum = 0;

	for (size_t i = 0; i < runtimes.size(); ++i)
	{
		sum += runtimes.at(i);
	}

	return sum;
}

string TestGroup::getName()
{
	return groupName;
}

string TestGroup::getReport()
{
	if (!executed)
	{
		throw 1;
	}

	if (passed())
	{
		return groupName + " passed all tests";
	}

	string result = "";

	for (size_t i = 0; i < failedTests.size(); ++i)
	{
		result += "\"" + messages.at(failedTests.at(i)) + "\"," + to_string(double(runtimes.at(i)) / CLOCKS_PER_SEC) + "\n";
	}

	result += groupName + " failed to pass" + "," + to_string(double(getRuntime()) / CLOCKS_PER_SEC) + "\n";

	return result;
}

bool TestGroup::passed()
{
	if (assertions.size() == 0)
	{
		throw 0;
	}

	if (!executed)
	{
		throw 1;
	}

	return passedAllTests;
}

bool TestGroup::failed()
{
	if (assertions.size() == 0)
	{
		throw "Empty set";
	}

	if (!executed)
	{
		throw 1;
	}

	return !passedAllTests;
}

vector<size_t> TestGroup::getFailedIndicies()
{
	return failedTests;
}

vector<clock_t> TestGroup::getTimes()
{
	return runtimes;
}

vector<string> TestGroup::getFailedMessages()
{
	return failedMessages;
}

vector<string> TestGroup::getFailedComparisons()
{
	return failedComparisons;
}

vector<string> TestGroup::getComparisons()
{
	return comparisons;
}

template<class T>
void TestGroup::equal(T x, T y, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<T> comparison(message, x, y);
	comparison.equal();
	addAssertion(comparison);
}

template<class T>
void TestGroup::unequal(T x, T y, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<T> comparison(message, x, y);
	comparison.unequal();
	addAssertion(comparison);
}

template<class T>
void TestGroup::lessThan(T x, T y, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<T> comparison(message, x, y);
	comparison.lessThan();
	addAssertion(comparison);
}

template<class T>
void TestGroup::greaterThan(T x, T y, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<T> comparison(message, x, y);
	comparison.greaterThan();
	addAssertion(comparison);
}

template<class T>
void TestGroup::lessThanEqual(T x, T y, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<T> comparison(message, x, y);
	comparison.lessThanEqual();
	addAssertion(comparison);
}

template<class T>
void TestGroup::greaterThanEqual(T x, T y, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<T> comparison(message, x, y);
	comparison.greaterThanEqual();
	addAssertion(comparison);
}

template<class T>
void TestGroup::isTrue(T x, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<T> comparison(message, x, true);
	comparison.isTrue();
	addAssertion(comparison);
}

template<class T>
void TestGroup::isFalse(T x, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<T> comparison(message, x, false);
	comparison.isFalse();
	addAssertion(comparison);
}

template<class T>
void TestGroup::isZero(T x, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<T> comparison(message, x, 0);
	comparison.isZero();
	addAssertion(comparison);
}

template<class T>
void TestGroup::isOne(T x, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<T> comparison(message, x, 1);
	comparison.isOne();
	addAssertion(comparison);
}

void TestGroup::isMax(short x, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<short> comparison(message, x, numeric_limits<short>::max());
	comparison.isMax();
	addAssertion<short>(comparison);
}

void TestGroup::isMax(unsigned short x, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<unsigned short> comparison(message, x, numeric_limits<unsigned short>::max());
	comparison.isMax();
	addAssertion<unsigned short>(comparison);
}

void TestGroup::isMax(int x, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<int> comparison(message, x, numeric_limits<int>::max());
	comparison.isMax();
	addAssertion(comparison);
}

void TestGroup::isMax(unsigned int x, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<unsigned int> comparison(message, x, numeric_limits<unsigned int>::max());
	comparison.isMax();
	addAssertion(comparison);
}

void TestGroup::isMax(long x, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<long> comparison(message, x, numeric_limits<long>::max());
	comparison.isMax();
	addAssertion(comparison);
}

void TestGroup::isMax(unsigned long x, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<unsigned long> comparison(message, x, numeric_limits<unsigned long>::max());
	comparison.isMax();
	addAssertion(comparison);
}

void TestGroup::isMax(float x, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<float> comparison(message, x, numeric_limits<float>::max());
	comparison.isMax();
	addAssertion(comparison);
}

void TestGroup::isMax(double x, string message)
{
	if(message.length() == 0)
	{
		message = defaultMessage;
	}

	Assert<double> comparison(message, x, numeric_limits<double>::max());
	comparison.isMax();
	addAssertion(comparison);
}

#endif	//	TESTGROUP_HPP



//	TODO:
//
//
//
//
