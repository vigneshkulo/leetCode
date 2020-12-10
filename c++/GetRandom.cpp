#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Helper.h" 

#define MAX_SIZE	100

using namespace std;

typedef struct {
	string value;
	int index;
} Node;

class Solution {
	private:
		vector<int> keyList;
		unordered_map<int, Node*> hashMap;

	public:
		void print() {
			for (auto key: keyList) {
				printf("%s ", get(key).c_str());
			}
			printf("\n");
			Helper::print_vector<int>(keyList);
		}

		int add(int key, string value) {
			keyList.push_back(key);

			Node* curNode = new Node;
			if (!curNode) {
				printf("* Not enough memory\n");
				return -ENOMEM;
			}
			curNode->index = keyList.size() - 1;
			curNode->value = value;

			hashMap[key] = curNode;
			return 0;
		}

		string get(int key) {
			if (keyList.size() == 0) {
				printf("* No elements to get\n");
				return "";
			}

			auto itr = hashMap.find(key);
			if (itr == hashMap.end()) {
				printf("* Invalid key: %d\n", key);
				return "";
			}

			return itr->second->value;
		}

		string getRandom() {
			int randomIndex = rand() % keyList.size();
			return get(keyList[randomIndex]);
		}

		int remove(int key) {
			if (keyList.size() == 0) {
				printf("* No elements to remove\n");
				return -EINVAL;
			}

			auto itr = hashMap.find(key);
			if (itr == hashMap.end()) {
				printf("* Invalid key: %d\n", key);
				return -EINVAL;
			}

			int curIndex = itr->second->index;
			keyList[curIndex] = keyList.back();

			auto swap = hashMap.find(keyList[curIndex]);
			swap->second->index = curIndex;
			
			keyList.pop_back();
			delete itr->second;
			
			hashMap.erase(itr);
			return 0; 
		}

		void removeRandom() {
			int randomIndex = rand() % keyList.size();
			remove(keyList[randomIndex]);
		}

};

int main() {
	Solution sol;
	sol.add(1, "Adam");
	sol.add(2, "Ben");
	sol.add(3, "Cal");
	sol.add(4, "Dog");

	sol.print();
	printf("%s\n", sol.getRandom().c_str());
	printf("%s\n", sol.getRandom().c_str());
	printf("%s\n", sol.getRandom().c_str());
	printf("%s\n", sol.getRandom().c_str());
	printf("%s\n", sol.getRandom().c_str());
	printf("%s\n", sol.getRandom().c_str());
	printf("%s\n", sol.getRandom().c_str());
	printf("%s\n", sol.getRandom().c_str());
	printf("%s\n", sol.getRandom().c_str());
	printf("%s\n", sol.getRandom().c_str());
	printf("%s\n", sol.getRandom().c_str());

	sol.removeRandom();
	sol.removeRandom();
	sol.removeRandom();
	sol.removeRandom();
	sol.print();

	return 0;
}
