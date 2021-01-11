#include <iostream>
#include <unordered_map>

using namespace std;

typedef struct Node {
	int val;
	int key;
	struct Node* next;
	struct Node* prev;
} Node;

class LRUCache {
	private:
		int maxLen;
		struct Node dummyHead;
		unordered_map<int, Node*> hashMap;

	public:
		LRUCache(int capacity) {
			maxLen = capacity;
			dummyHead.next = &dummyHead;
			dummyHead.prev = &dummyHead;
		}

		void addNode(Node* curNode) {
			Node* tail = dummyHead.prev;

			tail->next = curNode;
			curNode->prev = tail;
			curNode->next = &dummyHead;
			dummyHead.prev = curNode;
		}

		void removeNode(Node* curNode) {
			Node* prev = curNode->prev;
			Node* next = curNode->next;

			prev->next = next;
			next->prev = prev;
		}

		void evict() {
			if (0 == maxLen) {
				return;
			}

			hashMap.erase(dummyHead.next->key);
			removeNode(dummyHead.next);
		}

		int get(int key) {
			if (hashMap.find(key) == hashMap.end()) {
				return -1;
			}

			Node* curNode = hashMap.at(key);
			removeNode(curNode);
			addNode(curNode);

			return curNode->val;
		}

		void put(int key, int value) {
			if (hashMap.size() == maxLen) {
				evict();
			}

			Node* curNode = new Node;
			curNode->val = value;
			curNode->key = key;
			addNode(curNode);
			hashMap[key] = curNode;
		}
};

int main () {

	LRUCache lRUCache(2);
	lRUCache.put(1, 1); // cache is {1=1}
	lRUCache.put(2, 2); // cache is {1=1, 2=2}
	cout << lRUCache.get(1) << endl;    // return 1
	lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
	cout << lRUCache.get(2) << endl;    // returns -1 (not found)
	lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
	cout << lRUCache.get(1) << endl;    // return -1 (not found)
	cout << lRUCache.get(3) << endl;    // return 3
	cout << lRUCache.get(4) << endl;    // return 4

	return 0;
}
