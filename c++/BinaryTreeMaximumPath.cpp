class Solution {
public:
    int maxPath = -INT_MAX;
    
    int dfs(TreeNode* curNode) {
        if (!curNode) {
            return 0;
        }
        
        int left = dfs(curNode->left);
        int right = dfs(curNode->right);
        
        maxPath = max(maxPath, (right >= 0 ? right : 0) + curNode->val + (left >= 0 ? left : 0));            
        
        return max(max(left, right) + curNode->val, curNode->val);
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxPath;
    }
};
