class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        int res = -1;
        for(int i : arr) mp[i]++;
        for(int i : arr) {
            if(mp[i] == i) res = max(res, i);
        }
        return res;
    }
};
