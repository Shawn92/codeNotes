#pragma once
#include <vector>
#include <string>
using namespace std;
void makeNext(string P, vector<int> next) {
	int	q, k;
	int m = P.size();
	next[0] = 0;
	for (q = 1, k = 0; q < m; ++q) {
		while (k > 0 && P[k] != P[q])
			k = next[k - 1];
		if (P[k] == P[q])
			++k;
		next[q] = k;
	}
}

int KMP(string T, string P) {
	int n = T.size();
	int m = P.size();
	if (n == 0 || m == 0)
		return -1;
	int i, q;
	vector<int> next(m);
	makeNext(P, next);
	for (i = 0, q = 0; i < n; ++i) {
		while (q > 0 && T[i] != P[q])
			q = next[q - 1];
		if (T[i] == P[q])
			++q;
		if (q == m)
			return i - m + 1;
	}
	return -1;
}