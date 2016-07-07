#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "HugeNum.h"

int main()
{
	string a;
	cin >> a;

	string b;
	cin >> b;
	int num;
	HugeNum k;
	k.EnterString(a, b);
	string c;

	c = k.sum(a, b);
	cout << c;
	
	int ghj;
	cin >> ghj;
	return 0;
}