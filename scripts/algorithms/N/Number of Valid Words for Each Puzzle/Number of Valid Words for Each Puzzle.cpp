// Runtime: 392 ms (Top 85.55%) | Memory: 69 MB (Top 97.11%)
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> maskCnt;
        for(const auto& w: words) ++maskCnt[bitmask(w)];
        vector<int> ans(puzzles.size(), 0);
        for(int i = 0; i < puzzles.size(); i++){
            int mask, subMask = mask = bitmask(puzzles[i]), first = bitmask(puzzles[i].substr(0,1));
            do{
                if( (first & subMask) == first && maskCnt.count(subMask)) ans[i] += maskCnt[subMask]; //ok
            }while(subMask = (subMask - 1) & mask);
        }
        return ans;
    }

private:
    int bitmask(const string& word, int mask = 0){
        for(auto c: word) mask |= (1 << (c - 'a'));
        return mask;
    }
};