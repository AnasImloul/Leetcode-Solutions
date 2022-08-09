class Solution {
    public String generateTheString(int n) {
        String s = "";
        String string ="a";
        for (int i = 0; i < n-1; i++) 
            s += string;
        if(n%2==0)
        return s+"b";
        return s+"a";            
    }
}
