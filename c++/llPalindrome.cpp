#include <iostream>
#include <stack>
#include "LinkedList.h"

using namespace std;

static bool output = true;

Node<char>* isPalindrome(Node<char> *curNode, Node<char> *head) {
	if (!curNode) {
		return head;	
	}

	Node<char> *adj = isPalindrome(curNode->next, head);
	if (adj->val != curNode->val) {
		output = false;
	}

	return adj->next;
}

int main() {

	LinkedList<char> list;
#if 1
	char input[] = {'A', 'B', 'C', 'B', 'A'};
#else
	char input[] = {'A', 'B', 'C', 'D', 'A'};
#endif

	Node<char> *head = list.createList(input, sizeof(input)/sizeof(char));
	list.printList();

	/* Option 1*/
		stack<char> llstack;

		Node<char> *curNode = head;
		while (curNode) {
			llstack.push(curNode->val);
			curNode = curNode->next;
		}

		curNode = head;
		while (curNode && llstack.size()) {
			if (curNode->val != llstack.top()) {
				cout << false << endl;
				break;
			}
			curNode = curNode->next;
			llstack.pop();
		}

		if (!llstack.size())
			cout << true << endl;

	/* Option 2 */
		isPalindrome(head, head);
		cout << output << endl;
	return 0;
}
