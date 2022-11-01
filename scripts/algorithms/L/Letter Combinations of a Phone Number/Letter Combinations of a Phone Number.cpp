// Runtime: 0 ms (Top 100.00%) | Memory: 6.5 MB (Top 53.08%)
class Solution {
public:

    void solve(string digit,string output,int index,vector<string>&ans,string mapping[])
    { // base condition
        if(index>=digit.length())
        {
            ans.push_back(output);
            return;
        }
        // digit[index] gives character value to change in integer subtract '0'
        int number=digit[index]-'0';
        // get the string at perticular index in mapping
        string value=mapping[number];
        //runs loop in value string and push that value in out put string ans do recursive call for next index
        for(int i=0;i<value.length();i++)
        {
            output.push_back(value[i]);
            solve(digit,output,index+1,ans,mapping);
            //backtrack
            //backtrach because initially output is empty and one case solves now you have to solve second case in similar way
            output.pop_back(); }

    }

    vector<string> letterCombinations(string digits) {

        vector<string>ans;
        //if it is empty input string
        if(digits.length()==0)
        {
            return ans;
        }
        string output="";
        int index=0;
        //map every index with string
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,index,ans,mapping);
        return ans;
    }
};