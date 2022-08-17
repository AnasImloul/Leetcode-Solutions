class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> res;
        int ct = 1;
        int n = s.size();
        for(int i =0; i< n - 1 ; ++i){
            if(s[i] == s[i + 1]) ct++;
            else{
                res.push_back(ct);
                ct = 1;
            }
        }
        res.push_back(ct);
        
        int ans = 0;
        n = res.size();
        for(int i =0; i< n - 1; ++i){
            ans += min(res[i], res[i + 1]);
        }
        return ans;
    }
};
