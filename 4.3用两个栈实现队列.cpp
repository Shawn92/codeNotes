class TwoStack {
private:
    stack<int> PushStack;
    stack<int> PopStack;
public:
    void Push(int val) {
        PushStack.push(val);
    }
    
    int Pop() {
        int val;
        if (!PopStack.empty()) {
            val = PopStack.top();
            PopStack.pop();
        }else{
            while (!PushStack.empty()) {
                int item = PushStack.top();
                PushStack.pop();
                PopStack.push(item);
            }
            val = PopStack.top();
            PopStack.pop();
        }
        return val;
    }
    
    vector<int> twoStack(vector<int> ope, int n) {
        // write code here
        vector<int> popArr;
        if (n > 0) {
            for (auto item : ope) {
                if (item > 0) 
                    Push(item);
                else
                    popArr.push_back(Pop());
            }
        }
        return popArr;
    }
};