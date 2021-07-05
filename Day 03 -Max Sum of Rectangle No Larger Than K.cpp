class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            vector<int> sums(m);
            for(int j=i;j<n;j++){
                for(int p = 0;p<m;p++){sums[p]+=matrix[p][j];}
                
                set<int> s = {0};
                int cur_sum = 0;
                for(int sum : sums){
                    cur_sum+=sum;
                    auto it = s.lower_bound(cur_sum-k);
                    if(it!=s.end())
                        ans = max(ans,cur_sum - *it);
                    s.insert(cur_sum);
                }
            }
        }
     return ans;
    }
};