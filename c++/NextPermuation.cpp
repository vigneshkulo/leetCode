class Solution {
public:
    void swap(int index1, int index2, vector<int>& nums) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
        return;
    }
    
    void nextPermutation(vector<int>& nums) {
        int endIndex = nums.size() - 1;
        int curIndex = endIndex;
        int startIndex = 0;
        
        while((curIndex > 0) && (nums[curIndex - 1] >= nums[curIndex])) {
            --curIndex;
        }
        
        startIndex = curIndex - 1;
        if (curIndex != 0) {
            curIndex = startIndex + 1;
            while ((curIndex <= endIndex) && (nums[curIndex] > nums[startIndex])) {
                ++curIndex;
            }
            curIndex -= 1;
            swap(curIndex, startIndex, nums);
        }
        
        curIndex = startIndex + 1;
        while (endIndex > curIndex) {
            swap(curIndex, endIndex, nums);
            --endIndex;
            ++curIndex;
        }
        return;
    }
};
