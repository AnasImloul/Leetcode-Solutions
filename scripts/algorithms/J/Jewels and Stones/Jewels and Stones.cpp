// Runtime: 0 ms (Top 100.0%) | Memory: 6.60 MB (Top 45.88%)

class Solution {
public:
    map<char,int> umap;
    int numJewelsInStones(string J, string S) {
        for(char c:S){
            umap[c]++;
        }
        int count=0;
        for(char c:J){
            if(umap.count(c)){
                count+=umap[c];
            }
        }
        return count;
    }
};
