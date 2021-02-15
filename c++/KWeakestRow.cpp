class Solution {
public:
    int getSolCount(vector<int>& curRow, int start, int end) {
        if (start > end) {
            return curRow.size();
        }
        
        int mid = (start + end) / 2;
        
        if (curRow[mid] == 0 && curRow[mid-1] == 1) {
            return mid;
        } else if (curRow[mid] == 0) {
            return getSolCount(curRow, start, mid - 1);
        } else {
            return getSolCount(curRow, mid + 1, end);
        }
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> weakestRows;
        make_heap(weakestRows.begin(), weakestRows.end());

        int soldiers = 0;
        int curRowIndex = 0;
        
        for (auto& row : mat) {
            soldiers = 0;
            if (row[0] != 0) {
                soldiers = getSolCount(row, 0, row.size() - 1);
            }
            
            if ((weakestRows.size() == k) && (soldiers < weakestRows[0][0])) {
                pop_heap(weakestRows.begin(), weakestRows.end());
                weakestRows.pop_back();            
            }
            
            if (weakestRows.size() < k) {
                weakestRows.push_back({soldiers, curRowIndex});
                push_heap(weakestRows.begin(), weakestRows.end());
            }
            
            ++curRowIndex;
        }
        
        sort_heap(weakestRows.begin(), weakestRows.end());
        vector<int> output;
        
        for (auto& item : weakestRows) {
            output.push_back(item[1]);
        }
        
        return output;
    }
};
