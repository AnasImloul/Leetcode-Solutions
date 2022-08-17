class Solution {
    public int countHomogenous(String s) {
        int res = 1;
        int carry = 1;
        int mod = 1000000007;
        for(int i =1;i<s.length();i++){
            if(s.charAt(i) == s.charAt(i-1)) carry++;
            else carry = 1;
            res = (res + carry) % mod;
        }
        
        return res;
        
    }
}
