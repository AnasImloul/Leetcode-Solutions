// Runtime: 56 ms (Top 34.77%) | Memory: 26 MB (Top 35.19%)
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans{first};
        for(int x: encoded)
            ans.push_back(first^=x);
        return ans;
    }
};