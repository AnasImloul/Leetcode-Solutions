// Runtime: 0 ms (Top 100.0%) | Memory: 11.70 MB (Top 85.79%)

class Solution {
    private:
    void solve(int cnt1,int cnt2,int n,vector<string> &ans,string &op,int ind)
    {
        if(ind>=n*2)
        {
            ans.push_back(op);
            return;}
        if(cnt1<n and ind<n*2-1)
        {
            op+='(';
            solve(cnt1+1,cnt2,n,ans,op,ind+1);
            op.pop_back();
        }
        
        if(cnt2<cnt1 and ind>0)
        {
            op+=')';
 
            solve(cnt1,cnt2+1,n,ans,op,ind+1);
            op.pop_back();
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
         string op="";
        vector<string> ans;
        solve(0,0,n,ans,op,0);
        return ans;
    }
};




