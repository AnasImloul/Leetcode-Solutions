// Runtime: 5 ms (Top 89.09%) | Memory: 42.70 MB (Top 55.56%)

class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        //Solution 1
        int sum = 0;
        for(int x : nums)
            sum += x;
        if(((sum - target) % 2 == 1) || (target > sum))
            return 0;
        
        int n = nums.length;
        int s2 = (sum - target)/2;
        int[][] t = new int[n + 1][s2 + 1];
        t[0][0] = 1;
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 0; j < s2 + 1; j++) {
                if(nums[i - 1] <= j)
                    t[i][j] = t[i-1][j] + t[i - 1][j - nums[i - 1]];
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        return t[n][s2];
        
           //Solution 2
//         int sum = 0;
//         for(int x : nums)
//             sum += x;
//         if(((sum - target) % 2 != 0) || (target > sum))
//             return 0;
        
//         int n = nums.length;
//         int s2 = (sum - target)/2;
        
//         int[][] t = new int[n + 1][s2 + 1];
//         for(int i = 0; i < n + 1; i++) {
//             for(int j = 0; j < s2 + 1; j++) {
//                 if(i == 0)
//                     t[i][j] = 0;
//                 if(j == 0)
//                     t[i][j] = 1;
//             }
//         }
        
//         for(int i = 1; i < n + 1; i++) {
//             for(int j = 1; j < s2 + 1; j++) {
//                 if((nums[i - 1] > j) || (nums[i - 1] == 0))
//                     t[i][j] = t[i - 1][j];
//                 else
//                     t[i][j] = t[i - 1][j] + t[i - 1][j - nums[i - 1]];
//             }
//         }
        
//         int count = 0;
//         for(int x : nums)
//             if(x == 0)
//                 count++;
        
//         return (int)(Math.pow(2,count)) * t[n][s2];
    }
}
