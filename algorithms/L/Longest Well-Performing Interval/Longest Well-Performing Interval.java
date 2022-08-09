// Brute Force Approach : PrefixSum ((Tiring - Non Tiring) Days) + Checking All Sliding Windows (Lengths 1 To n)
// For Longest Well Performing Interval/Window
// T.C. = O(n^2) , S.C. = O(n)
class Solution {
    
    public int longestWPI(int[] hours) {
        int n = hours.length;
        
        int[] prefixSumTiringDaysMinusNonTiringDaysArr = new int[n + 1];
        prefixSumTiringDaysMinusNonTiringDaysArr[0] = 0;
        
        int prefixSumTiringDaysCount = 0;
        int prefixSumNonTiringDaysCount = 0;
        
        for (int i = 0 ; i < n ; i++) {
            int noOfHoursWorkedToday = hours[i];
            
            if (noOfHoursWorkedToday > 8) {
                prefixSumTiringDaysCount++;
            }
            else {
                prefixSumNonTiringDaysCount++;
            }
            
            prefixSumTiringDaysMinusNonTiringDaysArr[i + 1] = prefixSumTiringDaysCount - prefixSumNonTiringDaysCount;
            // System.out.print(prefixSumTiringDaysMinusNonTiringDaysArr[i] + " ");
        }
        // System.out.println(prefixSumTiringDaysMinusNonTiringDaysArr[n]);
        
        int longestLengthOfContinuousPositiveSequence = 0;
        
        for (int currentSlidingWindowLength = 1 ; currentSlidingWindowLength <= n ; currentSlidingWindowLength++) {
            // System.out.print(currentSlidingWindowLength + " - ");
            for (int i = 0 ; i <= n - currentSlidingWindowLength ; i++) {
                int j = i + currentSlidingWindowLength - 1;
                // System.out.print(i + "," + j + " ");
                int currentIntervalNoOfTiringDaysMinusNonTiringDays = prefixSumTiringDaysMinusNonTiringDaysArr[j + 1] - prefixSumTiringDaysMinusNonTiringDaysArr[i];
                if (currentIntervalNoOfTiringDaysMinusNonTiringDays > 0) { // => currentInterval = Well Performing Interval
                    longestLengthOfContinuousPositiveSequence = Math.max(currentSlidingWindowLength, longestLengthOfContinuousPositiveSequence);
                }
            }
            // System.out.println();
        }
        // System.out.println();
        
        int lengthOfLongestWellPerformingInterval = longestLengthOfContinuousPositiveSequence;
        
        return lengthOfLongestWellPerformingInterval;
    }
    
}
