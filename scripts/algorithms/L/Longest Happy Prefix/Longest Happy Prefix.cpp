// Runtime: 59 ms (Top 53.19%) | Memory: 15.1 MB (Top 86.23%)
class Solution {
public:
    string longestPrefix(string s) {
        if(s == "")
            return "";
        int n = s.length();
        int arr[n];
        fill(arr, arr + n, 0);
        int prevLPS = 0, i = 1;
        while(i < n){
            if(s[i] == s[prevLPS]){
                arr[i] = prevLPS + 1;
                i++;
                prevLPS++;
            }
            else if(prevLPS == 0){
                arr[i] = 0;
                i++;
            }
            else{
                prevLPS = arr[prevLPS - 1];
            }
        }
        int oplen = arr[n-1];
        string temp = s.substr(n - oplen, oplen);
        return temp;
    }
};