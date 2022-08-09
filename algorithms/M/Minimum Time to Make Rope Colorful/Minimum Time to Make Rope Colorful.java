class Solution {
    public int minCost(String colors, int[] neededTime) {
        return minCost(colors, neededTime, 0, neededTime.length - 1);
    }
    
    public int minCost(String colors, int[] neededTime, int start, int end) {
        if (start == end) {
            return 0;
        }
        
        int mid = (start + end) / 2;
        int lEnd = mid;
        int rStart = mid + 1;
        int t1 = minCost(colors, neededTime, start, lEnd);
        int t2 = minCost(colors, neededTime, rStart, end);
        
        while (neededTime[lEnd] < 0 && lEnd >= start) {
            --lEnd;
        }
        while (neededTime[rStart] < 0 && rStart <= end) {
            ++rStart;
        }
        
        if (colors.charAt(lEnd) != colors.charAt(rStart)) {
            return t1 + t2;
        }
        
        int removeTime = 0;
        if (neededTime[lEnd] <= neededTime[rStart]) {
            removeTime = neededTime[lEnd];
            neededTime[lEnd] *= -1;
        }
        else {
            removeTime = neededTime[rStart];
            neededTime[rStart] *= -1;
        }
            
        return t1 + t2 + removeTime;
    }
}
