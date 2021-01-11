#include <iostream>

#define SIZE_OF(x)	( (sizeof(x)) / (sizeof(x[0])) )
using namespace std;


struct Node {
	int x, y;
	struct Node* next;
};

void removeRedundant(Node* head) {
	Node* cur = head;
	Node* next = NULL;

	Node* start = head;
	Node* end = head;

	while (cur->next) {
		start = cur;

		while (cur->next && (start->x == cur->next->x)) {
			end = cur->next;
			cur = cur->next;
		}

		while (cur->next && (start->y == cur->next->y)) {
			end = cur->next;
			cur = cur->next;
		}

		while (start->next != end) {
			next = start->next;
			start->next = start->next->next;
		}
	}
}

int main() {
	int x[] = {0,0,0,2,5,7,7,7};
	int y[] = {1,5,8,8,8,8,10,12};

	Node* head = new Node;
	Node* cur = head;

	cur->x = x[0];
	cur->y = y[0];
	cur->next = NULL;

	for (int i = 1; i < SIZE_OF(x); ++i) {
		cur->next = new Node;
		cur = cur->next;
		cur->x = x[i];
		cur->y = y[i];
	}

	cur = head;
	while (cur) {
		cout << cur->x << ", " << cur->y << endl;
		cur = cur->next;
	}

	removeRedundant(head);

	cout << endl;
	cur = head;
	while (cur) {
		cout << cur->x << ", " << cur->y << endl;
		cur = cur->next;
	}

	return 0;
}
