class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        
        vector<int> vec;
        int mx=0, ans=0;
        for(auto itr: seq)
        {
            if(itr=='(')
                ans++;
            mx = max(mx, ans);
            vec.push_back(ans);
            if(itr==')')
                ans--;
        }
        
        mx = mx/2;
        for(int i=0; i<seq.size(); i++)
        {
            if(vec[i]<=mx)
                vec[i]=0;
            else
                vec[i]=1;
        }
        
        return vec;
        
    }
};
