// Runtime: 1 ms (Top 65.71%) | Memory: 45.8 MB (Top 46.61%)
class Solution {
    public int[] shuffle(int[] nums, int n)
    {
        int[] arr = new int[2*n];
        int j = 0;
        int k = n;
        for(int i =0; i<2*n; i++)
        {
            if(i%2==0)
            {
                arr[i] = nums[j];
                j++;
            }
            else
            {
                arr[i] = nums[k];
                k++;
            }
        }
        return arr;
    }
}