class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int val1 = nums[0], val2 = nums[0], cnt1 = 1, cnt2 = 0;
        for(int i = 1; i < nums.length; i++){
            if(val1 == nums[i]){
                cnt1++;
            } else if(val2 == nums[i]){
                cnt2++;
            } else{
                if(cnt1 == 0){
                    val1 = nums[i];
                    cnt1++;
                } else if(cnt2 == 0){
                    val2 = nums[i];
                    cnt2++;
                } else{
                    cnt1--;
                    cnt2--;
                }
            }
        }
        int check1 = 0, check2 = 0;
        for(int i = 0; i < nums.length; i++){
            if(val1 == nums[i])check1++;
            else if(val2 == nums[i])check2++;
        }
        List<Integer> ans = new ArrayList<>();
        if(check1 > nums.length / 3) ans.add(val1);
        if(check2 > nums.length / 3) ans.add(val2);
        return ans;
    }
}
