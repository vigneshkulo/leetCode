/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#define ROOT 0
#define LEFT 1
#define RIGHT 2
#define INNER 3

class Solution {

private:
        vector<int> left;
        vector<int> leaves;
        vector<int> right;
    
public:
    void dfs(TreeNode* curNode, int flag) {
        if (curNode == NULL)
            return;

        if (curNode->left == NULL && curNode->right == NULL) {
            leaves.push_back(curNode->val);
            return;
        }

        if (flag == LEFT)
            left.push_back(curNode->val);
        else if (flag == RIGHT)
            right.push_back(curNode->val);

        int newFlag = -1;
        if (flag == ROOT || flag == LEFT)
            newFlag = LEFT;
        else if (flag == RIGHT) {
            if (curNode->right == NULL) {
                newFlag = RIGHT;
            } else {
                newFlag = INNER;
            }
        }
        dfs(curNode->left, newFlag);

        if (flag == ROOT || flag == RIGHT)
            newFlag = RIGHT;
        else if (flag == LEFT) {
            if (curNode->left == NULL)
                newFlag = LEFT;
            else
                newFlag = INNER;
        }
        dfs(curNode->right, newFlag);
        return;
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> output;
        if (root == NULL)
            return output;
        
        output.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
            return output;
                
        dfs(root, ROOT);
        
        for (auto item : left)
            output.push_back(item);
        
        for (auto item : leaves)
            output.push_back(item);
        
        for (int i = right.size() - 1; i >= 0; --i)
            output.push_back(right[i]);
                   
        return output;
    }
};
