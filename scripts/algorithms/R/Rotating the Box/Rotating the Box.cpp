class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        vector<vector<char>> ans(n,vector<char>(m,'.'));
        
        for(int i=0;i<m;++i){
            int k = n; //Stores last obstacle or occupied position
            for(int j=n-1;j>=0;--j)
            {
                if(box[i][j] == '#')
                {
                    ans[--k][i] = '#';
                }
                else if(box[i][j] == '*')
                {
                     k = j;
                     ans[j][i] = '*';
                }   
            }
        }
        for(int i=0;i<n;++i){
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
