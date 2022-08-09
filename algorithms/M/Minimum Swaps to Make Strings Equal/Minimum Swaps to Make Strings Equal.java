class Solution {
    public int minimumSwap(String s1, String s2) {
        if(s1.length() != s2.length()) return -1;
		int n = s1.length();
        int x = 0 , y = 0;
        
        for(int i = 0 ; i < n ; i ++){
            char c1 = s1.charAt(i) , c2 = s2.charAt(i);
            if(c1 == 'x' && c2 == 'y') x++;
            else if(c1 == 'y' && c2 == 'x') y++;
        }
        
        if(x % 2 == 0 && y % 2 == 0) return x/2 + y/2;
        else if(x % 2 == 1 && y % 2 == 1) return x/2 + y/2 + 2;
        return -1;
    }
}
