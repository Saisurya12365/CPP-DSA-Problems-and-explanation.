class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        // largest and second largest without sign and third largest positive
        sort(nums.begin(),nums.end());
        return max(nums[n-3]*nums[n-1]*nums[n-2], nums[0]*nums[1]*nums[n-1]);
    }
};