// Runtime: 15 ms (Top 33.9%) | Memory: 12.42 MB (Top 38.6%)

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i = 1;i<words.size();i++){
            string x = words[i];
            sort(x.begin(),x.end());
            string y = words[i-1];
            sort(y.begin(),y.end());
            if(x == y){
                words.erase(words.begin() + i);
                i--;
            }
        }
        return words;
    }
};