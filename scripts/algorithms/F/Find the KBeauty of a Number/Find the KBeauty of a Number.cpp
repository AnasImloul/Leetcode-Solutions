// Runtime: 2 ms (Top 43.1%) | Memory: 6.12 MB (Top 9.5%)

class Solution {
public:
    bool isBeauty(string s1, string s2){
        int n1 = stoi(s1);
        int n2 = stoi(s2);
        if(n2) return !(n1 % n2);
        return false;
    }
    
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.size();
        if(!n) return 0;
        int i = 0, j = 0, beautyCount = 0;
        // At any given moment, for any particular values of i and j, (j - i + 1) gives us the window size
        
        while(j < n){
            // Calculation
            string window = s.substr(i, j - i + 1);
            
            // Window size not reached yet
            if(j - i + 1 < k){
                j++;
            }
            
			// Window size reached
            else if(j - i + 1 == k){
                // Find the answer
                if(isBeauty(s, window)) beautyCount++;
                
                // Slide the window
                i++;
                j++;
            }
        }
        return beautyCount;
    }
};