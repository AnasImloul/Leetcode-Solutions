// Runtime: 175 ms (Top 20.59%) | Memory: 28.4 MB (Top 34.44%)
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        map<int, int> mp;
        int n = intervals.size();

        for(int i = 0; i < n; i++)
            mp[intervals[i][0]] = i;

        vector<int> ans;
        for(auto &i : intervals)
        {
            auto it = mp.lower_bound(i[1]);
            ans.push_back(it == mp.end() ? -1 : it->second);
        }

        return ans;
    }
};