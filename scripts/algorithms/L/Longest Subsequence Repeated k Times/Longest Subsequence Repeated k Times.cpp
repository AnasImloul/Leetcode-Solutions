class Solution {
public:
    int Alpha=26;
    bool find(string &s,string &p,int k)
    {
        int j=0;
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==p[j])
            {
                j++;
                if(j==p.size())
                {
                    count++;
                    j=0;
                }
                if(count==k)
                {
                    return true;
                }
            }
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) 
    {
        queue<string>q;
        q.push("");
        string ans="";
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            for(int i=0;i<Alpha;i++)
            {
                string curr=temp+char('a'+i);
                if(find(s,curr,k))
                {
                    ans=curr;
                    q.push(curr);
                }
            }
        }
        return ans;
    }
};