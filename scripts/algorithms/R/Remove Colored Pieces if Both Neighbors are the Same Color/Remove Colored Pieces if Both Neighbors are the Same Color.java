// Runtime: 48 ms (Top 5.50%) | Memory: 52.8 MB (Top 84.58%)
class Solution {
    public boolean winnerOfGame(String colors) {
        int cntA=0,cntB=0;
        for(int i=1;i<colors.length()-1;i++){
             if(colors.charAt(i)=='A'&&colors.charAt(i-1)=='A'&&colors.charAt(i+1)=='A')cntA++;
            if(colors.charAt(i)=='B'&&colors.charAt(i-1)=='B'&&colors.charAt(i+1)=='B')cntB++;
        }

        return cntA>cntB;
    }
}