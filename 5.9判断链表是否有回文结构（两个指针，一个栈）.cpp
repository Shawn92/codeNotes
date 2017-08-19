/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        // write code here
        stack<int> valStack;
        ListNode* p1 = pHead, *p2 = pHead;
        while (p1 && p2) {
            p2 = p2->next;
            if (p2) {
                valStack.push(p1->val);
                p2 = p2->next;
            }
            p1 = p1->next;
        }
        while (p1) {
            if (p1->val != valStack.top())
                return false;
            p1 = p1->next;
            valStack.pop();
        }
        return true;
    }
};