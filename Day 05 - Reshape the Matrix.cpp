class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        if((m*n)!=(r*c) || (m==r && n==c))
            return mat;
        
        vector<vector<int>> remat(r,vector<int>(c));
        
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
             remat[i][j]=mat[count/n][count%n];
                count++;
            }
        }
        
        return remat;
    }
};