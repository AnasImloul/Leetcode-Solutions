#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        int i=0, j=col-1;
        
        while(i>=0 && i<row && j>=0 && j<col) {
            
            // finding nums in all 4 directions
            int up = i-1<0 ? -1 : mat[i-1][j];
            int down = i+1>=row ? -1 : mat[i+1][j];
            int left = j-1<0 ? -1 : mat[i][j-1];
            int right = j+1>=col ? -1 : mat[i][j+1];
            
            // check if current is peak
            if(mat[i][j] > up && mat[i][j] > left && mat[i][j] > right && mat[i][j] > down)
                return {i, j};
            
            // get maxm among 4 direction
            int maxm=max({up, down, left, right});
            
            // move in max direction
            if(up == maxm) i--;
            else if(down == maxm) i++;
            else if(left == maxm) j--;
            else if(right == maxm) j++;
        }
        return {-1, -1};
    }
};
