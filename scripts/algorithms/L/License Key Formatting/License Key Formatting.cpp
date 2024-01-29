// Runtime: 8 ms (Top 55.67%) | Memory: 9.70 MB (Top 8.81%)

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        stack<char> sChars;
        for (auto ch : S) {
            if (ch != '-')
                sChars.push(ch);
        }
        
        string sRet;
        int cur = 0;
        while (!sChars.empty()) {
            sRet += toupper(sChars.top());
            sChars.pop();
            cur++;
            
            if (cur == K && !sChars.empty()) {
                sRet += '-';
                cur = 0;
            }
        }
        reverse(sRet.begin(), sRet.end());
        return sRet;
    }
};
