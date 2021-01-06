// Time: O(n), Space: O(n)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        unordered_set<int> duplicates;
        ListNode* curNode = head;
        
        while (curNode->next) {
            if (curNode->val == curNode->next->val)
                duplicates.insert(curNode->val);
            curNode = curNode->next;
        }
        
        if (!duplicates.size()) {
            return head;
        }
        
        ListNode dummyHead;
        dummyHead.next = head;
        
        ListNode* prev = &dummyHead;
        curNode = head;
        
        while (curNode) {
            if (duplicates.find(curNode->val) != duplicates.end()) {
                prev->next = curNode->next;
            } else {
                prev = curNode;
            }
            curNode = curNode->next;
        }
        
        return dummyHead.next;
    }
};
