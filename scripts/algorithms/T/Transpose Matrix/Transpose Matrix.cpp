class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        vector<vector<int>>result;
        map<int,vector<int>>m;
        
        for(int i=0;i<matrix.size();i++){
            vector<int>v = matrix[i];
            for(int j=0;j<v.size();j++){
                m[j].push_back(v[j]);
            }
        }
        
        for(auto i:m){
            result.push_back(i.second);
        }
        return result;
    }
};
