class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        int num = 0;
        for (auto ch : A) {
            if (ch == '(') ++num;
            else if (ch == ')') --num;
            if (num <0) break;
        }
        return num == 0;
    }
};