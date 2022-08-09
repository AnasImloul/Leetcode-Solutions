class Solution {
    public int minimumSize(int[] nums, int maxOperations) {
	//initiate the boundary for possible answers, here if you let min=1 it will still work for most cases except for some corner cases. We make max=100000000 because nums[i] <= 10^9. You can choose to sort the array and make the max= arr.max, at the price of time consumption.
	//The answer should be the minimized max value.
        int min = 0;
        int max = 1000000000;
		//Compared with min<max or min <= max, min + 1 < max will avoid infinite loops e.g. when min = 2, max = 3
        while (min +1< max) {
            int mid = (max - min)/2 + min;
			//count indicates the operation times with atmost mid balls in bag.
            int count = 0;
            for (int a: nums) {
			//this is the same as Math. ceil(a/mid) - 1=> math.ceil(a/mid) gives the number of divided bags, we subtract the number by 1 to get the subdivision operation times.
                count+=(a-1)/mid;
            }
			//if count < maxOperations, max WOULD be further minimized and set to mid; 
			//if count = maxOperations, max still COULD be further minimized and set to mid. 
			//so we combine < and = cases together in one if condition
            if (count <= maxOperations) {
			//max = mid - 1 will not work in this case becasue mid could be the correct answer. 
			//To not miss the correct answer we set a relatively "loose" boundary for max and min.
                max = mid;
            } else{
                min = mid;
            }
        }
		//Now we find the minimized max value
        return max;
    }
}
