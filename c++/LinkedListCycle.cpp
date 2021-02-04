class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;

        if (!head) {
            return false;
        }

        while (fastPtr && fastPtr->next) {
            fastPtr = fastPtr->next->next;            
            slowPtr = slowPtr->next;
            
            if (fastPtr == slowPtr) {
                return true;
            }
        }
        
        return false;
    }
};
