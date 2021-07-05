class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int> v;
        vector<int>::iterator it;
        it = lower_bound(arr.begin(),arr.end(),x);
        int p=it-arr.begin();
        
        if(p==n)p--;
        else if(arr[p]>x && p>0 && (arr[p]-x>=x-arr[p-1]))p--;
        else p=p;
        
        int l=p-1,r=p+1;
        
        v.push_back(arr[p]);
        
        for(int i=0;i<k-1;i++){
            if(l<0){v.push_back(arr[r]);r++;}
            else if(r>n-1){v.push_back(arr[l]);l--;}
            else if(x-arr[l]<=arr[r]-x){v.push_back(arr[l]);l--;}
            else {v.push_back(arr[r]);r++;}
        }
        
        sort(v.begin(),v.end());
        return v;
    }
};