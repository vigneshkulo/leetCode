class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curNode = head;
        
        while (curNode) {
            Node* newNode = new Node(curNode->val);
            newNode->next = curNode->next;
            curNode->next = newNode;
            
            curNode = newNode->next;
        }
        
        curNode = head;
        Node dummyHead(0);
        if (curNode) {
            dummyHead.next = curNode->next;
        } else {
            dummyHead.next = NULL;
        }
        
        while (curNode) {
            Node* newNode = curNode->next;
            if (curNode->random) {
                newNode->random = curNode->random->next;
            } else {
                newNode->random = NULL;
            }
            curNode = newNode->next;
        }     
        
        curNode = head;
        while (curNode) {
            Node* newNode = curNode->next;
            curNode->next = newNode->next;
            if (newNode->next) {
                newNode->next = newNode->next->next;
            }
            
            curNode = curNode->next;
        }
        
        return dummyHead.next;
    }
};
