有一个只由0，1，2三种元素构成的整数数组，请使用交换、原地排序而不是使用计数进行排序。

给定一个只含0，1，2的整数数组A及它的大小，请返回排序后的数组。保证数组大小小于等于500。

测试样例：
[0,1,1,0,2,2],6
返回：[0,0,1,1,2,2]
class ThreeColor {
public:
    vector<int> sortThreeColor(vector<int> A, int n) {
        // write code here
        int l = -1, r = n, index = 0;
        while (index < r) {
            if (A[index] == 0)
                swap(A[++l], A[index++]);
            else if (A[index] == 2)
                swap(A[--r], A[index]);
            else
                ++index;
        }
        
        return A;
    }
};