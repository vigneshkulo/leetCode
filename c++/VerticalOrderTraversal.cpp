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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int curLen = -1;
                
        vector<vector<int>> output;
        queue<tuple<TreeNode*, int>> q;
        map<int, vector<int>> index2Node;
        
        q.push({root, 0});
        
        while (q.size()) {
            curLen = q.size();
            unordered_map<int, vector<int>> curLevel;
            
            for (int i = 0; i < curLen; ++i) {
                auto item = q.front();
                q.pop();

                curLevel[get<1>(item)].push_back(get<0>(item)->val);
                if (get<0>(item)->left) {
                    q.push({get<0>(item)->left, get<1>(item) - 1});
                }
                if (get<0>(item)->right) {
                    q.push({get<0>(item)->right, get<1>(item) + 1});
                }
            }
            
            for (auto item : curLevel) {
                sort(item.second.begin(), item.second.end());
                for (auto val : item.second) {
                    index2Node[item.first].push_back(val);
                }
            }
        }
        
        for (auto item : index2Node) {
            output.push_back(item.second);
        }
        
        return output;
    }
};
