// Runtime: 152 ms (Top 66.6%) | Memory: 154.57 MB (Top 22.2%)

class Solution {
    public int[] minDifference(int[] nums, int[][] queries) {
        int n = nums.length;
        int[][] count = new int[n + 1][100];
        int q = queries.length;
        int ans[] = new int[q];
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 100; ++j)
                count[i + 1][j] = count[i][j];
            
            ++count[i + 1][nums[i] - 1];
        }
        
        for(int i = 0; i < q; ++i) {
            int low = queries[i][0];
            int high = queries[i][1] + 1;
            List<Integer> present = new ArrayList<>();
            int min = 100;
            
            for(int j = 0; j < 100; ++j)
                if(count[high][j] - count[low][j] != 0)
                    present.add(j);
            
            for(int j = 1; j < present.size(); ++j)
                min = Math.min(min, present.get(j) - present.get(j - 1));
            
            if(present.size() == 1)
                min = -1;
            
            ans[i] = min;
        }
        
        return ans;
    }
}