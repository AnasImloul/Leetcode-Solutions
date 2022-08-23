// Runtime: 88 ms (Top 64.62%) | Memory: 16.6 MB (Top 74.51%)
class Solution {
public:
    int minSteps(string s, string t) {
        int count = 0, length = s.length();
        vector<int> vec1(26, 0), vec2(26, 0);
        for(int i = 0; i < length; ++i){
            vec1[s[i] - 'a']++;
            vec2[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; ++i){
            if(vec1[i] > vec2[i])
                count += vec1[i] - vec2[i];
        }
        return count;
    }
};