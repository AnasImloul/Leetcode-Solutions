// Runtime: 74 ms (Top 5.17%) | Memory: 82 MB (Top 5.24%)
class Solution {
    public boolean canTransform(String start, String end) {
        int startL = 0, startR = 0;
        int endL = 0, endR = 0;
        String stLR = "", edLR = "";
        for(int i = 0; i < start.length(); i++) {
            if(start.charAt(i) != 'X') {
                if(start.charAt(i) == 'L') {
                    startL++;
                } else{
                    startR++;
                }
                stLR+= start.charAt(i);
            }
            if(end.charAt(i) != 'X') {
                if(end.charAt(i) == 'L') {
                    endL++;
                } else{
                    endR++;
                }
                edLR += end.charAt(i);
            }

            if(startL > endL || startR < endR) //Check conditions at each instant
                return false;
        }

        if(startL != endL || startR != endR || !stLR.equals(edLR)) //check their final count and positions
            return false;

        return true;
    }

}