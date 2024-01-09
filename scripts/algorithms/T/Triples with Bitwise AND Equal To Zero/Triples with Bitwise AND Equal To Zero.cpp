// Runtime: 267 ms (Top 65.96%) | Memory: 13.40 MB (Top 32.62%)

class Solution {
public:
    int countTriplets(vector<int>& a) {
        int  n = a.size();
        unordered_map<int,int> mp;
        for(int  i= 0;i<n;i++)
        {
            for(int  j= 0;j<n;j++)
            {
               mp[(a[i] & a[j])]++;
            }
        }
        int ans  = 0;
        for(auto &op : mp)
        {
            for(int  i = 0;i<n;i++)
            {
                if(op.first & a[i])
                {}
                else
                {ans+=op.second;}
            }
        }
        return ans;
    }
};
