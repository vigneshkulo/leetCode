#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

vector<Node<int>*> reverseItems(Node<int>* head, int k) {
	Node<int> * prev = NULL;
	Node<int> * next = NULL;
	Node<int> * cur = head;

	for (int i = 0; i < k && cur; ++i) {
		next = cur->next;
		cur->next= prev;
		prev = cur;
		cur = next;
	}
	head->next = cur;

	for (int i = 1; i < k && cur; ++i) {
		cur = cur->next;
	}
	return {prev, cur};
}

int main() {
	
	LinkedList<int> list;
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int k = 10;

	Node<int> * head = list.createList(arr, SIZE_OF(arr));

	list.printList();

	Node<int> dummyHead;
	Node<int> *cur = head;
	Node<int> *prev = &dummyHead;

	vector<Node<int>*> ret; 
	while (cur) {
		ret = reverseItems(cur, k);

		prev->next = ret[0];
		prev = ret[1];

		if (prev) {
			cur = prev->next;
		} else {
			cur = NULL;
		}
	}

	/* Output */
	cur = dummyHead.next;
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;

	return 0;
}
