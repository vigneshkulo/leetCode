#include <iostream>

#define SIZE_OF(x) (sizeof(x)/sizeof(x[0]))

template <typename T>
class Node {
	public:
		T val;
		Node<T> *next;
};

template <typename T>
class LinkedList {
	private:
		int len = 0;
		Node<T> dummyHead;

	public:
		Node<T>* createList(T* nodeArray, int num) {
			if (nodeArray == NULL || num <= 0) {
				return NULL;
			}

			Node<T>* curNode = NULL;
			Node<T>* prevNode = &dummyHead;
			prevNode->next = NULL;
			len = num;

			for (int i = 0; i < num; ++i) {
				curNode = new Node<T>;
				prevNode->next = curNode;

				curNode->val = nodeArray[i];
				curNode->next = NULL;

				prevNode = curNode;
			}

			return dummyHead.next;
		}

		void printList() {
			Node<T>* curNode = dummyHead.next;

			while (curNode) {
				std::cout << curNode->val << " ";
				curNode = curNode->next;
			}
			std::cout << std::endl;
		}

		Node<T>* getNode(int index) {
			Node<T>* curNode = dummyHead.next;
			if (!len || index > len) {
				return NULL;
			}

			while (--index) {
				curNode = curNode->next;
			}

			return curNode;
		}

		Node<T>* tail() {
			return getNode(len);
		}

		int getLen() {
			return len;
		}
};
