class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        }
        
        Node *curNode = head, *parent = NULL;
        Node *newNode = NULL, *next = NULL;
        
        while (curNode) {
            newNode = new Node(curNode->val);
            newNode->next = curNode->next;
            curNode->next = newNode;
            curNode = newNode->next;
        }
        
        parent = head;
        curNode = head;
        
        while (curNode) {
            curNode = curNode->next;
            curNode->random = parent->random ? parent->random->next : NULL;
            
            parent = curNode->next;
            curNode = parent;
        }
        
        parent = head->next;
        curNode = head;
        while (curNode) {
            next = curNode->next;
            curNode->next = next->next;
            
            if (next->next) {
                next->next = next->next->next;
            }
            
            curNode = curNode->next;
        }
        
        
        return parent;
    }
};
