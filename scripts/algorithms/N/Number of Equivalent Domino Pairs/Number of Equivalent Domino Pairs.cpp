// Runtime: 95 ms (Top 39.89%) | Memory: 22 MB (Top 89.42%)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes)
    {
        map<pair<int,int>,int> m;
        int ans=0;
        for(auto &d:dominoes)
        {
            int a=min(d[0],d[1]),b=max(d[0],d[1]);
            m[{a,b}]++;
        }
        for(auto &p:m)
        {
            int n=p.second;
            ans+=((n-1)*n)/2;
        }
        return ans;

    }
};
//if you like the solution plz upvote.