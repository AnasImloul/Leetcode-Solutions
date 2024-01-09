// Runtime: 7 ms (Top 98.69%) | Memory: 14.10 MB (Top 36.43%)

class Solution {
public:
    vector<int> answerQueries(vector<int>& v, vector<int>& q) {
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++)v[i]+=v[i-1];
        vector<int> ans;
        for(int x:q){
            int idx=upper_bound(v.begin(),v.end(),x)-v.begin();
            ans.push_back(idx);
        }
        return ans;
    }
};
