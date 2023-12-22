// Runtime: 2 ms (Top 44.3%) | Memory: 6.40 MB (Top 48.64%)

class Solution {
public:
    int maximum69Number (int num) {
        
        string s = to_string(num);
        
        /* You can change at the most one digit,
           so traverse from left and change the first
           encountered 6  to  9  (to increase th value of num) */
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == '6')
            {
                s[i] = '9';
                break;
            }
        }
        
        return stoi(s);
    }
};
