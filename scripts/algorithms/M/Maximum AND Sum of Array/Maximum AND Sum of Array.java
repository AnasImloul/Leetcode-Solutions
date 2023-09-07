// Runtime: 11 ms (Top 93.9%) | Memory: 44.11 MB (Top 57.7%)

class Solution {
    int[] memo;
    int[] nums;
    int numSlots;
    public int maximumANDSum(int[] nums, int numSlots) {
        this.memo=new int[1<<(2*numSlots)];
        this.nums=nums;
        this.numSlots=numSlots;
        return helper(0,0);
    }
    int helper(int numIndex, int set) {
        // Base case when we used all the numbers 
        if(numIndex==nums.length) return 0;
        // Set informs BOTH the slots used and the numIndex. If the later
        // statement surprises you, think it like this: We must place all
        // the numbers in a slot, so how many slots are used in numIndex=10?
        // yes! 9 slots (because we will use the 10th now!), so the set will
        // have 10 ones. No other numIndex will have 9 ones. So having memo
        // with 2 dimentions would be redundant, as you would naver have a
        // combination of numIndex 3 with sets 1, 2, 4, 6.. etc, only
        // numIndex 2 will have those sets.
        if(memo[set]>0) return memo[set]-1; // I use memo-1 so I dont have to fill it with -1
        int max=0;
        for(int i=0;i<numSlots;i++) {
            int firstHalfSlot = (set&(1<<i))==0?i:-1; // -1 if it is used
            int secondHalfSlot = (set&(1<<(i+numSlots)))==0?i+numSlots:-1; // -1 if it is used
            int slotChosen = firstHalfSlot>-1?firstHalfSlot:secondHalfSlot;
            if(slotChosen<0) continue; // both slots are used
            int andSum=0;
            if(slotChosen>=numSlots) andSum=((slotChosen-numSlots)+1)&nums[numIndex];
            else andSum=(slotChosen+1)&nums[numIndex];
            // By adjusting the set in the recursion signature
            // I am backtracking in an elegant way.
            max=Math.max(max, andSum+ helper(numIndex+1,set|1<<slotChosen));
        }
        memo[set]=max+1; // I use memo+1 so I dont have to fill it with -1
        return max;
    }
}