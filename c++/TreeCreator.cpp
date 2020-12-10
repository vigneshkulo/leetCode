#include "TreeCreator.h"

using namespace std;

TreeNode* TreeCreator::createNode(int curIndex) {
	if (curIndex < 0 || curIndex >= nodeList.size() || nodeList[curIndex] == null) {
		return NULL;
	}

	TreeNode* curNode = new TreeNode;
	curNode->val = nodeList[curIndex];
	curNode->left = createNode((curIndex * 2) + 1);
	curNode->right = createNode((curIndex * 2) + 2);

	return curNode;
}

TreeNode* TreeCreator::createTree(vector<int> inputArray) {
	nodeList = inputArray;
	return createNode(0);
};

void TreeCreator::createList(TreeNode* curNode) {
	if (!curNode) {
		return;
	}

	printList.push_back( curNode->left != NULL ? curNode->left->val : null);
	printList.push_back( curNode->right != NULL ? curNode->right->val : null);

	createList(curNode->left);
	createList(curNode->right);
}

void TreeCreator::printTree(TreeNode* root) {
	if (!root) {
		return;
	}

	int lastIndex = 0;

	printList.clear();
	printList.push_back(root->val);
	createList(root);

	for (auto index = 0; index < printList.size(); ++index) {
		if (printList[index] != null)
			lastIndex = index;
	}

	for (auto index = 0; index <= lastIndex; ++index) {
		if (printList[index] == null)
			printf("null ");
		else
			printf("%d ", printList[index]);
	}
	printf("\n");
}
