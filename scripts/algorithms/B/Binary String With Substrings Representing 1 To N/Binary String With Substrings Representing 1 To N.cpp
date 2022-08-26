// Runtime: 5 ms (Top 42.03%) | Memory: 6.5 MB (Top 32.61%)
class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<int> seen;
        int len = s.length();
        for(int i=len-1;i>=0;i--){
            int num = 0;
            for(int j=1;j<=min(len-i,31);j++){ //max 31 bit is enough to form positive integer
                num = num*2 + (s[i+j-1] == '1' ? 1 : 0);
                if(0 < num && num <= n) seen.insert(num);
            }
            if(seen.size() == n) return true;
        }
        return false;
    }
};