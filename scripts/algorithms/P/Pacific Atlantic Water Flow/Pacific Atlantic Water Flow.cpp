// Runtime: 75 ms (Top 50.47%) | Memory: 17.5 MB (Top 77.07%)
class Solution {
public:
    void dfs(vector<vector<int>>& heights,vector<vector<bool>>&v,int i,int j)
    {
        int m=heights.size();
        int n=heights[0].size();
        v[i][j]=true;
        if(i-1>=0&&v[i-1][j]!=true&&heights[i-1][j]>=heights[i][j])
        {
            dfs(heights,v,i-1,j);
        }
         if(i+1<m&&v[i+1][j]!=true&&heights[i+1][j]>=heights[i][j])
        {
            dfs(heights,v,i+1,j);
        }
         if(j-1>=0&&v[i][j-1]!=true&&heights[i][j-1]>=heights[i][j])
        {
            dfs(heights,v,i,j-1);
        }
         if(j+1<n&&v[i][j+1]!=true&&heights[i][j+1]>=heights[i][j])
        {
            dfs(heights,v,i,j+1);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        vector<vector<int>>ans;
        if(m==0)
        {
            return ans;
        }
        int n=heights[0].size();
        if(n==0)
        {
            return ans;
        }
        vector<vector<bool>>pa(m,vector<bool>(n));
        vector<vector<bool>>at(m,vector<bool>(n));
        for(int i=0;i<m;i++)
        {
            dfs(heights,pa,i,0);
            dfs(heights,at,i,n-1);
        }
        for(int j=0;j<n;j++)
        {
             dfs(heights,pa,0,j);
            dfs(heights,at,m-1,j);
        }
        for(int i=0;i<m;i++)
        {
            vector<int>p;
            for(int j=0;j<n;j++)
            {
                if(pa[i][j]&&at[i][j])
                {

                    p.push_back(i);
                    p.push_back(j);
                    ans.push_back(p);
                    p.clear();
                }

            }

        }
        return ans;

    }
};
