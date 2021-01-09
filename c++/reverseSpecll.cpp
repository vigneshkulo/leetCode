#include<iostream>
#include "LinkedList.h"

using namespace std;

int main() {

	LinkedList<int> list;
	int input[] = {1,2,3,4,5,6,7,8,9};

	Node<int> *head = list.createList(input, SIZE_OF(input));
	list.printList();

	int s = 1, e = 9;
	int diff = e - s + 1;

	Node<int> dummyHead;
	dummyHead.next = head;

	Node<int> *sprev = &dummyHead; 
	Node<int> *cur = head;

	while(--s) {
		sprev = cur;
		cur = cur->next;
	}

	Node<int> *tail = cur;

	Node<int> *prev = NULL;
	Node<int> *next = NULL;

	while(diff--) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	sprev->next = prev;
	tail->next = cur;

	cur = dummyHead.next;
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;

	return 0;
}
