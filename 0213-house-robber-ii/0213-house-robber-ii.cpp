class Solution {
public:
    //Method-1 : Top-Down(Recursion + Memoization)
    
    //Time Complexity = O(n)
    //Space Complexity = O(n)
    
    int dp[101] ; //memoization dp array

    int solve(vector<int>& nums, int i, int n){
        //1.)handle base case
        if(i > n) return 0 ;

        //2.)check memoization array
        if(dp[i] != -1){
            return dp[i] ;
        }

        //3.) We have two choices : rob current house or skip
        int rob = nums[i] + solve(nums, i+2, n) ;

        int skip = solve(nums, i+1, n) ;

        //4.) return max of rob, skip
        return dp[i] = max(rob, skip) ;
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size() ;
        
        //1.) handle edge cases
        if(n == 1){ //only 1 house
            return nums[0] ; 
        }
        if(n == 2){ //only two houses
            return max(nums[0], nums[1]) ; //rob max money house
        }

        memset(dp, -1, sizeof(dp)) ; //fill memoization array with -1

        //Case-1 : if Robbed first house(0th index house)
        int rob_0th_house = solve(nums, 0, n-2) ;

        memset(dp, -1, sizeof(dp)) ;

        //Case-2 : if Robbed second house(1st index house)
        int rob_1st_house = solve(nums, 1, n-1) ;

        return max(rob_0th_house, rob_1st_house) ;
    }
};