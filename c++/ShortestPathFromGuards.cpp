#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int PATH = 0;
const int WALL = -1;
const int GUARD = -2;

class Solution {
	public:
		void dfsUpdateMatrix(int row, int col, int depth, vector<vector<int>>& matrix) {
			if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size()) {
				return;
			}

			if ( (matrix[row][col] == GUARD) || (matrix[row][col] == WALL) ) {
				return;
			}

			if ( (matrix[row][col] != PATH) && (depth >= matrix[row][col]) ) {
				return;
			}

			matrix[row][col] = depth;
			dfsUpdateMatrix(row, col - 1, depth + 1, matrix);
			dfsUpdateMatrix(row, col + 1, depth + 1, matrix);
			dfsUpdateMatrix(row - 1, col, depth + 1, matrix);
			dfsUpdateMatrix(row + 1, col, depth + 1, matrix);
		}

		void findShortest(vector<vector<int>>& inp) {
			int row, col;
			vector<vector<int>> guards;

			for (row = 0; row < inp.size(); ++row) {
				for (col = 0; col < inp[0].size(); ++col) {
					if (inp[row][col] == GUARD) {
						guards.push_back({row, col});
					}
				}
			}

			for (auto guard : guards) {
				row = guard[0];
				col = guard[1];
				dfsUpdateMatrix(row, col - 1, 1, inp);
				dfsUpdateMatrix(row, col + 1, 1, inp);
				dfsUpdateMatrix(row - 1, col, 1, inp);
				dfsUpdateMatrix(row + 1, col, 1, inp);
			}

			return;
		}
};

int main () {
	
	Solution sol;

	/*
		O  O  O  O  G
		O  W  W  O  O
		O  O  O  W  O
		G  W  W  W  O
		O  O  O  O  G
	*/
	vector<vector<int>> inp = {
		{ 0,  0,  0,  0, -2},
		{ 0, -1, -1,  0, -2},
		{ 0,  0,  0, -1, -2},
		{-2, -1, -1, -1, -2},
		{ 0,  0,  0,  0, -2},
	};

	printf("* ---------- Before -----------\n");
	for (auto row : inp) {
		for (auto item : row) {
			printf("%2d ", item);
		}
		cout << endl;
	}

	sol.findShortest(inp);

	printf("\n* ---------- After -----------\n");
	for (auto row : inp) {
		for (auto item : row) {
			printf("%2d ", item);
		}
		cout << endl;
	}

	return 0;
}
