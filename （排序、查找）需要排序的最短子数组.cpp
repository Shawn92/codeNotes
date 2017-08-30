对于一个数组，请设计一个高效算法计算需要排序的最短子数组的长度。

给定一个int数组A和数组的大小n，请返回一个二元组，代表所求序列的长度。(原序列位置从0开始标号,若原序列有序，返回0)。保证A中元素均为正整数。

测试样例：[1,4,6,5,9,10],6
返回：2



class Subsequence {
public:
    int shortestSubsequence(vector<int> A, int n) {
        // write code here
        int left = 0,right = n - 1,max = 0xffffffff,min = 0x7fffffff;
        for (int i = 0; i < n; i++){
            if (A[i] >= max)
                max = A[i];
            else
                left = i;
        }
        for (int i = n - 1;i >= 0; i--){
            if (A[i] <= min)
                min = A[i];
            else
                right = i;
        }
        if ((left - right + 1) > 1)
            return left - right + 1;
        else
            return 0;
    }
};