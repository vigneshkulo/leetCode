#include <iostream>
#include <vector>

#define null    -999

typedef struct TreeNode {
        int val;
        struct TreeNode* left;
        struct TreeNode* right;
} TreeNode;

class TreeCreator {
        public:
                TreeCreator() {}

                TreeNode* createTree(std::vector<int> inputArray);
                void printTree(TreeNode* root);

	private:
		std::vector<int> nodeList;
		std::vector<int> printList;

                TreeNode* createNode(int curIndex);
                void createList(TreeNode* curNode);
};
