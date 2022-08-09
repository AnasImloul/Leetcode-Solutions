class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> res;
    
        int I = 0;
        int D = s.size();
        
        for(int i=0;i<s.size()+1;i++)
        {
            if(s[i]=='I')
                res.push_back(I++);
            else
                res.push_back(D--);
        }
        return res;
    }
};
