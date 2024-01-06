// Runtime: 191 ms (Top 62.9%) | Memory: 44.30 MB (Top 70.14%)

class Solution {
public:
    unordered_set<string>st;
    int ans=0;
    void dfs(string &s, int idx)
    {
        if(st.size()>ans) ans=st.size();
        if(idx>=s.length()) return;
        string str="";
        for(int i=idx ; i<s.length() ; i++)
        {
            str += s[i];
            if(st.find(str)==st.end())
            {
                st.insert(str);
                dfs(s,i+1);
                st.erase(str);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        dfs(s,0);
        return ans;
    }
};
