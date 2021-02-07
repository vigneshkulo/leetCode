class Solution {
public:
    
    void dfs(TreeNode* curNode, int curLevel, vector<int>& output) {
        if (NULL == curNode) {
            return;
        }
        
        if (output.size() == curLevel) {
            output.push_back(curNode->val);
        }
        
        dfs(curNode->right, curLevel + 1, output);
        dfs(curNode->left, curLevel + 1, output);

        return;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> output;

        dfs(root, 0, output);
        return output;
    }
};
