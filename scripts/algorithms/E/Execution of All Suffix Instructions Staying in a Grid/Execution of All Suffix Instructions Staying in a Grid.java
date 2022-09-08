// Runtime: 101 ms (Top 24.39%) | Memory: 46.7 MB (Top 33.10%)
class Solution {
    public int[] executeInstructions(int n, int[] startPos, String s) {
        //Make array of length equal to string length
        int ans[]=new int[s.length()];

        //Now use two for loops
        for(int i=0;i<s.length();i++){
            //countmoves will keep on counting the valid moves from i to s.length
            int countMoves=0;
            int yIndex=startPos[0];
            int xIndex=startPos[1];
            for(int j=i;j<s.length();j++){

                if(s.charAt(j)=='R'){
                    xIndex++;
                }
                if(s.charAt(j)=='L'){
                       xIndex--;
                }
               if(s.charAt(j)=='U'){
                        yIndex--;
                }
                if(s.charAt(j)=='D'){
                    yIndex++;
                }
                if(xIndex<0 || xIndex>=n || yIndex<0 || yIndex>=n){
                    break;
                }
                else{
                    countMoves++;
                }
            }

            ans[i]=countMoves;

        }
        return ans;

    }
}