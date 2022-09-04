// Runtime: 15 ms (Top 52.29%) | Memory: 11.9 MB (Top 92.97%)
class Solution {
public:
    //iterate over each words[i] and take the sub-string str from s of size equals to words[i].
    //and compare str with words[i] if both are equal increase count by 1.
    int countPrefixes(vector<string>& words, string s)
    {
        int count=0;
        for(auto it: words)
        {
            string str = s.substr(0, it.size());
            if(str == it) count++;
        }
        return count;
    }
};