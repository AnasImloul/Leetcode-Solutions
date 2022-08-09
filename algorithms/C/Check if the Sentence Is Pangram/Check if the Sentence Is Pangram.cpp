class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> v(26,0);
        for(auto x:sentence)
        {
            v[x-'a'] = 1;
        }
        return accumulate(begin(v),end(v),0) == 26;
    }
};
