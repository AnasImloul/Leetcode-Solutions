class Solution {
public:
    
    bool isVowel(char s)
    {
        if(s == 'a' or s == 'e' or s == 'i' or s == 'o' or s == 'u'
           or s == 'A' or s == 'E' or s == 'I' or s == 'O' or s == 'U') return true;
        return false;
    }
    
    string reverseVowels(string s) {
        if(s.size() == 0) return "";
        int left = 0, right = s.size() - 1;
        
        while(left < right)
        {
            if(isVowel(s[left]) and isVowel(s[right]))
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            else if(isVowel(s[left])) right--;
            else if(isVowel(s[right])) left++;
            else {
                left++;
                right--;
            }
        }
        
        
        return s;
    }
};
