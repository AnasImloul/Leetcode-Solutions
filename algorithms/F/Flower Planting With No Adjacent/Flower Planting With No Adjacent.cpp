class Solution {
public:
    int check(vector<int> a[],vector<int> &col,int sv,int i)
    {
        for(auto it:a[sv])
        {
            if(col[it]==i)return 0;
        }
        return 1;
    }
    
    void dfs(vector<int> a[],vector<int> &col,int sv,int lc)
    {
        for(int i = 1;i<5;i++)
        {
            if(check(a,col,sv,i))
            {
                col[sv] = i;
                break;
            }
        }
        for(auto it:a[sv])
        {
            if(col[it]==-1)
            {
                dfs(a,col,it,col[sv]);
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> a[n];
        for(auto it:paths)
        {
            a[it[0]-1].push_back(it[1]-1);
            a[it[1]-1].push_back(it[0]-1);
        }
        
        vector<int> col(n,-1);
        for(int i = 0;i<n;i++)
        {
            if(col[i]==-1)
            {
                dfs(a,col,i,-7);
            }
        }
        return col;
    }
};
