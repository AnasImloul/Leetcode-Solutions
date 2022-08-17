class Solution {
    public boolean judgeCircle(String moves) {
       int up=0;
        int rt=0;
        for(int i=0;i<moves.length();i++){
            if(moves.charAt(i)=='U') up++;
            if(moves.charAt(i)=='R') rt++;
            if(moves.charAt(i)=='L') rt--;
            if(moves.charAt(i)=='D') up--;
            
        }
        if(up==0&&rt==0) return true;
        return false;
    }
}
