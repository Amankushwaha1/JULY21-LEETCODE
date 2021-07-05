class Solution {
public:
    unordered_map<int,vector<int>> m;
    long mod = 1e9+7;
           
    
    
    int recursive(int n,int i,char prev,vector<vector<long long>>& dp){
        if(i>n)return 0;
        
        if(i==n){
            switch(prev){
                    case 'a':return 1;
                    case 'e':return 2;
                    case 'i':return 4;
                    case 'o':return 2;
                    case 'u':return 1;
                    case 'c':return 5;
            }
        }
        
        int index = prev - 'a';
        if(dp[i][index]!=-1)
            return dp[i][index];
        
       long long count=0;
       for(auto next : m[prev])
           count+=(recursive(n,i+1,next,dp))%mod;
        
        return dp[i][index]=count%mod;
    }
    
    int countVowelPermutation(int n) {
            m['c'] = {'a','e','i','o','u'};
            m['a'] = {'e'};
            m['e'] = {'a','i'};
            m['i'] = {'a','e','o','u'};
            m['o'] = {'i','u'};
            m['u'] = {'a'};
        
        vector<vector<long long>> dp(n+2,vector<long long> (27,-1));
        int count = 0;
        
        count=recursive(n,1,'c',dp);
        return count;
    }
};