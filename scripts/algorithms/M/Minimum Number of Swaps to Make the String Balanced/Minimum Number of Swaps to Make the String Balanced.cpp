// Runtime: 404 ms (Top 5.05%) | Memory: 33.7 MB (Top 18.77%)
class Solution {
public:
    int minSwaps(string s) {
        int ans=0;
        stack<char> stack;
        for(int i=0;i<s.length();i++){
            if(s[i]=='['){
                stack.push(s[i]);
            }
            if(s[i]==']' && stack.size()!=0 && stack.top()=='['){
                stack.pop();
            }

        }

        ans=stack.size();
        if(ans%2==0)
            return ans/2;
        else
            return (ans+1)/2;

    }
};