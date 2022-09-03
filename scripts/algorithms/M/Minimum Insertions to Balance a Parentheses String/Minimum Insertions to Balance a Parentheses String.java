// Runtime: 19 ms (Top 44.46%) | Memory: 51.9 MB (Top 75.57%)
class Solution {
    public int minInsertions(String s) {
        int open=0;
        int ans=0;

        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('){
                open++;
            }
            else{
                if(i+1<s.length() && s.charAt(i+1)==')'){
                    i++;
                    if(open>0){
                        open--;
                    }
                    else{
                        ans++;
                    }
                }
                else{
                    if(open>0){
                        open--;
                        ans++;
                    }
                    else{
                        ans+=2;
                    }
                }
            }
        }
        ans+=2*open;
        return ans;
    }
}