struct Bound {
	int high;
	int low;

	Bound(int h = 0, int l = 0) : high(h),low(l) {
	}
};

int lenghtOfLongestConsecutiveSequence(vector<int> &num) {
	unordered_map<int, Bound> table;
	int local;
	int maxLen = 0;
	for (int i = 0; i < num.size(); ++i) {
		if (table.count(num[i])) {//如果找到当前key，不需要更新，继续
			continue;
		}
		//否则需要将当前值作为key插入到哈希表中
		local = num[i];//记录当前位置的值
		int low = local, high = local;//记录连续序列的最高和最低位

		if (table.count(local - 1))//如果local - 1 存在，利用到了local - 1 的 value 体现了动态规划思想
			low = table[local - 1].low;//那么当前local的地位等于local-1的低位

		if (table.count(local + 1))//如果local + 1 存在
			high = table[local + 1].high;//那么当前local的高位等于local+1的高位

		table[low].high = table[local].high = high;//更新local 和 local - 1 对应的高位值
		table[high].low = table[local].low = low;//跟新local 和 local + 1 对应的低位值

		maxLen = max(maxLen, high - low + 1);//更新连续序列的长度
	}
	return maxLen;
}