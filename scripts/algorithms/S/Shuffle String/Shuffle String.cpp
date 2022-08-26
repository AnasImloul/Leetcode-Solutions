// Runtime: 15 ms (Top 49.52%) | Memory: 15.2 MB (Top 43.21%)
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {

        string ans = s;

        for(int i=0 ; i<s.size() ; i++){
            ans[indices[i]] = s[i];
        }

        return ans;
    }
};