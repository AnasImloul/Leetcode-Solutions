Time: O(n+n)  Space: O(1)

class Solution {
public:
    string reverseWords(string s) {
        int i,j;
        for( i=0,j=0;i<size(s);i++){
            if(s[i]==' '){
                reverse(begin(s)+j,begin(s)+i);
                j=i+1;
            }
        }
        reverse(begin(s)+j,end(s));
        return s;
    }
};
