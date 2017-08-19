/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead)
            return NULL;
        RandomListNode* cur = pHead;
        RandomListNode* next = cur->next;
        //将原链表 1->2->3-NULL 复制为 1->1->2->2->3->3->NULL
        while (next) {
            RandomListNode* newNode = new RandomListNode(cur->label);
            cur->next = newNode;
            newNode->next = next;
            cur = next;
            next = cur->next;
        }
        RandomListNode* newNode = new RandomListNode(cur->label);
        cur->next = newNode;
        //复制random的值
        cur = pHead;
        next = pHead->next;
        while (next->next) {
            next->random = cur->random;
            cur = cur->next->next;
            next = next->next->next;
        }
        cur = pHead;
        next = cur->next;
        RandomListNode* copyedHead = next;
        //拆分过程
        while (next) {
            cur->next = next->next;
            cur = cur->next;
            if (cur) {
                next->next = cur->next;
                next = cur->next;
            }
            else {
                next->next = NULL;
                next = NULL;
            }
        }
        return copyedHead;
    }
};