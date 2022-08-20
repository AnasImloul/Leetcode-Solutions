// Runtime: 15 ms (Top 19.20%) | Memory: 43.5 MB (Top 45.49%)

class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<>();

        int len = s.length();
        for(int i = 1; i < 4 && i < len-2 ; i++ ){
            for(int j = i + 1; j < i + 4 && j < len-1 ; j++ ){
                for(int k = j+1 ; k < j + 4 && k < len ; k++){
                  String s1 = s.substring(0,i);
                  String s2 = s.substring(i,j);
                  String s3 = s.substring(j,k);
                  String s4 = s.substring(k,len);
                  if(isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4))
                      ans.add(s1+"."+s2+"."+s3+"."+s4);
                }
            }
        }
        return ans;
    }
    boolean isValid(String s){
        if(s.length() > 3 || s.length()==0 || (s.charAt(0)=='0' && s.length()>1) || Integer.parseInt(s) > 255)
           return false;
        return true;
    }
}