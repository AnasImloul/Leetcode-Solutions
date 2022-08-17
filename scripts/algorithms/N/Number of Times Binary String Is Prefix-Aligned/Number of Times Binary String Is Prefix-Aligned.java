class Solution {
    public int numTimesAllBlue(int[] flips) {
        int counter=0,total=0,max=Integer.MIN_VALUE;
        for(int i=0;i<flips.length;i++){
            if(max<flips[i])max=flips[i];
            if(++counter==max)total++;
        }
        return total;
    }
}

