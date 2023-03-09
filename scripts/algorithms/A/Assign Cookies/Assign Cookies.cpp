class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        if(n==0 or m==0)return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        while(i<m and j<n)
        {
            if(s[i]>=g[j])
                j++;
            i++;
        }
        return j;
    }
};