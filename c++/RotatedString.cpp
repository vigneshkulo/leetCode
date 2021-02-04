class Solution {
public:
    bool rotateString(string A, string B) {
        int curIndex = 0;
        
        if (A.length() != B.length()) {
            return false;
        }
        if (A.length() == 0 && B.length() == 0) {
            return true;
        }
        
        while (curIndex < B.length()) {          
            if (A[0] == B[curIndex]) {
                int startIndex = curIndex;
                int endIndex = B.length();
                int srcIndex = 0;
                while ((startIndex < endIndex) && (A[srcIndex] == B[startIndex])) {
                    ++startIndex;
                    ++srcIndex;
                    if (startIndex == B.length()) {
                        startIndex = 0;
                        endIndex = curIndex;
                    }
                }
                
                if ((endIndex == curIndex) && (startIndex == endIndex)) {
                    return true;
                }
            }
            ++curIndex;
        }

        return false;
    }
};
