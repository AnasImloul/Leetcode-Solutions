// Runtime: 20 ms (Top 8.82%) | Memory: 10.3 MB (Top 50.82%)
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