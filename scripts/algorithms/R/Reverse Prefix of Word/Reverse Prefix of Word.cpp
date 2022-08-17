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
