class Solution {
public:
    bool dfs(TreeNode* curNode, long max, long min) {
        if (curNode == NULL) {
            return true;
        }
        
        if ((curNode->val >= max) || (curNode->val <= min)) {
            return false;
        }
        
        return (dfs(curNode->left, curNode->val, min) && dfs(curNode->right, max, curNode->val));
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MAX, LONG_MIN);
    }
};
