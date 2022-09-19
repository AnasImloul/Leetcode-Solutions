// Runtime: 0 ms (Top 100.00%) | Memory: 6.1 MB (Top 72.47%)
class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans = "";
        int tr = true;
        for(auto w : word){
            ans.push_back(w);
            if(tr && w == ch){
                tr=false;
                reverse(ans.begin(), ans.end());
            }
        }
        return ans;
    }
};