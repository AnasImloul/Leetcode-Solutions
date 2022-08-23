// Runtime: 58 ms (Top 13.90%) | Memory: 21.4 MB (Top 22.99%)
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n= fronts.size();
        map<int,int>mp;
        set<int>s;
        for(int i=0;i<n;i++){
            if(fronts[i] == backs[i]){
                mp[fronts[i]]++;
            }
            s.insert(fronts[i]);
            s.insert(backs[i]);
        }
        for(auto i:s){
            if(mp[i] >= 1) continue;
            return i;
        }
        return 0;

    }
};