class Solution {
public:
    bool areAnagram(string str1, string str2)
    {
        sort(str1.begin(), str1.end());
        for (int i=0;i<str1.size();i++)
        {
            if (str1[i]!=str2[i])
            {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<string> v;
        vector<int> ans;
        string k="";
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<i+p.size() && j<s.size();j++)
            {
                k+=s[j];
            }
            if(k.size()==p.size())
            {
                v.push_back(k);   
            }
            k="";
        }
        sort(p.begin(),p.end());
        for(int i=0;i<v.size();i++)
        {
            if(areAnagram(v[i],p))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
