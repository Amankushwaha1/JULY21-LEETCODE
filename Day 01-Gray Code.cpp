class Solution {
public:
    
    int convert(string bins){
        int ans = 0;
        int n = bins.length();
        for(int i=0;i<n;i++){
           if(bins[n-1-i]=='1')
           ans+=pow(2,i); 
        }
        return ans;
    }
    vector<int> grayCode(int n) {
        vector<int> v ;
        for (int i = 0; i < (1 << n); i++)
        {
        int val = (i ^ (i >> 1));
        
        bitset<32> r(val);
         
        string s = r.to_string();
        string bins = s.substr(32 - n);
        int p = convert(bins);
         v.push_back(p);
     }
        return v;
    }
};