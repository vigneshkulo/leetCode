class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        
        ListNode dummyHead;
        ListNode* curNode1 = l1;
        ListNode* curNode2 = l2;
        ListNode* nextNode = NULL;
        ListNode* prevNode = &dummyHead;
        
        int sum = 0;
        int carry = 0;
        
        while (curNode1 && curNode2) {
            sum = curNode1->val + curNode2->val + carry;
            carry = sum / 10;
            sum %= 10;
            
            prevNode->next = new ListNode;
            prevNode->next->val = sum;
            
            prevNode = prevNode->next;
            curNode1 = curNode1->next;
            curNode2 = curNode2->next;
        }
        
        while (curNode1) {
            sum = curNode1->val + carry;
            carry = sum / 10;
            sum %= 10;
            
            prevNode->next = new ListNode;
            prevNode->next->val = sum;

            prevNode = prevNode->next;            
            curNode1 = curNode1->next;
        }
        while (curNode2) {
            sum = curNode2->val + carry;
            carry = sum / 10;
            sum %= 10;
            
            prevNode->next = new ListNode;
            prevNode->next->val = sum;

            prevNode = prevNode->next;
            curNode2 = curNode2->next;            
        }
        
        if (carry) {
            prevNode->next = new ListNode;
            prevNode->next->val = 1;
        }
                
        return dummyHead.next;
    }
};
