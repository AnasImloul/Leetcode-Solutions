// Runtime: 57 ms (Top 71.43%) | Memory: 109.9 MB (Top 23.21%)
class Solution {
    public int minimumLines(int[][] stockPrices) {
        if(stockPrices.length == 1) return 0;
        int count = 1;
        Arrays.sort(stockPrices,(o1,o2)->o1[0]-o2[0]);
        for(int i=1;i<stockPrices.length-1;i++){
            int x1 = stockPrices[i-1][0];
            int y1 = stockPrices[i-1][1];
            int x2 = stockPrices[i][0];
            int y2 = stockPrices[i][1];
            int x3 = stockPrices[i+1][0];
            int y3 = stockPrices[i+1][1];
            if(((x3-x2)*(y2-y1))==((y3-y2)*(x2-x1))) continue;

            count++;
        }
        return count;
    }
}