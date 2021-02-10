class Solution {
public:
    int dfs(TreeNode* curNode, int totalSum) {
        if (!curNode) {
            return INT_MIN;
        }
        
        int right = dfs(curNode->right, totalSum);
        if (right != INT_MIN) {
            curNode->val += right;
        } else if (totalSum != INT_MIN) {
            curNode->val += totalSum;
        }
        
        int left = dfs(curNode->left, curNode->val);
        return (left == INT_MIN) ? curNode->val : left;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        
        dfs(root, INT_MIN);
        return root;
    }
};
