class Solution {
public:
    vector<Node*> getDDList(Node* curNode) {
        if (!curNode) {
            return {NULL, NULL};
        }
        
        vector<Node*> left = getDDList(curNode->left);
        vector<Node*> right = getDDList(curNode->right);
        
        if (left[1]) {
            left[1]->right = curNode;
            curNode->left = left[1];
        } else {
            left[0] = curNode;
            left[1] = curNode;
        }
        
        if (right[0]) {
            curNode->right = right[0];
            right[0]->left = curNode;
        } else {
            right[0] = curNode;
            right[1] = curNode;
        }
        
        left[0]->left = right[1];
        right[1]->right = left[0];
        
        return {left[0], right[1]};
    }
    
    Node* treeToDoublyList(Node* root) {
        return getDDList(root)[0];
    }
};
