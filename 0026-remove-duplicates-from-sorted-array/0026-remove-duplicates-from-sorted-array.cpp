class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int k=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[k-1]){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {

//         for (int i = 0; i < nums.size() - 1; ) {

//             if (nums[i] == nums[i + 1]) {
//                 nums.erase(nums.begin() + i + 1);
//             }
//             else {
//                 i++;
//             }
//         }

//         return nums.size();
//     }
// };