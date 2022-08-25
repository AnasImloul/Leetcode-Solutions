// Runtime: 6 ms (Top 63.59%) | Memory: 7 MB (Top 71.84%)
class Solution {
public:
    int minOperations(string s) {
        int start0 = 0, start1 = 0;
        for(int i = 0; i<s.size(); i+=2){
            if(s[i]!='0') start0++;
        }
        for(int i = 1; i<s.size(); i+=2){
            if(s[i]!='1') start0++;
        }

        for(int i = 0; i<s.size(); i+=2){
            if(s[i]!='1') start1++;
        }
        for(int i = 1; i<s.size(); i+=2){
            if(s[i]!='0') start1++;
        }

        return min(start0, start1);
    }
};