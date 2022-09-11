// Runtime: 320 ms (Top 18.36%) | Memory: 24.5 MB (Top 25.16%)
#define vv vector<int>

class Solution {
public:

    int dx[4]={0 , 0, 1 , -1};
    int dy[4]={1 , -1 , 0 , 0};

    int minCost(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        priority_queue< vv , vector<vv> , greater<vv>> pq;

        vector<vector<int>> dp(m+3 , vector<int>(n+3 , INT_MAX));

        dp[0][0]=0;
        pq.push({0 , 0 , 0});

        // there is no need of visited

        // distance or u can say cost relaxation

        while(!pq.empty())
        {

            auto v=pq.top();
            pq.pop();

            int cost=v[0];
            int i=v[1];
            int j=v[2];

            if(i==m-1 && j==n-1)
            {
                return cost;
            }

            for(int k=0;k<4;k++)
            {
                int newi=i+dx[k];
                int newj=j+dy[k];

                if(newi>=0 && newj>=0 && newi<m && newj<n)
                {
                    if((k+1)==grid[i][j])
                    {
                        if(dp[newi][newj]>cost)
                        {
                            dp[newi][newj]=cost;
                            pq.push({cost , newi , newj});
                        }
                    }
                    else
                    {
                        if(dp[newi][newj]>cost+1)
                        {
                            dp[newi][newj]=cost+1;
                            pq.push({cost+1 , newi , newj});
                        }
                    }
                }
            }

        }

        if(dp[m-1][n-1]!=INT_MAX)
        {
            return dp[m-1][n-1];
        }

        return -1;

    }
};