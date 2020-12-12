#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:    
    bool isPalindrome(int start, int end, string source) {
        while (end > start) {
            if (source[end] != source[start]) {
                return false;
            }
            --end;
            ++start;
        }
        return true;
    }
    
    void findPartition(int curIndex, string s, vector<string> &curList, vector<vector<string>> &output) {        
        if (curIndex == s.length()) {
            output.push_back(curList);
            return;
        }
        
        for (int i = curIndex; i < s.length(); ++i) {
            string subString = s.substr(curIndex, i - curIndex +1);
            if (isPalindrome(curIndex, i, s)) {
                curList.push_back(subString);
                findPartition(i+1, s, curList, output);
                curList.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        vector<string> tempList;
        
        findPartition(0, s, tempList, output);
        
        return output;
    }
};

int main() {
	Solution sol;
	string input = "ababab";

	vector<vector<string>> output;

	output = sol.partition(input);

	cout << "[";
	for (auto list: output) {
		cout << "[";
		for (auto str : list) {
			cout << str << ", ";
		}
		cout << "], ";
	}
	cout << "]" << endl;

	return 0;
}
