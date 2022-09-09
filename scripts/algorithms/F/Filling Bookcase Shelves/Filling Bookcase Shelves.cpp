// Runtime: 84 ms (Top 5.26%) | Memory: 19.4 MB (Top 6.60%)
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<vector<int>> cost(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++)
        {
            int height=books[i-1][1];
            int width=books[i-1][0];
            cost[i][i]=height;
            for(int j=i+1;j<=n;j++)
            {
                height=max(height,books[j-1][1]);
                width+=books[j-1][0];
                if(width<=shelfWidth) cost[i][j]=height;
                else cost[i][j]=-1;
            }
        }
        vector<int> ans(n+1);
        ans[0]=0;
        for(int i=1;i<=n;i++)
        {
            ans[i]=INT_MAX;
            for(int j=1;j<=i;j++)
            {
                if(cost[j][i]==-1) continue;
                if(ans[j-1]!=INT_MAX) ans[i]=min(ans[i],ans[j-1]+cost[j][i]);
            }
        }
        return ans[n];
    }
};