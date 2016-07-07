#include "HugeNum.h"

#define OVERFLOW 2
#define ROW 50
#define COL 100+OVERFLOW

HugeNum::HugeNum()
{

}

void HugeNum::EnterString(string x, string y)
{
	num1 = x;
	num2 = y;
}

int HugeNum :: getCarry(int num) {
	int carry = 0;
	if (num >= 10) {
		while (num != 0) {
			carry = num % 10;
			num = num / 10;
		}
	}
	else carry = 0;
	return carry;
}

int HugeNum::num(char ak) {
	return int(ak) - 48;
}

string HugeNum::multiply(string a, string b)
{
	string ret;
	int a_len = a.length();
	int b_len = b.length();
	int mat[ROW][COL];
	for (int i = 0; i<ROW; ++i) {
		for (int j = 0; j<COL; ++j) {
			mat[i][j] = 0;

		}
	}

	int carry = 0, n, x = a_len - 1, y = b_len - 1;
	for (int i = 0; i<ROW; ++i) {
		x = a_len - 1;
		carry = 0;
		for (int j = (COL - 1) - i; j >= 0; --j) {
			if ((x >= 0) && (y >= 0)) {
				n = (num(a[x])*num(b[y])) + carry;
				mat[i][j] = n % 10;
				carry = getCarry(n);
			}
			else if ((x >= -1) && (y >= -1)) mat[i][j] = carry;
			x = x - 1;
		}
		y = y - 1;
	}

	carry = 0;
	int sum_arr[COL];
	for (int i = 0; i<COL; ++i) sum_arr[i] = 0;
	for (int i = 0; i<ROW; ++i) {
		for (int j = COL - 1; j >= 0; --j) {
			sum_arr[j] += (mat[i][j]);
		}
	}
	int temp;
	for (int i = COL - 1; i >= 0; --i) {
		sum_arr[i] += carry;
		temp = sum_arr[i];
		sum_arr[i] = sum_arr[i] % 10;
		carry = getCarry(temp);
	}

	for (int i = 0; i<COL; ++i) {
		ret.push_back(char(sum_arr[i] + 48));
	}

	while (ret[0] == '0') {
		ret = ret.substr(1, ret.length() - 1);
	}
	return ret;
}

string HugeNum::arrayToString(vector<int> a)
{
	string k;
	for (int i = 0; i < a.size(); i++)
	{
		k.push_back(a[i] + '0');
	}

	return k;
}

vector<int> HugeNum::stringToArray(string a)
{
	vector<int> buf1;
	for (int i = 0; i < a.length(); i++)
	{
		int k1 = (int)a[i] - '0';
		buf1.push_back(k1);
	}
	return buf1;
}

string HugeNum::diff(string x, string y)
{
	vector<int> buf1 = stringToArray(x);
	vector<int> buf2 = stringToArray(y);
	//reverse the buf1 and buf2 arrays
	vector<int> rbuf1;
	vector<int> rbuf2;

	int maxSize = 0;
	if (buf1.size() > buf2.size())
		maxSize = buf1.size();
	else
		maxSize = buf2.size();
	maxSize = maxSize + 1;
	for (int i = 0; i <maxSize; i++)
	{
		rbuf1.push_back(0);
		rbuf2.push_back(0);
	}

	int t = 0;

	for (int i = buf1.size() - 1; i >= 0; i--)
	{
		rbuf1[t++] = buf1[i];
	}
	t = 0;
	for (int i = buf2.size() - 1; i >= 0; i--)
	{
		rbuf2[t++] = buf2[i];
	}
	bool equal = true;
	if (buf1.size() == buf2.size())
	{
		for (int i = 0; i < buf1.size(); i++)
		{
			if (buf1[i] != buf2[i])
				equal = false;
		}
	}

	else
		equal = false;

	if (equal == true)
		return "0";

	//store the diff here
	vector<int> rbuf3;
	bool carryOn = false;
	int eachSum;
	for (int i = 0; i <maxSize; i++)
	{
		eachSum = 0;

		if (carryOn == true)
		{
			rbuf1[i] = rbuf1[i] - 1;
			carryOn = false;
		}

		if (rbuf1[i] >= rbuf2[i])
			eachSum = rbuf1[i] - rbuf2[i];

		else
		{
			carryOn = true;
			eachSum = rbuf1[i] - rbuf2[i] + 10;
		}
		rbuf3.push_back(eachSum);
	}

	int k = maxSize - 1;
	while (rbuf3[k] == 0)
	{
		maxSize = maxSize - 1;
		k = k - 1;
	}

	string result;
	for (int i = maxSize - 1; i >= 0; i--)
	{
		result.push_back(rbuf3[i] + '0');
	}

	return result;
}

string HugeNum::sum(string x, string y)
{
	vector<int> buf1 = stringToArray(x);
	vector<int> buf2 = stringToArray(y);
	//reverse the buf1 and buf2 arrays
	vector<int> rbuf1;
	vector<int> rbuf2;

	int maxSize = 0;
	if (buf1.size() > buf2.size())
		maxSize = buf1.size();
	else
		maxSize = buf2.size();
	maxSize = maxSize + 1;
	for (int i = 0; i <maxSize; i++)
	{
		rbuf1.push_back(0);
		rbuf2.push_back(0);
	}

	int t = 0;

	for (int i = buf1.size() - 1; i >= 0; i--)
	{
		rbuf1[t++] = buf1[i];
	}
	t = 0;
	for (int i = buf2.size() - 1; i >= 0; i--)
	{
		rbuf2[t++] = buf2[i];
	}

	//store the sum here
	vector<int> rbuf3;
	bool carryOn = false;
	for (int i = 0; i <maxSize; i++)
	{
		int eachSum = rbuf1[i] + rbuf2[i];
		if (carryOn == true)
		{
			eachSum = eachSum + 1;
			carryOn = false;
		}
		if (eachSum >= 10)
		{
			eachSum = eachSum - 10;
			carryOn = true;
		}
		rbuf3.push_back(eachSum);
	}

	if (rbuf3[maxSize - 1] == 0)
		maxSize = maxSize - 1;

	string result;
	for (int i = maxSize - 1; i >= 0; i--)
	{
		result.push_back(rbuf3[i] + '0');
	}

	return result;
}


HugeNum::~HugeNum()
{
}
