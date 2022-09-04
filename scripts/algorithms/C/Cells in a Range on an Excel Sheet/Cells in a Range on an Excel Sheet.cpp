// Runtime: 3 ms (Top 82.44%) | Memory: 7.8 MB (Top 19.11%)
class Solution {
public:
    vector<string> cellsInRange(string s) {

        vector<string>ans;

        for(char ch=s[0];ch<=s[3];ch++)
        {
            for(int i=s[1]-'0';i<=s[4]-'0';i++)
            {
                string res="";
                res+=ch;
                res+=to_string(i);
                ans.push_back(res);

            }
        }
        return ans;
    }
};