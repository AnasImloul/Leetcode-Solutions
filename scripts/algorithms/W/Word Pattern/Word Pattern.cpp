// Runtime: 0 ms (Top 100.00%) | Memory: 6.5 MB (Top 54.74%)

class Solution {
public:

    unordered_set<string> processed_words;
    string m[26]; // char to string mapping

    bool crunch_next_word(char c, string word)
    {
        int idx = c-'a';
        if(m[idx].empty() && processed_words.count(word)==0)
        {
            m[idx] = word;
            processed_words.insert(word);
            return true;
        }
        else if(m[idx]==word) return true;
        else return false;
    }

    bool wordPattern(string pattern, string s)
    {
        int count = 0;

        int start = 0;
        int end = s.find(' ');
        while (end != -1)
        {
            string word = s.substr(start, end - start);
            char c = pattern[count];
            if(!crunch_next_word(c,word)) return false;

            start = end + 1;
            end = s.find(' ', start);
            count++;
            if(count == pattern.length()) return false;
        }
        if(count != pattern.length()-1) return false;
        string word = s.substr(start, end - start);
        char c = pattern[count];
        if(!crunch_next_word(c,word)) return false;
        return true;
    }
};