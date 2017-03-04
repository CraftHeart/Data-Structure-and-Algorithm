#pragma once
//exception classes for various error types

#ifndef MYEXCEPTIONS_H_
#define MYEXCEPTIONS_H_
#include<string>
#include<iostream>

using namespace std;

// illegal parameter value
class illegalParameterValue
{
public:
	illegalParameterValue(string theMessage = "illegal parameter value") :message{ theMessage } {
		cout << message << endl;
	}
	void outputMessage() { cout << message << endl; }
private:
	string message;
};

// illegal index
class illegalIndex
{
public:
	illegalIndex(string theMessage = "illegal index") :message{ theMessage } {}
	void outputMessage() { cout << message << endl; }
private:
	string message;
};

class ThrowException
{
public:
	ThrowException(string exception) :message{ exception }
	{
		cout << "error:" << message << endl;
	}
private:
	string message;
};
#endif // !MYEXCEPTIONS_H_
