// Runtime: 4 ms (Top 21.96%) | Memory: 5.9 MB (Top 94.64%)
class Solution{
public:
    int minimumSum(int num){
        string s = to_string(num);
        sort(s.begin(), s.end());
        int res = (s[0] - '0' + s[1] - '0') * 10 + s[2] - '0' + s[3] - '0';
        return res;
    }
};