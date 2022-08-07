class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int n = s.size();
        int i = n-1;
        while(i>=0){
            if(s[i]==' '){
                i--;
                if(count >0){
                    break;
                }
            }
            else{
                count++;
                i--;
            }
        }
        return count;
    }
};
