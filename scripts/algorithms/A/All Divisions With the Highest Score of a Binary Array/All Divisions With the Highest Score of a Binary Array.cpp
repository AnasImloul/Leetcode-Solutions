// Runtime: 262 ms (Top 85.58%) | Memory: 286.70 MB (Top 87.39%)

class Solution {
public:

    vector<int> maxScoreIndices(vector<int> &a) {
        int n=a.size();
        
        int one=accumulate(a.begin(),a.end(),0), zero=0;
        
        int maxs=0;
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int s=one+zero;
            if(s>maxs){
                maxs=s;
                ans={i};
            }else if(s==maxs){
                ans.push_back(i);
            }
            if(i<n){
                one -= (a[i]==1);
                zero += (a[i]==0);
            }
        }
        return ans;
    }
};
