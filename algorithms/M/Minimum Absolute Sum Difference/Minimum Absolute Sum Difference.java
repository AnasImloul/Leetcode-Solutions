class Solution {
    public int minAbsoluteSumDiff(int[] nums1, int[] nums2) {
        int mod = (int)1e9+7;

        // Sorted copy of nums1 to use for binary search
        int[] snums1 = nums1.clone();
        Arrays.sort(snums1);
        
        int maxDiff = 0;    // maximum difference between original and new absolute diff
        int pos = 0;        // where the maximum difference occurs
        int newn1 = 0;      // nums1 value to copy to nums1[pos]

        // For each array position i from 0 to n-1, find up to two elements
        // in nums1 that are closest to nums2[i] (one on each side of nums2[i]).
        // Calculate a new absolute difference for each of these elements.
        for (int i=0; i<nums2.length; i++) {
            int n2 = nums2[i];
            int origDiff = Math.abs(nums1[i] - n2);
            
            // Find the largest element in nums1 that is less than or equal to
            // the current element in nums2, if such an element exists.
            int floor = arrayFloor(snums1, n2);
            if (floor > Integer.MIN_VALUE) {
                // If a valid element exists, calculate a new absolute difference
                // at the current position, and calculate how much smaller this is
                // than the current absolute difference. If the result is better
                // than what we have seen so far, update the maximum difference and
                // save the data for the current position.
                int newDiff = Math.abs(floor - n2);
                int diff = origDiff - newDiff;
                if (diff > maxDiff) {
                    pos = i;
                    newn1 = floor;
                    maxDiff = diff;
                }
            }
            
            // Find the smallest element in nums1 that is greater than or equal to
            // the current element in nums2, if such an element exists.
            int ceiling = arrayCeiling(snums1, n2);
            if (ceiling < Integer.MAX_VALUE) {
                // Same as above
                int newDiff = Math.abs(ceiling - n2);
                int diff = origDiff - newDiff;
                if (diff > maxDiff) {
                    pos = i;
                    newn1 = ceiling;
                    maxDiff = diff;
                }
            }
        }

        // If we found a replacement value, overwrite the original value.
        if (newn1 > 0) {
            nums1[pos] = newn1;
        }
        
        // Calculate the absolute sum difference with the replaced value.
        int sum = 0;
        for (int i=0; i<nums1.length; i++) {
            sum = (sum + Math.abs(nums1[i] - nums2[i])) % mod;
        }
        
        return sum;
    }


    //
    // Array versions of TreeSet.floor and TreeSet.ceiling
    //
    
    // Greatest element less than or equal to val
    private int arrayFloor(int[] arr, int val) {
        int lo = 0;
        int hi = arr.length-1;
        int max = Integer.MIN_VALUE;
        
        while (lo <= hi) {
            int mid = lo+(hi-lo)/2;
            if (arr[mid] <= val) {
                max = arr[mid];
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        
        return max;
    }
    
    // Smallest element greater than or equal to val
    private int arrayCeiling(int[] arr, int val) {
        int lo = 0;
        int hi = arr.length-1;
        int min = Integer.MAX_VALUE;
        
        while (lo <= hi) {
            int mid = lo+(hi-lo)/2;
            if (arr[mid] >= val) {
                min = arr[mid];
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        
        return min;
    }
}
