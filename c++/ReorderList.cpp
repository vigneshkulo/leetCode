class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }
        
        ListNode* first = head;
        ListNode* second = NULL;
        ListNode* curNode = head;
        ListNode *prev, *next, *next1;
        
        int len = 0, mid = 0;
        
        /* Calculate length */
        while (curNode) {
            ++len;
            curNode = curNode->next;
        }
        
        mid = len/2;
        if (len % 2) {
            ++mid;
        }
        
        /* Split it into two lists */
        curNode = head;
        for (int i = 1; i < mid; ++i) {
            curNode = curNode->next;
        }
        second = curNode->next;
        curNode->next = NULL;
        
        /* Reverse the second list */
        curNode = second;
        prev = NULL;
        next = NULL;
        while (curNode) {
            next = curNode->next;
            curNode->next = prev;
            prev = curNode;
            curNode = next;
        }
        second = prev;
        curNode = first;
        
        /* Merge the two lists */
        while (second) {
            next = curNode->next;
            curNode->next = second;
            
            next1 = second->next;
            second->next = next;
            
            curNode = next;
            second = next1;
        }        
    }
};
