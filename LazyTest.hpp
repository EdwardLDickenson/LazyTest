//=============================================================================
//---	Preprocessors	-------------------------------------------------------
//=============================================================================
#pragma once

#ifndef LAZYTEST_HPP
#define LAZYTEST_HPP

//=============================================================================
//---	Dependencies	-------------------------------------------------------
//=============================================================================
#include "TestSuite_deps.hpp"
#include "Assert.hpp"
#include "TestSuite.hpp"

/*class TestGroup
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

	bool passed();
	bool failed();

	vector<clock_t> getTimes();
	vector<string> getFailedMessages();
	vector<size_t> getFailedIndicies();
	vector<string> getFailedComparisons();
	vector<string> getComparisons();
};*/

/*class TestSuite
{
private:
	vector<TestGroup> groups;
	vector<string> messageList;
	string fname;
	ofstream output;

public:
	TestSuite(string fname);

	void setMessageList(vector<string> messages);
	void addGroup(TestGroup group);
	void run();
	void run(size_t testNumber);
	void write();
};*/

//------------------------------------------------------------------------------
//---	Assert	----------------------------------------------------------------
//------------------------------------------------------------------------------
//template<class T> Assert<T>::Assert(string msg, T x, T y)
//{
//	canCompare = false;
//	compareType = '?';
//	errmsg = msg;
//
//	a = x;
//	b = y;
//}
//
//template<class T> void Assert<T>::equal()
//{
//	compareType = '=';
//	canCompare = true;
//}
//
//template<class T> void Assert<T>::unequal()
//{
//	compareType = '!';
//	canCompare = true;
//}
//
//template<class T> bool Assert<T>::getResult()
//{
//	if (compareType == '=')
//	{
//		return a == b;
//	}
//
//	if (compareType == '!')
//	{
//		return a != b;
//	}
//}
//
//template<class T> bool Assert<T>::passed()
//{
//	if (!canCompare)
//	{
//		throw 0;
//	}
//
//	return false;
//}
//
//template<class T> bool Assert<T>::failed()
//{
//	if (!canCompare)
//	{
//		throw 0;
//	}
//
//	return true;
//}
//
//template<class T> string Assert<T>::getMessage()
//{
//	return errmsg;
//}
//
//template<class T> char Assert<T>::getType()
//{
//	if (!canCompare)
//	{
//		throw 0;
//	}
//
//	return compareType;
//}
//
//template<class T> string Assert<T>::getComparison()
//{
//	stringstream result;
//
//	//cout << a << endl;
//
//	result << "(\"";
//	result << a;
//	result << "\"";
//	result << compareType;
//	result << "\"";
//	result << b;
//	result << "\")";
//
//	return result.str();;
//}
//
//template<class T> T Assert<T>::getA()
//{
//	if (!canCompare)
//	{
//		throw 0;
//	}
//
//	return a;
//}
//
//template<class T> T Assert<T>::getB()
//{
//	if (!canCompare)
//	{
//		throw 0;
//	}
//
//	return b;
//}

