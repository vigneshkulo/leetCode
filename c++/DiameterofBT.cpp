class Solution {
public:
    int diameter = 0;
    
    int dfs(TreeNode* curNode) {
        if (!curNode) {
            return 0;
        }
        
        int left = dfs(curNode->left);
        int right = dfs(curNode->right);
        
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
};
