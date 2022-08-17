class Solution {
    public boolean hasAlternatingBits(int n) {
        String l = Integer.toBinaryString(n);
        for(int i = 0 ; i< l.length() -1 ; i++){
            if(l.charAt(i) == l.charAt(i+1))
                return false;
        }
        return true;
    }
}
