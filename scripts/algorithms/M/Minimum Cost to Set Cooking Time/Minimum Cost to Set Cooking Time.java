// Runtime: 1 ms (Top 88.7%) | Memory: 39.44 MB (Top 55.0%)

class Solution {
    public int minCostSetTime(int startAt, int moveCost, int pushCost, int tar) {
     
        int min=tar/60, sec=tar%60, minCost=(moveCost+pushCost)*4;
        
        if(min>99) { min--; sec+=60; } // this is required to do because if tar>=6000 then min is 100 which is not possible as it atmost can be 99mins
        
        while(min>=0&&sec<=99) { // this while loop will work for atmost 2 iterations
            tar=min*100+sec;
            char arr[]=(""+tar).toCharArray();
            int sameMove=0;
            for(int i=0;i<arr.length-1;i++)
                if(arr[i]==arr[i+1])
                    sameMove++;
            if(startAt==arr[0]-'0')
                minCost=Math.min(minCost,pushCost*arr.length+moveCost*(arr.length-1-sameMove));
            else
                minCost=Math.min(minCost,pushCost*arr.length+moveCost*(arr.length-sameMove));
            min--; sec+=60;
        }
        return minCost;
    }
}