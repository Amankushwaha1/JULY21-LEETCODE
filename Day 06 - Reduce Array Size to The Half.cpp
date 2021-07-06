class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int,int> m;
        for(auto i:arr)m[i]++;
        
        vector<int> v;
        for(auto i:m)v.push_back(i.second);
        sort(v.rbegin(),v.rend());
        
        int k = ceil(n*0.5);
        int i=0;
        while(k>0){
            k=k-v[i];
            i++;
        }
        return i;
    }
};