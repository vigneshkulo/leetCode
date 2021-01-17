class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> forward(nums.size()+1, 1);
        vector<int> backward(nums.size()+1, 1);
        
        vector<int> output(nums.size(), 1);
        
        for (int i = 1; i <= nums.size(); i++) {
            forward[i] = forward[i-1] * nums[i-1];
        }
        
        
        for (int i = nums.size() - 1; i >= 0; --i) {
            backward[i] = backward[i+1] * nums[i];
        }
        
        for (int i = 0; i < nums.size(); i++) {
            output[i] = forward[i] * backward[i+1];
        }
        
        return output;
    }
};
