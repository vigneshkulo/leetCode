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

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> output;
        
        if (root == NULL) {
            return output;
        }
        
        int maxCol = -1;
        int minCol = 1;

        unordered_map<int, vector<int>> map;
        vector<tuple<TreeNode*, int>> queue;
        
        tuple<TreeNode*, int> item = {root, 0};
        queue.push_back(item);
        
        while (queue.size() > 0) {
            item = queue[0];
            queue.erase(queue.begin());
            
            auto col = get<1>(item);
            auto curNode = get<0>(item);
            
            maxCol = max(maxCol, col);
            minCol = min(minCol, col);
            
            if (map.find(col) == map.end()) {
                map[col] = {curNode->val};
            } else {
                map[col].push_back(curNode->val);
            }
            
            if (curNode->left) {
                queue.push_back({curNode->left, col-1});
            }
            if (curNode->right) {
                queue.push_back({curNode->right, col+1});                
            }
        }
        
        for (int i = minCol; i <= maxCol; ++i) {
            output.push_back(map[i]);
        }
        
        return output;
    }
};
