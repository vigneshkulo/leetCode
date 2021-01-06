// Time: O(n), Space: O(1)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        ListNode* curNode = NULL;
        ListNode* prev = NULL;
        
        ListNode dummyHead;
        dummyHead.next = head;
        
        prev = &dummyHead;
        curNode = head;
        
        while (curNode && curNode->next) {
            if (curNode->val == curNode->next->val) {
                while (curNode->next && curNode->val == curNode->next->val) {
                    curNode = curNode->next;
                }
                prev->next = curNode->next;
            } else {
                prev = curNode;
            }
            curNode = curNode->next;
        }
        
        return dummyHead.next;
    }
};
