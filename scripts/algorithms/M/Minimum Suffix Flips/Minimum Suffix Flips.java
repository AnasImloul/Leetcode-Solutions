// Runtime: 9 ms (Top 72.82%) | Memory: 46.7 MB (Top 65.16%)

class Solution {
    public int minFlips(String target) {

        boolean lastBit = false;

        int flips = 0;
        for(int i=0;i<target.length();i++){

            if(target.charAt(i)=='1' && !lastBit){
                flips++;
                lastBit = !lastBit;
            }
            else if(target.charAt(i)=='0' && lastBit){
                flips++;
                lastBit = !lastBit;
            }

        }

        return flips;

    }
}