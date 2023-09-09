// Runtime: 11 ms (Top 71.1%) | Memory: 13.70 MB (Top 5.9%)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int>ump;
        unordered_map<int,int>mp;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    ump[i]=1;
                    mp[j]=1;
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(ump[i] || mp[j]){
                    matrix[i][j]=0;
                }
            }
        }


        
        
    }
};