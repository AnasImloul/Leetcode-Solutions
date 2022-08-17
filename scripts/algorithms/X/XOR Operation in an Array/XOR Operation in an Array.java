class Solution {
    public int xorOperation(int n, int start) {
        int nums[]=new int[n];
        for(int i=0;i<n;i++)
            nums[i] = start + 2 * i;
        for(int i=1;i<n;i++)
            nums[i] = nums[i-1]^nums[i];
        return nums[n-1];
    }
}
