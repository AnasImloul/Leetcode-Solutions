class Solution {
public:
    string toLowerCase(string s) {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
                s[i]+=32;
        }
        return s;
    }
};