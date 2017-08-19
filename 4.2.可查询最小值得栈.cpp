class Solution {
private:
    stack<int> DataStack;
    stack<int> MinStack;
public:
    void push(int value) {
        DataStack.push(value);
        if (MinStack.size() == 0 || value <= MinStack.top())
            MinStack.push(value);
    }
    void pop() {
        if(DataStack.top() == MinStack.top())
            MinStack.pop();
        DataStack.pop();
    }
    int top() {
        return DataStack.top();
    }
    int min() {
        return MinStack.top();
    }
};