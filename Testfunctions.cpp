#include "Testfunctions.h"

bool checkEquals(int exp, int act, const string& description, bool silent)
{
	bool result{ exp == act };
	if (!silent) { printTestResult(result, "checkEquals", description, std::to_string(exp), std::to_string(act)); }
	return result;
}

bool checkEquals(const string& exp, const string& act, const string& description, bool silent)
{
	bool result{ exp == act };
	if (!silent) { printTestResult(result, "checkEquals", description, exp, act); }
	return result;
}

bool checkEquals(double exp, double act, double precision, const string& description, bool silent)
{
	double difference{ (exp >= act) ? (exp - act) : (act - exp) };
	bool result{ difference <= precision };
	if (!silent) { printTestResult(result, "checkEquals", description, std::to_string(exp), std::to_string(act)); }
	return result;
}

bool checkTrue(bool condition, const string& description, bool silent)
{
	bool result{ condition == true };
	if (!silent) { printTestResult(result, "checkEquals", description, std::to_string(condition), std::to_string(true)); }
	return result;
}

bool checkFalse(bool condition, const string& description, bool silent)
{
	bool result{ condition == false };
	if (!silent) { printTestResult(result, "checkEquals", description, std::to_string(condition), std::to_string(true)); }
	return result;
}

void printTestResult(bool successful, const string& testType, const string& description, const string& expected, const string& actual)
{
	if (!successful) cout << "FAILED test ";
	else cout << " succeeded test ";
	cout << testType << '(' << description << ')';
	cout << ", expected: " << expected;
	cout << ", actual: " << actual << std::endl;
}