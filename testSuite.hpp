#pragma once

#ifndef TESTSUITE_HPP
#define TESTSUITE_HPP

#include "lazydeps.hpp"
#include "testGroup.hpp"

class TestSuite
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
};

TestSuite::TestSuite(string fname)
{
	output.open(fname.c_str());
}

void TestSuite::setMessageList(vector<string> messages)
{
	messageList = messages;
}

void TestSuite::addGroup(TestGroup group)
{
	groups.push_back(group);
}

void TestSuite::write()
{
	size_t testSum = 0;

	output << "Message,Time,Comparison,Number" << endl;

	for (size_t i = 0; i < groups.size(); ++i)
	{
		vector<string> messageList = groups[i].getFailedMessages();
		vector<string> comparisonList = groups[i].getFailedComparisons();

		double size = groups[i].getSize();
		double nPassed = groups[i].getPassedSize();
		double nFailed = groups[i].getFailedSize();

		//	The conditional statements below were created for divide by zero
		//	cases. For example when all tests pass. They can probably be collapsed

		if(size > 0)
		{
			output << "--\t" << nPassed << " passed, ";
			output << nFailed << " failed, out of ";
			output << size << " total tests " << endl;
		}

		else
		{
			output << "--	0 tests were created. 0 tests were executed" << endl;
		}

		if(nPassed > 0)
		{
			output << "--\t" << (nPassed / size * 100) << "% passed" << endl;
		}

		else
		{
			output << "--\t 0% passed" << endl;
		}

		if(nFailed > 0)
		{
			output << "--\t" << (nFailed / size * 100) << "% failed" << endl;
		}

		else
		{
			output << "--\t 0% failed" << endl;
		}

		for (size_t j = 0; j < messageList.size(); ++j)
		{
			output << "\"" << messageList[j] + "\"" << ",";
			output << to_string((double(groups[i].getTimes()[j]) / CLOCKS_PER_SEC)) << ",";
			output << comparisonList[j] << "," << (groups[i].getFailedIndicies()[j] + testSum) << endl;
		}

		if (messageList.size() == 0)
		{
			output << groups[i].getName() << " passed all " + to_string(groups[i].getSize()) + " tests" << endl;
		}

		else
		{
			output << "--\t" << groups[i].getName() << " failed to pass" << endl;
		}

		testSum += groups[i].getSize();
	}
}

void TestSuite::run()
{
	for (size_t i = 0; i < groups.size(); ++i)
	{
		groups[i].run();
	}
}

void TestSuite::run(size_t testNumber)
{

}

#endif	//	TESTSUITE_HPP


//	TODO:
//
//
//
