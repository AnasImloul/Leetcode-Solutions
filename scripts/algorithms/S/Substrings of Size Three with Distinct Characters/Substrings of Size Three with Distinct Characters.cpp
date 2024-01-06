// Runtime: 0 ms (Top 100.0%) | Memory: 6.90 MB (Top 23.54%)

class Solution {
public:
    int countGoodSubstrings(string s) {
        int cnt=0,n=s.size();
        unordered_map<char,int> map;
        for(int i=0;i<n;i++){
            if(i>2 and --map[s[i-3]] == 0) map.erase(s[i-3]);
            map[s[i]]++;
            if(map.size() == 3) cnt++;
        }
        return cnt;
    }
};
