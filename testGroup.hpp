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
	size_t nFailed();
	size_t nPassed();
	string getName();
	string getReport();
	clock_t getRuntime();

	template<class T> void addAssertion(Assert<T> assertion);
	void run();
	
	template<class T> void equal(T x, T y);
	template<class T> void unequal(T x, T y);
	template<class T> void lessThan(T x, T y);
	template<class T> void greaterThan(T x, T y);
	template<class T> void lessThanEqual(T x, T y);
	template<class T> void greaterThanEqual(T x, T y);
	template<class T> void isNULL(T x);
	template<class T> void notNULL(T x);

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

template<class T> void TestGroup::addAssertion(Assert<T> assertion)
{
	T a = assertion.getA();
	T b = assertion.getB();
	vector<function<bool(T, T)>> test;

	switch (assertion.getType())
	{
		case Comparator::equal:
		{
			function<bool()> equalFunc = [=]() {
				return a == b;
			};

			assertions.push_back(equalFunc);
			//messages.push_back(assertion.getMessage());
			//comparisons.push_back(assertion.getComparison());
		}
		break;
		case Comparator::unequal:
		{
			function<bool()> unequalFunc = [=]() {
				return a != b;
			};

			assertions.push_back(unequalFunc);
			//messages.push_back(assertion.getMessage());
			//comparisons.push_back(assertion.getComparison());
		}
		break;
		case Comparator::lessThan:
		{
			function<bool()> lessThanFunc = [=]() {
				return a < b;
			};

			assertions.push_back(lessThanFunc);
			//messages.push_back(assertion.getMessage());
			//comparisons.push_back(assertion.getComparison());
		}
		break;
		case Comparator::greaterThan:
		{
			function<bool()> greaterThanFunc = [=]() {
				return a > b;
			};

			assertions.push_back(greaterThanFunc);
			//messages.push_back(assertion.getMessage());
			//comparisons.push_back(assertion.getComparison());
		}
		break;
		case Comparator::lessThanEqual:
		{
			function<bool()> lessThanEqualFunc = [=]() {
				return a <= b;
			};

			assertions.push_back(lessThanEqualFunc);
			//messages.push_back(assertion.getMessage());
			//comparisons.push_back(assertion.getComparison());
		}
		break;
		case Comparator::greaterThanEqual:
		{
			function<bool()> greaterThanEqualFunc = [=]() {
				return a >= b;
			};

			assertions.push_back(greaterThanEqualFunc);
			//messages.push_back(assertion.getMessage());
			//comparisons.push_back(assertion.getComparison());
		}
		break;
        
        case Comparator::isNull:
        {
            //  Do nothing for now.
        }break;
        case Comparator::notNull:
        {
            //  Do nothing for now.
        }break;
	}

	messages.push_back(assertion.getMessage());
	comparisons.push_back(assertion.getComparison());
}

size_t TestGroup::getSize()
{
	return assertions.size();
}

size_t TestGroup::nFailed()
{
	return nfailed;
}

size_t TestGroup::nPassed()
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
		return groupName + " passed all test";
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
		throw "Emptry set";
	}

	if (!executed)
	{
		throw 1;
	}

	return !passedAllTests;
}

void TestGroup::run()
{
	executed = true;

	for (size_t i = 0; i < assertions.size(); ++i)
	{
		clock_t tmp = clock();

		if (!assertions[i]())
		{
			passedAllTests = false;
			failedTests.push_back(i);
			failedMessages.push_back(messages[i]);
			failedComparisons.push_back(comparisons[i]);
		}

		clock_t runtime = clock() - tmp;
		runtimes.push_back(runtime);
	}
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
void TestGroup::equal(T x, T y)
{
	Assert<T> comparison(defaultMessage, x, y);
	comparison.equal();
	addAssertion(comparison);
}

template<class T> 
void TestGroup::unequal(T x, T y)
{
	Assert<T> comparison(defaultMessage, x, y);
	comparison.unequal();
	addAssertion(comparison);
}

template<class T>
void TestGroup::lessThan(T x, T y)
{
	Assert<T> comparison(defaultMessage, x, y);
	comparison.lessThan();
	addAssertion(comparison);
}

template<class T>
void TestGroup::greaterThan(T x, T y)
{
	Assert<T> comparison(defaultMessage, x, y);
	comparison.greaterThan();
	addAssertion(comparison);
}

template<class T>
void TestGroup::lessThanEqual(T x, T y)
{
	Assert<T> comparison(defaultMessage, x, y);
	comparison.lessThanEqual();
	addAssertion(comparison);
}

template<class T>
void TestGroup::greaterThanEqual(T x, T y)
{
	Assert<T> comparison(defaultMessage, x, y);
	comparison.greaterThanEqual();
	addAssertion(comparison);
}

template<class T>
void TestGroup::isNULL(T x)
{

}

template<class T>
void TestGroup::notNULL(T x)
{

}

#endif	//	TESTGROUP_HPP



//	TODO:
//
//
//
//


