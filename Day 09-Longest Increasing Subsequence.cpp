class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && (nums[j]&nums[i])*2<(nums[j]|nums[i]))
                    dp[i]=max(dp[j]+1,dp[i]);
            }
        }
        int ans =INT_MIN;
        for(auto i:dp)ans = max(ans,i);
       
        
        return ans;
    }
};
