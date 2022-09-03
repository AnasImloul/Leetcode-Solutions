// Runtime: 0 ms (Top 100.00%) | Memory: 6.9 MB (Top 78.33%)
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int>ans(2);
        int lines =0;
        int calc = 0;
        int i =0;
        while(i<s.length()){
            calc = 0;
            while(i<s.length() and calc<=100){
                calc+=widths[s[i]-'a'];
                i++;
            }
            if(calc>100){
                i-=1;
                calc-=widths[s[i]-'a'];
            }
            lines++;
            // cout<<lines;
        }
        ans[0] = lines;
        ans[1] = calc;
        return ans;
    }
};