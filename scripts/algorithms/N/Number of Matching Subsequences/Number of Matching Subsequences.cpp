class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
       int ct=0;
        unordered_map<string,int>m;
        
        for(int i=0;i<words.size();i++)
        {
             m[words[i]]++;
        }
        
        
        for(auto it=m.begin();it!=m.end();it++)
        {
            string k=it->first;
            
            int z=0;
            
            for(int i=0;i<s.length();i++)
            {
                if(s[i]==k[z])
                    z++;
                else if(z==k.length())
                    break;
            }
            if(z==k.length())
                ct=ct+it->second;
            
        }        
    return ct;
    }
};
