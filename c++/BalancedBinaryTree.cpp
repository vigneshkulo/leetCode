class Solution {
public:
    int dfs(TreeNode* curNode) {
        if (curNode == NULL) {
            return 0;
        }
        
        int ldep = dfs(curNode->left);
        if (ldep < 0) {
            return ldep;
        }
        
        int rdep = dfs(curNode->right);
        if (rdep < 0) {
            return rdep;
        }
        
        if (abs(ldep - rdep) > 1) {
            return -1;
        }
        
        return max(ldep, rdep) + 1;
        
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        
        return (dfs(root) >= 0) ? true : false;
    }
};
