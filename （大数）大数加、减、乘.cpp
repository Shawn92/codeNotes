#pragma once
#include <string>
#include <cstring>
using namespace std;

//大数加法，a和b均是正数
string addTwoNum(string a, string b) {
	int c = 0;//记录进位
	string sum = "";// 记录a+b
	if (a.size() < b.size())//比较找出a、b中较大的那个
		swap(a, b);
	int i, j;
	for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; --i, --j) {
		int cur = a[i] - '0' + b[j] - '0' + c ;
		c = 0;
		if (cur > 9) {
			c = 1;
			cur = cur - 10;
		}
		sum += cur + '0';
	}
	for (; i >= 0; --i) {
		char cur = a[i] + c;
		c = 0;
		if (cur - '0' > 9) {
			c = 1;
			cur = cur - 10;
		}
		sum += cur;
	}
	if (c)//如果最终还有一位进位
		sum += c + '0';
	reverse(sum.begin(), sum.end());//翻转最终的结果
	return sum;
}

//大数减法，a和b均是正数
string subTwoNum(string a, string b) {
	string sub = "";
	int c = 0, flag = 0;
	if (a.size() < b.size() || (a.size() == b.size() && strcmp(a.c_str(), b.c_str()) < 0)) {
		swap(a, b);
		flag = 1;
	}
	int i, j;
	for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; --i, --j) {
		int cur = a[i] - c - b[j];
		c = 0;
		if (cur < 0) {
			cur += 10;
			c = 1;
		}
		sub += cur + '0';
	}
	for (; i >= 0; --i) {//a中剩下的
		char cur = a[i] - c;
		c = 0;
		if (cur < '0') {
			cur += 10;
			c = 1;
		}
		sub += cur;
	}

	reverse(sub.begin(), sub.end());
	while (sub[0] == '0')//去除所有前缀0
		sub.erase(0 ,1);
	if (flag) sub = '-' + sub;//如果结果为负数要加上符号
	if (sub == "") sub = "0";//如果去除前缀0后结果为空，就返回一个0
	return sub;
}

//大数乘法
string multiTwoSum(string a, char b) {
	string multiVal = "";
	if (b == '0' || a =="0")
		return "0";
	int c = 0;
	for (int i = a.size() - 1; i >= 0; --i) {
		int cur = (a[i] - '0') * (b - '0') + c;
		c = 0;
		if (cur > 9) {
			c = cur / 10;
			cur = cur % 10;
		}
		multiVal += cur + '0';
	}
	if (c)
		multiVal += c + '0';
	reverse(multiVal.begin(), multiVal.end());
	return multiVal;
}

string multiTwoSum(string a, string b) {
	string multiVal = "0";
	if (b == "0" || a == "0")
		return multiVal;
	int c = 0;
	for (int i = b.size() - 1; i >= 0; --i) {//从b的各位数开始，分别与a相乘，将得到的结果加入multiVal中
		string curVal = multiTwoSum(a, b[i]);
		if (curVal != "0")
			curVal = curVal + string(b.size() - 1 - i, '0');
		multiVal = addTwoNum(multiVal, curVal);
	}
	return multiVal;
}