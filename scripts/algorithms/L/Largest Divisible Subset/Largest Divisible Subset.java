// Runtime: 34 ms (Top 44.53%) | Memory: 44.1 MB (Top 26.48%)
class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int N = nums.length;
        List<Integer> ans =new ArrayList<Integer>();
        int []dp =new int[N];
        Arrays.fill(dp,1);
        int []hash =new int[N];
        for(int i=0;i<N;i++){
            hash[i]=i;
        }
        int lastindex=0;
        int maxi =1;
        for(int i=0;i<N;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0 && dp[j]+1 >dp[i]){
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
                if(dp[i] > maxi){
                    maxi = dp[i];
                    lastindex = i;
                }
            }
        }//for ends
        ans.add(nums[lastindex]);
        while(hash[lastindex] != lastindex){
            lastindex = hash[lastindex];
            ans.add(nums[lastindex]);
        }
        return ans;
    }

}