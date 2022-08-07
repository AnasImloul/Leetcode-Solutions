class Solution {
public:
    bool check(string k)
    {
        string l=k;
        reverse(l.begin(),l.end());
        if(k==l)return true;
        return false;
    }
    void solve(string &s,vector<vector<string>>&ans,
               vector<string>temp,int pos)
    {
        if(pos>=s.size()){ans.push_back(temp); return;}
        string m;
        for(int i=pos;i<s.size();i++)
        {
            m+=s[i];
            if(check(m))
            {temp.push_back(m);
            solve(s,ans,temp,i+1);
            temp.pop_back();}
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(s,ans,temp,0);
        return ans;
    }
};
