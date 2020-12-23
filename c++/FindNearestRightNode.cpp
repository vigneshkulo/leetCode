class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if (root == NULL) {
            return NULL;
        }
        
        queue<TreeNode*> queue;
        
        queue.push(root);
        TreeNode* prev = NULL;
        
        while (queue.size()) {
            int curLen = queue.size();
            prev = NULL;
            
            for (int i = 0; i < curLen; ++i) {
                TreeNode* node = queue.front();
                queue.pop();
                
                if (prev == u) {
                    return node;
                }
                
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
                
                prev = node;
            }
        }
        
        return NULL;
    }
};
