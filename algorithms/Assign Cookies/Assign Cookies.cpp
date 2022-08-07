class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        int g_idx = 0;
        int s_idx = 0;
        sort(s.begin(),s.end(),greater<int>());
        sort(g.begin(),g.end(),greater<int>());
        
        while(g_idx<g.size()&&s_idx<s.size())
        {
            if(s[s_idx]>=g[g_idx])
            {
                res++;
                g_idx++;
                s_idx++;
            }
            else
            {
                g_idx++;
            }
        }
        return res;
        
    }
};
