// Runtime: 69 ms (Top 79.43%) | Memory: 28.20 MB (Top 71.43%)

class Solution {
public:
    static bool comp(pair<int,int> &x,pair<int,int> &y)
    {
        if (x.second != y.second) 
        return x.second > y.second;
 
    return x.first > y.first;
};
    vector<int> filterRestaurants(vector<vector<int>>& r, int vf, int mx, int md) {
        vector<int> ans;
        vector<pair<int,int>> v;
        for(int i=0;i<r.size();i++)
        {
            if(vf==1)
            {
             if(r[i][2]==vf && r[i][3]<=mx && r[i][4]<=md)
                v.push_back(make_pair(r[i][0],r[i][1]));
            }
            else
            {
                if(r[i][3]<=mx && r[i][4]<=md)
                v.push_back(make_pair(r[i][0],r[i][1]));
            }
            
        }
        sort(v.begin(),v.end(),comp);
        for(auto itr:v)
         ans.push_back(itr.first);
        return ans;
    }
};
