#define ll long long
class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<ll> result;
        ll start = intLength % 2 == 0 ? pow(10, intLength/2 - 1) : pow(10, intLength/2);
        for(int q: queries) { 
            string s = to_string(start + q - 1);
            string palindrome = s;
            reverse(s.begin(), s.end());
            if(intLength % 2 == 0) {
                palindrome += s;
            } else {
                palindrome += s.substr(1, s.size() - 1);
            }
			
			// len of palindrome should be intLength, otherwise -1
            if (palindrome.size() == intLength)
                result.push_back(stoll(palindrome));
            else
                result.push_back(-1);
        }
        
        return result;
    }
};
