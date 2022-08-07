class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        generate(ans,"",n,n);
        
        return ans;
    }
    
    void generate(vector<string> &ans,string s,int open,int close)
    {
        if(open == 0 && close == 0)
        {
            ans.push_back(s);
            return ;
        }
        
        if(open > 0)
        {
            generate(ans,s+'(',open-1,close);
        }
        
        if(open < close)
        {
            generate(ans,s+')',open,close-1);
        }
    }
};
