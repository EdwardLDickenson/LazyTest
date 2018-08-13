#pragma once

#ifndef TESTSUITE_HPP
#define TESTSUITE_HPP

#include "TestSuite_deps.hpp"
#include "TestGroup.hpp"

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

	output << "Message,Number,Time,Comparison" << endl;

	for (size_t i = 0; i < groups.size(); ++i)
	{
		vector<string> messageList = groups[i].getFailedMessages();
		vector<string> comparisonList = groups[i].getFailedComparisons();

		//for(size_t j = 0; j < messageList.size(); ++j)
		//{
		//	cout << messageList[i] << endl;
		//	cout << comparisonList[i] << endl;
		//}

		for (size_t j = 0; j < messageList.size(); ++j)
		{
			//cout << groups[i].getComparisons()[j] << endl;
			//output << messageList[j] << "," <<  to_string((double(groups[i].getTimes()[j]) / CLOCKS_PER_SEC)) << "," << groups[i].getComparisons()[j] << "," << (groups[i].getFailedIndicies()[j] + testSum) << endl;
			output << messageList[j] << "," << to_string((double(groups[i].getTimes()[j]) / CLOCKS_PER_SEC)) << "," << comparisonList[j] << "," << (groups[i].getFailedIndicies()[j] + testSum) << endl;
		}

		if (messageList.size() == 0)
		{
			output << groups[i].getName() << " passed all " + to_string(groups[i].getSize()) + " tests" << endl;
		}

		else
		{
			output << groups[i].getName() << " failed to pass" << endl;
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

