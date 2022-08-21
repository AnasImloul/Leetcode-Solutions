// Runtime: 4 ms (Top 33.21%) | Memory: 7.3 MB (Top 37.14%)

class Solution {
public:
    vector<string> ans;
    void solve(string& a,unordered_set<string>& words,int idx,string cstr)
    {
        if(idx>=a.length())
        {
            ans.push_back(cstr);
            return;
        }
        if(cstr.length()!=0)
        {
            cstr+=" ";
        }
        for(int i=idx;i<a.length();++i)
        {
            string str=a.substr(idx,i-idx+1);
            if(words.find(str)!=words.end())
            {
                solve(a,words,i+1,cstr+str);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ans.clear();
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        solve(s,st,0,"");
        return ans;
    }
};