class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int len = 0;
        int output = 0;
        ListNode* curNode = head;
        
        while (curNode) {
            ++len;
            curNode = curNode->next;
        }
        
        curNode = head;
        while (curNode) {
            --len;
            if (curNode->val) {
                output += (1 << len);
            }
            curNode = curNode->next;
        }
        
        return output;
    }
};
