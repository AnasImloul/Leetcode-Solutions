// Runtime: 0 ms (Top 100.0%) | Memory: 6.19 MB (Top 57.6%)

class Solution {
public:
    int addMinimum(string word) {
        
        int n = word.size(), i = 0, res = 0;
        
        while(i < n) {
            int count = 0;
            
            if(word[i] == 'a') {
                count++;i++;
            }
             
            if(i < n and word[i] == 'b') {
                count++;i++;
            }
            
            if(i < n and word[i] == 'c') {
                count++;i++;
            }
            
            res += 3 - count;
        }
        
        return res;
    }
};