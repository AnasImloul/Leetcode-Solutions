class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int res = 0;
        
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u'};
        
        for (int i = 0; i < n; i++)
        {
            unordered_set<char> letters;
            // string temp = "";
            for (int j = i; j < n; j++)
            {
                // temp += word[j];
                letters.insert(word[j]);
                if (letters == vowels)
                res++;
            }
        }
        
        return res;
    }
}; 
