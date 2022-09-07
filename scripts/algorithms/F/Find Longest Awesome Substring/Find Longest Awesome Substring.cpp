// Runtime: 403 ms (Top 40.21%) | Memory: 10.8 MB (Top 68.53%)
class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int,int> map;
        int mask = 0, maxL = 0;
        map[mask] = -1;

        for(int i=0; i<s.size(); ++i){
            int ch = s[i]-'0';
            mask^= (1<<ch);

            if(map.find(mask) != map.end()){
                maxL = max(maxL, i-map[mask]);
            }

            for(int x=0; x<=9; ++x){
                int newMask = mask^(1<<x);
                if(map.find(newMask) != map.end()){
                    maxL = max(maxL, i-map[newMask]);
                }
            }

            if(map.find(mask) == map.end()){
                map[mask] = i;
            }
        }
        return maxL;
    }
};