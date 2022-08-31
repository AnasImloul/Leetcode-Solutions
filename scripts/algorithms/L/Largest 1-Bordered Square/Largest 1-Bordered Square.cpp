// Runtime: 164 ms (Top 8.73%) | Memory: 11.7 MB (Top 72.75%)
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n= grid[0].size();
        vector<vector<int>>left(m,vector<int>(n,0));
        vector<vector<int>>down(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){
            left[i][n-1] = grid[i][n-1];
        }
        for(int i = 0;i<m;i++){
            for(int j = n-2;j>=0;j--){
                //now make the left grid
                if(grid[i][j] == 0){
                    left[i][j] = 0;
                }
                else{
                    left[i][j] += left[i][j+1]+1;
                }
            }
        }
        for(int i = 0;i<n;i++){
            down[m-1][i] = grid[m-1][i];
        }
        for(int i = m-2;i>=0 ;i--){
            for(int j= 0;j<n;j++){
                if(grid[i][j] == 0){
                    down[i][j] = 0;
                }
                else{
                    down[i][j]+= down[i+1][j]+1;
                }
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                cout<<left[i][j] <<' ';
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                cout<<down[i][j] <<' ';
            }
            cout<<endl;
        }
        // now take the minimum of the values of the required
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                // take the minimum of the values of the
                if(grid[i][j] == 1){
                    int ci = i;
                    int cj = j;
                    int w = min(left[i][j],down[i][j]);
                    // now serach in the left and down when no of the 1's become equal
                    for(int k = 0;k<w;k++){
                        // size of the square of the submatrix
                        if(k == 0){
                            ans = max(ans,1);
                        }
                        else{
                            // now make it maximum value of the
                            if(down[ci][cj+k] >= k+1 && left[ci+k][cj] >=k+1){
                                ans = max(ans,(k+1)*(k+1));
                            }
                        }

                    }
                }

            }
        }
        return ans;
    }
};