//------------------------------------------------------------------------------
//---	Test Group -------------------------------------------------------------
//------------------------------------------------------------------------------
//template<class T> void TestGroup::addAssertion(Assert<T> assertion)
//{
//	T a = assertion.getA();
//	T b = assertion.getB();
//
//	vector<function<bool(T, T)>> test;
//
//	if (assertion.getType() == '=')
//	{
//		function<bool()> func = [=]() {
//			return a == b;
//		};
//
//		assertions.push_back(func);
//		//messages.push_back(assertion.getMessage());
//		//comparisons.push_back(assertion.getComparison());
//	}
//
//	else if (assertion.getType() == '!')
//	{
//		function<bool()> func = [=]() {
//			return a == b;
//		};
//
//		assertions.push_back(func);
//		//messages.push_back(assertion.getMessage());
//		//comparisons.push_back(assertion.getComparison());
//	}
//
//	//cout << assertion.getComparison() << endl;
//	messages.push_back(assertion.getMessage());
//	comparisons.push_back(assertion.getComparison());
//}
//
//TestGroup::TestGroup(string name)
//{
//	groupName = name;
//	nfailed = 0;
//	passedAllTests = true;
//	executed = false;
//}
//
//size_t TestGroup::getSize()
//{
//	return assertions.size();
//}
//
//size_t TestGroup::nFailed()
//{
//	return nfailed;
//}
//
//size_t TestGroup::nPassed()
//{
//	return assertions.size() - nfailed;
//}
//
//clock_t TestGroup::getRuntime()
//{
//	if (!executed)
//	{
//		throw 1;
//	}
//
//	clock_t sum = 0;
//
//	for (size_t i = 0; i < runtimes.size(); ++i)
//	{
//		sum += runtimes.at(i);
//	}
//
//	return sum;
//}
//
//string TestGroup::getName()
//{
//	return groupName;
//}
//
//string TestGroup::getReport()
//{
//	if (!executed)
//	{
//		throw 1;
//	}
//
//	if (passed())
//	{
//		return groupName + " passed all test";
//	}
//
//	string result = "";
//
//	for (size_t i = 0; i < failedTests.size(); ++i)
//	{
//		result += "\"" + messages.at(failedTests.at(i)) + "\"," + to_string(double(runtimes.at(i)) / CLOCKS_PER_SEC) + "\n";
//	}
//
//	result += groupName + " failed to pass" + "," + to_string(double(getRuntime()) / CLOCKS_PER_SEC) + "\n";
//
//	return result;
//}
//
//bool TestGroup::passed()
//{
//	if (assertions.size() == 0)
//	{
//		throw 0;
//	}
//
//	if (!executed)
//	{
//		throw 1;
//	}
//
//	return passedAllTests;
//}
//
//bool TestGroup::failed()
//{
//	if (assertions.size() == 0)
//	{
//		throw 0;
//	}
//
//	if (!executed)
//	{
//		throw 1;
//	}
//
//	return !passedAllTests;
//}
//
//void TestGroup::run()
//{
//	executed = true;
//
//	for (size_t i = 0; i < assertions.size(); ++i)
//	{
//		clock_t tmp = clock();
//
//		if (!assertions[i]())
//		{
//			passedAllTests = false;
//			failedTests.push_back(i);
//			failedMessages.push_back(messages[i]);
//			failedComparisons.push_back(comparisons[i]);
//		}
//
//		clock_t runtime = clock() - tmp;
//		runtimes.push_back(runtime);
//	}
//}
//
//vector<size_t> TestGroup::getFailedIndicies()
//{
//	return failedTests;
//}
//
//vector<clock_t> TestGroup::getTimes()
//{
//	return runtimes;
//}
//
//vector<string> TestGroup::getFailedMessages()
//{
//	return failedMessages;
//}
//
//vector<string> TestGroup::getFailedComparisons()
//{
//	return failedComparisons;
//}
//
//vector<string> TestGroup::getComparisons()
//{
//	return comparisons;
//}

//------------------------------------------------------------------------------
//---	Test Suite -------------------------------------------------------------
//------------------------------------------------------------------------------
//TestSuite::TestSuite(string fname)
//{
//	output.open(fname.c_str());
//}
//
//void TestSuite::setMessageList(vector<string> messages)
//{
//	messageList = messages;
//}
//
//void TestSuite::addGroup(TestGroup group)
//{
//	groups.push_back(group);
//}
//
//void TestSuite::write()
//{
//	size_t testSum = 0;
//
//	output << "Message,Number,Time,Comparison" << endl;
//
//	for (size_t i = 0; i < groups.size(); ++i)
//	{
//		vector<string> messageList = groups[i].getFailedMessages();
//		vector<string> comparisonList = groups[i].getFailedComparisons();
//
//		//for(size_t j = 0; j < messageList.size(); ++j)
//		//{
//		//	cout << messageList[i] << endl;
//		//	cout << comparisonList[i] << endl;
//		//}
//
//		for (size_t j = 0; j < messageList.size(); ++j)
//		{
//			//cout << groups[i].getComparisons()[j] << endl;
//			//output << messageList[j] << "," <<  to_string((double(groups[i].getTimes()[j]) / CLOCKS_PER_SEC)) << "," << groups[i].getComparisons()[j] << "," << (groups[i].getFailedIndicies()[j] + testSum) << endl;
//			output << messageList[j] << "," << to_string((double(groups[i].getTimes()[j]) / CLOCKS_PER_SEC)) << "," << comparisonList[j] << "," << (groups[i].getFailedIndicies()[j] + testSum) << endl;
//		}
//
//		if (messageList.size() == 0)
//		{
//			output << groups[i].getName() << " passed all " + to_string(groups[i].getSize()) + " tests" << endl;
//		}
//
//		else
//		{
//			output << groups[i].getName() << " failed to pass" << endl;
//		}
//
//		testSum += groups[i].getSize();
//	}
//}
//
//void TestSuite::run()
//{
//	for (size_t i = 0; i < groups.size(); ++i)
//	{
//		groups[i].run();
//	}
//}
//
//void TestSuite::run(size_t testNumber)
//{
//
//}




//	TODO:
//
//	Tried to do lazy evaluation with some function pointer/functional magic but unfortunatly that's nearly impossible or actually impossible with templated functions
//	Definitely a bullet point in the future iterations, but currently unfeasible
//
//	When a test group fails the report does not explain how many units passed.  This is a bug
//
//



#endif	//	LAZYTEST_HPP


