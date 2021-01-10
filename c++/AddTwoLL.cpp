#include <iostream>
#include "LinkedList.h"

using namespace std;

Node<int>* reverseList(Node<int> *head) {
	Node<int> *prev = NULL;
	Node<int> *cur = head;
	Node<int> *next = NULL;

	while (cur && cur->next) {
		next = cur->next;
		cur->next = prev;

		prev = cur;
		cur = next;
	}
	cur->next = prev;

	return cur;
}

void printList(Node<int> *head) {
	Node<int> *curNode = head;
	while (curNode) {
		cout << curNode->val << " ";
		curNode = curNode->next;
	}
	cout << endl;
}

Node<int>* addLists(Node<int> *head1, Node<int> *head2) {
	int carry = 0;
	int sum = 0;
	Node<int> *curNode1 = head1;
	Node<int> *curNode2 = head2;
	Node<int> *prev = NULL;

	if (!head2) {
		return head1;
	}

	while (curNode1 && curNode2) {
		sum = (curNode1->val + curNode2->val + carry);
		curNode1->val = sum % 10;
		carry = sum / 10;

		prev = curNode1;
		curNode1 = curNode1->next;
		curNode2 = curNode2->next;
	}

	while (curNode1 && carry) {
		sum = curNode1->val + carry;
		curNode1->val = sum % 10;
		carry = sum / 10;

		prev = curNode1;
		curNode1 = curNode1->next;
	}

	if (carry) {
		prev->next = new Node<int>;
		prev->next->val = 1;		
		prev->next->next = NULL;		
	}

	return head1;
}

int main () {

	LinkedList<int> list1;
	LinkedList<int> list2;

//	int arr1[] = {5, 7, 3, 4};
//	int arr2[] = {9, 4, 6};

//	int arr1[] = {9, 9, 9, 9};
//	int arr2[] = {9, 9, 9, 9};

	int arr1[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
	int arr2[] = {0};

	Node<int> *head1 = list1.createList(arr1, SIZE_OF(arr1));
	Node<int> *head2 = list2.createList(arr2, SIZE_OF(arr2));

	list1.printList();
	list2.printList();
	cout << endl;

	head1 = reverseList(head1);
	head2 = reverseList(head2);

	Node<int> *output = addLists(head1, head2);

	output = reverseList(output);
	printList(output);
	return 0;
}
