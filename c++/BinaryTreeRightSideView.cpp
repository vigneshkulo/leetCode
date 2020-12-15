#include <iostream>
#include <vector>
#include "Helper.h" 
#include "TreeCreator.h" 

using namespace std;

class Solution {
	public:
		vector<int> rightSideView(TreeNode* root) {
			vector<int> output;

			if (root == NULL) {
				return output;
			}

			vector<TreeNode*> queue;
			queue.push_back(root);

			while(queue.size() > 0) {
				int curLen = queue.size();
				output.push_back(queue.back()->val);

				for (int i = 0; i < curLen; ++i) {
					TreeNode* curNode = queue[0];
					queue.erase(queue.begin());
					if (curNode->left)
						queue.push_back(curNode->left);
					if (curNode->right)
						queue.push_back(curNode->right);
				}
			}

			return output;
		}
};

int main() {
	Solution sol;
        TreeCreator creator;
        vector<int> nodeList = {7, 3, 15, null, null, 9, 20};
        TreeNode* root = creator.createTree(nodeList);

	vector<int> output = sol.rightSideView(root);
	Helper::print_vector(output);
	
	return 0;
}
