#include <iostream>
#include "LinkedList.h" 

using namespace std;

int main () {

	LinkedList<int> list1;
	LinkedList<int> list2;

	int arr1[] = {1};
	int arr2[] = {1, 2, 3, 2, 3, 4};

	// Create lists
	Node<int>* head1 = list1.createList(arr1, sizeof(arr1)/sizeof(int));
	Node<int>* head2 = list2.createList(arr2, sizeof(arr2)/sizeof(int));

	// Intersect the lists
	list1.tail()->next = list2.getNode(4);

	list1.printList();
	list2.printList();

	// Find the intersection
	
	/* Option 1: */
		int len1 = 0, len2 = 0, diff = 0; 
		Node<int> *shorter = NULL, *longer = NULL;

		Node<int> *curNode = head1;
		while(curNode) {
			++len1;
			curNode = curNode->next;
		}
		
		curNode = head2;
		while(curNode) {
			++len2;
			curNode = curNode->next;
		}

		diff = abs(len1 - len2);

		if (len1 > len2) {
			longer = head1;
			shorter = head2;
		} else {
			shorter = head1;
			longer = head2;
		}

		while (diff--) {
			longer = longer->next;
		}

		while (longer && shorter && longer != shorter) {
			longer = longer->next;
			shorter = shorter->next;
		}

		cout << "They intersect at " << longer->val << endl;

	/* Option 2*/
		Node<int> * ptr1 = head1;
		Node<int> * ptr2 = head2;

		while (ptr1 != ptr2) {
			if (!ptr1) {
				ptr1 = head2;
			}
			if (!ptr2) {
				ptr2 = head1;
			}

			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}

		cout << "They intersect at " << ptr1->val << endl;

	return 0;
}
