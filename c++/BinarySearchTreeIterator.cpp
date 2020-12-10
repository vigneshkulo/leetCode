#include <iostream>
#include <vector>
#include "TreeCreator.h" 

using namespace std;

class BSTIterator {
	public:
	    vector<TreeNode*> stack;

		BSTIterator(TreeNode* root) {
			addNode(root);
		}

		void addNode(TreeNode *curNode) {
			if (!curNode) {
			    return;
			}

			stack.push_back(curNode);
			return addNode(curNode->left);
		}

		int next() {
			auto curNode = stack.back();
			stack.pop_back();
			if (curNode->right)
			    addNode(curNode->right);

			return curNode->val;
		}

		bool hasNext() {
			return stack.size() > 0;
		}
};

int main() {

	TreeCreator creator;
	vector<int> nodeList = {7, 3, 15, null, null, 9, 20};
	TreeNode* root = creator.createTree(nodeList);
	creator.printTree(root);

	BSTIterator iterator(root);

	while (iterator.hasNext()) {
		printf("%d ", iterator.next());
	}
	printf("\n");

	return 0;
}
