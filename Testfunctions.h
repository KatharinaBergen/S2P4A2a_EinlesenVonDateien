#ifndef TESTDRIVENDESIGN_H
#define TESTDRIVENDESIGN_H

#include <string>
using std::string;
#include <iostream>
using std::cout;

bool checkEquals(int exp, int act, const string& description, bool silent = false);
bool checkEquals(const string& exp, const string& act, const string& description, bool silent = false);
bool checkEquals(double exp, double act, double precision, const string& description, bool silent = false);
bool checkTrue(bool condition, const string& description, bool silent = false);
bool checkFalse(bool condition, const string& description, bool silent = false);
void printTestResult(bool successful, const string& testType, const string& description, const string& expected = "", const string& actual = "");

#endif // !TESTDRIVENDESIGN_H
