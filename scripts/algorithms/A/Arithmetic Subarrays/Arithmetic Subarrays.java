// Runtime: 16 ms (Top 83.14%) | Memory: 45.90 MB (Top 9.57%)

class Solution {
    public Boolean check(int[] arr) {
        Arrays.sort(arr);
        int diff = arr[1] - arr[0];
        
        for (int i = 2; i < arr.length; i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }
        
        return true;
    }
    
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> ans = new ArrayList();
        for (int i = 0; i < l.length; i++) {
            int[] arr = new int[r[i] - l[i] + 1];
            for (int j = 0; j < arr.length; j++) {
                arr[j] = nums[l[i] + j];
            }
            
            ans.add(check(arr));
        }

        return ans;
    }
}

