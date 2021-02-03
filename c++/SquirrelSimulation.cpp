class Solution {
public:

    int distance(vector<int>& a, vector<int>& b) {
	    return (abs(a[0] - b[0]) + abs(a[1] - b[1]));
    }

    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
	    int maxSaving = INT_MIN;
            int nut2Tree = 0;
	    int nut2Squi = 0;
	    int output = 0;
	    int firstNut = 0;

	    for (int i = 0; i < nuts.size(); ++i) {
		nut2Tree = distance(nuts[i], tree);
    		nut2Squi = distance(nuts[i], squirrel);
		if ((nut2Tree - nut2Squi) > maxSaving) {
			maxSaving = nut2Tree - nut2Squi;
			firstNut = i;
		}
	    }

	    output += distance(squirrel, nuts[firstNut]);
	    output += distance(tree, nuts[firstNut]);

	    for (int i = 0; i < nuts.size(); ++i) {
		    if (i != firstNut) {
			    output += (distance(tree, nuts[i]) * 2);
		    }
	    }

	    return output;
    }
};
