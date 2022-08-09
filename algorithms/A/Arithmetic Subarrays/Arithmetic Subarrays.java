class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> result = new ArrayList<>();
        int L = nums.length, ll = l.length,ind=0;
        for(int i=0;i<ll;i++){
            int[] arr = new int[r[i]-l[i]+1];
            ind=0;
            for(int k=l[i];k<=r[i];k++){
                arr[ind] =nums[k];
                ind++;
            }
            Arrays.sort(arr);
            result.add(isArithmetic(arr));
        }
        return result;
    }
    
    public boolean isArithmetic(int[] nums) {
        int L = nums.length;
        boolean b = true;
        if(L<=2) return true;
        for(int i=1;i<L-1;i++){
            if(nums[i]-nums[i-1]!=nums[i+1]-nums[i]) return false;
        }
        return b;
    }
}
