class Solution {
public:
    int checkForConcatenation( unordered_set<string>& st, string w, int i, vector<int>& dp){
        if(i == w.size()) return 1;
        if(dp[i] != -1) return dp[i];
        for(int j = i; j < w.size(); ++j ){
            string t = w.substr(i, j-i+1);
            if(t.size() != w.size() && st.find(t) != st.end()){
                if(checkForConcatenation(st, w, j+1, dp)) return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> st;
        for(auto w: words) st.insert(w);
        for(auto w: words){
            vector<int> dp(w.size(), -1);
            if(checkForConcatenation(st, w, 0, dp)) ans.push_back(w);
        }
        return ans;
    }
};
