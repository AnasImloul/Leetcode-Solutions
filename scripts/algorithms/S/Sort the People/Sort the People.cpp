// Runtime: 30 ms (Top 74.41%) | Memory: 23.80 MB (Top 39.22%)

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
		// {height, name}
        vector<pair<int, string>> v;
		// by putting height at first, we can skip writing a comparator as it'll sort by first element of the pair
        for (int i = 0; i < names.size(); i++) v.push_back({heights[i], names[i]});
		// sort in decreasing order
        sort(v.rbegin(), v.rend());
		// build the final ans. x.second is the name.
        for (auto & x : v) ans.push_back(x.second);
        return ans;
    }
};
