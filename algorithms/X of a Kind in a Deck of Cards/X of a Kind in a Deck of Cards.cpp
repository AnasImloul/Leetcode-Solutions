class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mp;
        for(auto it: deck){
            mp[it]++;
        }
        int fin=0;
        for(auto it: mp){
            fin=__gcd(fin,it.second);
        }
        return fin>=2;
    }
};
