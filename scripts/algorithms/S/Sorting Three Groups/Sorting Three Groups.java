// Runtime: 468 ms (Top 5.4%) | Memory: 44.53 MB (Top 5.7%)

class Solution {
    public int minimumOperations(List<Integer> nums) {
        int min = Integer.MAX_VALUE;

        int n = nums.size();
		// one is the position of the left of the first bar, which means all i <= one are in first group
        for (int one = -1; one < n; one++) {
		   	// three is the position of the right of the second bar, which means all i >= three are in third group
			// by deduction, all one < i < three are in the second group
            for (int three = one+1; three <= n; three++) {
                min = Math.min(min, computeOperations(one, three, nums));
            }
        }
		return min;
    }

    int computeOperations(int one, int three, List<Integer> nums){
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            Integer pos = nums.get(i);
            if(i <= one){
                if(pos != 1) count++;
            } else if (i < three){
                if(pos != 2) count++;
            } else {
                if(pos != 3) count++;
            }

        }

        return count;
    }
}