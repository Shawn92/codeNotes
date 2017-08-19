对于一个没有重复元素的整数数组，请用其中元素构造一棵MaxTree，MaxTree定义为一棵二叉树，其中的节点与数组元素一一对应，同时对于MaxTree的每棵子树，它的根的元素值为子树的最大值。现有一建树方法，对于数组中的每个元素，其在树中的父亲为数组中它左边比它大的第一个数和右边比它大的第一个数中更小的一个。若两边都不存在比它大的数，那么它就是树根。请设计O(n)的算法实现这个方法。

给定一个无重复元素的数组A和它的大小n，请返回一个数组，其中每个元素为原数组中对应位置元素在树中的父亲节点的编号，若为根则值为-1。

测试样例：
[3,1,4,2],4
返回：[2,0,-1,2]

class MaxTree {
public:
    vector<int> buildMaxTree(vector<int> A, int n) {
        // write code here
        stack<int> monotonicStack;//一个单调栈
        vector<int> leftMax(n, 0x7fffffff);//存放A[i]左边第一个比A[i]大的数的位置
        vector<int> rightMax(n, 0x7fffffff);//存放A[i]右边第一个比A[i]大的数的位置
        vector<int> res(n, -1);//存放A[leftMax[i]]与A[rightMax[i]]中较小的那个，并作为返回结果
        //下面的过程分为两类：1、每次压栈时，比较当前A[i]与栈顶的大小，如果栈顶大于A[i]则作压栈操作，
        //                   如果栈顶小于当前A[i]则执行弹栈操作
        //                 2、压栈操作：每次压栈时将当前栈顶记录为A[i]左边第一个大于A[i]的数，记录在leftMax[i]中
        //                 3、弹栈操作：每次弹栈时，将当前需要弹出的数的下一个元素作为当前栈顶右边第一个大于当前栈顶的数，记录在rightMax[i]中
        for (int i = 0; i < n; ++i) {
            if (monotonicStack.empty() || A[monotonicStack.top()] > A[i]) {
                if (!monotonicStack.empty())
                    leftMax[i] = monotonicStack.top();
                monotonicStack.push(i);
            }
            else {
                while (!monotonicStack.empty() && A[monotonicStack.top()] < A[i]) {
                    rightMax[monotonicStack.top()] = i;
                    monotonicStack.pop();
                }
                if (!monotonicStack.empty())
					leftMax[i] = monotonicStack.top();
                monotonicStack.push(i);
            }
        }
        int temp = monotonicStack.top();
        monotonicStack.pop();
        while (!monotonicStack.empty()) {
            leftMax[temp] = monotonicStack.top();
            temp = monotonicStack.top();
            monotonicStack.pop();
        }
        for (int i = 0; i < n; ++i) {
            if (leftMax[i] != 0x7fffffff && rightMax[i] != 0x7fffffff)
                res[i] = A[leftMax[i]] < A[rightMax[i]] ? leftMax[i] : rightMax[i];
            else if (leftMax[i] == 0x7fffffff && rightMax[i] != 0x7fffffff)
                res[i] = rightMax[i];
            else if (leftMax[i] != 0x7fffffff && rightMax[i] == 0x7fffffff)
                res[i] = leftMax[i];
        }

        return res;
    }
};