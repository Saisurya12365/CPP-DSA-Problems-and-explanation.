class Solution {
public:
    int countPrimes(int n) {
        int cnt=0;
        vector<int>nums(n+1,1);
        for(int i=2;i*i<n;i++){
            if(nums[i]==1){
                for(int j=i*i;j<n;j+=i){
                    nums[j]=0;
                }
            }
        }
     for(int i=2;i<n;i++){
        if(nums[i]==1){
            cnt++;
        }
     } 
     return cnt;  
    }
};                                                                                                                                                                                                                                                                                                                        