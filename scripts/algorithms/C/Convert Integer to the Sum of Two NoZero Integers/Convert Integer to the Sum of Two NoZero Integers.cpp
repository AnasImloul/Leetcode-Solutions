// Runtime: 0 ms (Top 100.0%) | Memory: 6.90 MB (Top 12.45%)

class Solution {
public:
    
    bool isok(string a) {
        for(char ch : a) {
            if(ch == '0') return false;
        }
        return true;
    }
    
    vector<int> getNoZeroIntegers(int n) {
        int i = 1, j = n-1;
        while(i <= j) {
                if(i + j == n) {
                    string test1 = to_string(i);
                    string test2 = to_string(j);
                    if(isok(test1) and isok(test2)) return {i, j};
                }
            i++;
            j--;
        }
        return {};
    }
};
