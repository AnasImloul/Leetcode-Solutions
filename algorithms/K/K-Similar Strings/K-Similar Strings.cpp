class Solution {
public:
    unordered_map<string,int>m;
    int solve(string &s1,string &s2,int i)
    {
        if(i==s1.length())
            return 0;
        if(m.find(s1)!=m.end())return m[s1];
        if(s1[i]==s2[i])
            return m[s1]=solve(s1,s2,i+1);
        int ans=1e5;
        for(int j=i+1;j<s1.length();j++)
        {
            if(s1[j]==s2[i])
            {
                swap(s1[j],s1[i]);
                ans=min(ans,1+solve(s1,s2,i+1));
                swap(s1[j],s1[i]);
            }
        }
        return m[s1]=ans;
    }
    int kSimilarity(string s1, string s2) {
        return solve(s1,s2,0);
    }
};