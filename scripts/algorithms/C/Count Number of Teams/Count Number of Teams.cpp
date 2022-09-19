// Runtime: 128 ms (Top 82.18%) | Memory: 9.5 MB (Top 29.42%)
class Solution {
public:
    int numTeams(vector<int>& rating) {

        int i, j, n = rating.size(), ans = 0;
        vector<int> grt(n, 0), les(n, 0);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(rating[j] > rating[i])
                    grt[i] += 1;
                else
                    les[i] += 1;
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(rating[j] > rating[i])
                    ans += grt[j];
                else
                    ans += les[j];
            }
        }
        return ans;
    }
};