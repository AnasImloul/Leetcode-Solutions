// Runtime: 2780 ms (Top 5.12%) | Memory: 20.00 MB (Top 7.4%)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), start = matrix[0][0], end = matrix[n-1][n-1];
        unordered_map<int, int>mp;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mp[matrix[i][j]]++;
        
        for(int i = start; i <= end; i++)
            if(mp.find(i) != mp.end()){
                for(int j = 0; j < mp[i]; j++){
                    k--;
                    if(k == 0) return i;
                }
            }
          return -1;  
    }
};
