// Runtime: 41 ms (Top 5.11%) | Memory: 11.3 MB (Top 10.91%)
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
     int n = mat.size() ;
     int ans = 0 ;

     for(int i = 0 ; i < n ; i++){
        ans = ans + mat[i][i] + mat[i][n - i - 1] ;
      }
      ans = (n & 1) ? ans - mat[n/2][n/2] : ans ;//if n is odd then we have to subtract mat[n/2][n/2] from the ans because we add it twice earlier.
      return ans ;
    }
};