// Runtime: 15 ms (Top 22.24%) | Memory: 6.7 MB (Top 73.98%)
class Solution {
public:

    string greatestLetter(string s)
    {
        vector<int> low(26), upp(26); //storing occurences of lower and upper case letters
        string res = "";

        for(auto it : s) //iterate over each char and mark it in respective vector
        {
            if(it-'A'>=0 && it-'A'<26)
                upp[it-'A']++;
            else
                low[it-'a']++;
        }

        for(int i=25; i>=0; i--) //start from greater char
        {
            if(low[i] && upp[i]) //if char found in upp and low that will be the result
            {
                res += 'A'+i;
                break;
            }

        }
        return res;
    }
};