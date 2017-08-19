//实现栈的逆序
class StackReverse {
public:
    int RemoveTheLast(vector<int>& A) {
        int i = A[0];
        A.erase(A.begin());
        if (A.size() == 0)
            return i;
        else {
            int last = RemoveTheLast(A);
            A.insert(A.begin(), i);
            return last;
        }
    }
    
    void reverseStack(vector<int>& A) {
        if(A.size() == 0)
            return;
        int i = RemoveTheLast(A);
        reverseStack(A);
        A.insert(A.begin(), i);
    }
    
    vector<int> reverseStack(vector<int> A, int n) {
        // write code here
        reverseStack(A);
        return A;
    }
};