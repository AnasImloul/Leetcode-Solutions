class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans{first};
        for(int x: encoded)
            ans.push_back(first^=x);
        return ans;
    }
};
