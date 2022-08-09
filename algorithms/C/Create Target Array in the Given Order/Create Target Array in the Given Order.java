// Solution 1: O(n^2)
// --------------------------------------------------------------------
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int n = nums.length;
        int[] target = new int[n];
        
        for(int i = 0; i < n; i++) {
            int j = n - 1;
            while(j > index[i]) {
                target[j] = target[j - 1];
                j--;
            }
            target[index[i]] = nums[i];
        }
        
        return target;
    }
}

// Solution 2: O(n)
// ---------------------------------------------------------------------
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int n = nums.length;
        List<Integer> l = new ArrayList<>();
        
        for(int i = 0; i < n; i++) {
            l.add(index[i], nums[i]);
        }
        
        int[] target = new int[n];
        for(int i = 0; i < n; i++) {
            target[i] = l.get(i);
        }
        
        return target;
    }
}
