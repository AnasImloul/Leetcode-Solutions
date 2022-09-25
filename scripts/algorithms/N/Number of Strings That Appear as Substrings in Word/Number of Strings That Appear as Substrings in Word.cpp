// Runtime: 5 ms (Top 84.96%) | Memory: 8.8 MB (Top 65.84%)
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(int i=0;i<patterns.size();i++)
        {
            if(word.find(patterns[i])!=string::npos)
                count++;
        }
        return count;
    }
};