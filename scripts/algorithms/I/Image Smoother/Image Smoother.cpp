// Runtime: 143 ms (Top 11.55%) | Memory: 21.8 MB (Top 55.12%)
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row[]={0,0,0,-1,1,-1,1,-1,1};
        int col[]={0,-1,1,0,0,1,-1,-1,1};
        int m=img.size(),n=img[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int sum=0,count=0;
                for(int k=0;k<9;k++)
                {
                    if(0<=i+row[k] && i+row[k]<m && 0<=j+col[k] && j+col[k]<n)
                    {
                        sum+=img[i+row[k]][j+col[k]];
                        count++;
                    }
                }
                ans[i][j]=sum/count;
            }
        }
        return ans;
    }
};