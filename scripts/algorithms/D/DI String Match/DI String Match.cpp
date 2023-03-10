class Solution {
public:
    vector<int> diStringMatch(string s) {
        int p=0, j=s.size();
        vector<int>v;
        for(int i=0; i<=s.size(); i++)
        {
            if(s[i]=='I')v.push_back(p++);
            else v.push_back(j--);
        }
        return v;
    }
};