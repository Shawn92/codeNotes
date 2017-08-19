/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Divide {
public:
    void add2List(ListNode* head, int val) {
        ListNode *p = head;
        while (p->next) p = p->next;
        ListNode *newNode = new ListNode(val);
        p->next = newNode;
    }

    ListNode* listDivide(ListNode* head, int val) {
        // write code here
        ListNode* headOfSmall = new ListNode(-1);
        ListNode* headOfEqual = new ListNode(-1);
        ListNode* headOfBig = new ListNode(-1);

        ListNode* p = head;
        while (p) {
            if (p->val <= val)
                add2List(headOfSmall, p->val);
           // else if (p->val == val)
                //add2List(headOfEqual, p->val);
            else
                add2List(headOfBig, p->val);
            p = p->next;
        }

        p = headOfSmall;

        if (headOfSmall->next) {
            p->next = headOfSmall->next;
            while (p->next) p = p->next;
        }
        if (headOfEqual->next) {
            p->next = headOfEqual->next;
            while (p->next) p = p->next;
        }
        if (headOfBig->next) {
            p->next = headOfBig->next;
        }
        return headOfSmall->next;
    }
};