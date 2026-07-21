class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maximumidx=0;
        for(int i=0;i<n;i++){
            if(i>maximumidx) return false;
            maximumidx=max(maximumidx,nums[i]+i);
        }
        return true;
    }
};