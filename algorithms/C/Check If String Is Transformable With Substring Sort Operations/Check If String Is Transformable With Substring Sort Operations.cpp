class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<vector<int>> inx(10);
        for(int i = 0; i < s.length(); i++) 
            inx[s[i]-'0'].push_back(i);
        
        vector<int> cnt(10, 0);
        for(int i = 0; i < t.length(); i++) {
            int d = t[i] - '0';
            // check anagram
            if(cnt[d] >= inx[d].size())
                return false;
            for(int k = 0; k < d; k++) {
                if(cnt[k] < inx[k].size() && inx[k][cnt[k]] < inx[d][cnt[d]])
                    return false;
            }
            cnt[d] += 1;
        }
        
        return true;
    }
};

// 1 1 9 1 9  
// 1 9 1 1 9
