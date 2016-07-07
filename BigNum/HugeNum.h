#pragma once
#include <string>
#include <vector>

using namespace std;

class HugeNum
{
public:
	HugeNum();
	void EnterString(string x, string y);
	string multiply(string x, string y);
	string arrayToString(vector<int> a);
	vector<int> stringToArray(string a);
	string diff(string x, string y);
	string sum(string x, string y);
	int getCarry(int num);
	int num(char ak);

	~HugeNum();
private:
	string num1;
	string num2;
};

