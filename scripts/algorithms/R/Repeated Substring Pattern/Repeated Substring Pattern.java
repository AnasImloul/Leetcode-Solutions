// Runtime: 324 ms (Top 17.74%) | Memory: 165.9 MB (Top 16.84%)
class Solution {

  public boolean repeatedSubstringPattern(String s) {
       String temp="";
        for(int i=0 ;i<s.length()/2 ;i++){
            temp+=s.charAt(i);

            if(s.length()%temp.length()==0) {
                int times_repeat= s.length()/temp.length();
                StringBuilder str = new StringBuilder();
                for(int j=0 ;j<times_repeat ;j++){
                    str.append(temp);
                }
                if(str.toString().equals(s)) return true;
            }
        }
        return false;
    }
}