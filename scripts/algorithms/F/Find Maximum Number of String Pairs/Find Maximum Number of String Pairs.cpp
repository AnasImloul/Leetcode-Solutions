// Runtime: 4 ms (Top 88.61%) | Memory: 21.50 MB (Top 48.26%)

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string>mp;
        int res=0;
        for(auto it:words){
            string s=it;
            reverse(it.begin(),it.end());
            if(mp.find(it)==mp.end()){
                mp.insert(s);
            }
            else res++;
           
        }
        return res;
    }
};
