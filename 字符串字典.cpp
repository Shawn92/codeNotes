#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


bool findInStr(const string& str, const string& strInDic) {
	if (str.find(strInDic) == 0)
		return true;
	return false;
}

void findStrInDic(const string& str, const set<string>& dic, int curPos, const string& resStr) {
	if (curPos == str.size()) {
		cout << resStr << endl;
		return;
	}
	for (auto word : dic) {
		if (findInStr(string(str.begin() + curPos, str.end()), word)) {
			findStrInDic(str, dic, curPos + word.size(), resStr + word + ",");
		}
	}
}

int main() {
	string str = "ilikealibaba";
	set<string> dic{"i", "like", "ali", "liba", "baba", "alibaba", "ba"};
	findStrInDic(str, dic, 0, "");
	system("pause");
	return 0;
}