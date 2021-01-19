class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        
        ListNode *node1, *node2, *prev;
        ListNode dummyHead;
        
        node1 = l1;
        node2 = l2;
        prev = &dummyHead;
        
        while (node1 && node2) {
            if (node1->val <= node2->val) {
                prev->next = node1;               
                node1 = node1->next;
            } else {
                prev->next = node2;
                node2 = node2->next;
            }
            prev = prev->next;            
        }
        
        while (node1) {
            prev->next = node1;
            node1 = node1->next;
            prev = prev->next;
        }
        
        while (node2) {
            prev->next = node2;
            node2 = node2->next;
            prev = prev->next;
        }
        
        return dummyHead.next;
    }
};
