/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class ChkLoop {
public:
    int chkLoop(ListNode* head, int adjust) {
        // write code here
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p1 && p2) {
            p1 = p1->next;
            p2 = p2->next;
            if (p2) p2 = p2->next;
            if (p1 == p2)
                break;
        }
        if (!p2) return -1;
        p2 = head;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1->val;

    }
};