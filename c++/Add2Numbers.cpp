class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        ListNode dummyHead;
        ListNode *node1, *node2, *prev;
        
        prev = &dummyHead;
        node1 = l1;
        node2 = l2;
        
        while (node1 && node2) {
            prev->next = new ListNode;
            prev = prev->next;
            
            prev->next = NULL;
            prev->val = (node1->val + node2->val + carry) % 10;
            carry = (node1->val + node2->val + carry) / 10;
            
            node1 = node1->next;
            node2 = node2->next;
        }
        
        while (node1) {
            prev->next = new ListNode;
            prev = prev->next;
            
            prev->next = NULL;
            prev->val = (node1->val + carry) % 10;
            carry = (node1->val + carry) / 10;
            
            node1 = node1->next;
        }
        while (node2) {
            prev->next = new ListNode;
            prev = prev->next;
            
            prev->next = NULL;
            prev->val = (node2->val + carry) % 10;
            carry = (node2->val + carry) / 10;
            
            node2 = node2->next;
        }
        
        if (carry) {
            prev->next = new ListNode;
            prev = prev->next;
            prev->val = 1;
            prev->next = NULL;
        }
        
        return dummyHead.next;
    }
};
