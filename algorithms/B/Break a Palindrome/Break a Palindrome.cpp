class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        string res = "";
        if(n==1){
            return res;
        }
        int i = 0;
        while(i<n){
            if(n%2!=0 && i==n/2){
                i++;
                continue;
            }
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                break;
            }
            i++;
        }
        if(i==n){
            palindrome[i-1] = 'b';
        }
        return palindrome;
    }
};
