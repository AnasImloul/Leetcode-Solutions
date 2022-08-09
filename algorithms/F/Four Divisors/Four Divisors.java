class Solution {
    public int sumFourDivisors(int[] nums) {
        int res = 0;
        for(int val : nums){
            int sum = 0;
            int count = 0;
            for(int i=1;i*i <= val;i++){
                if(val % i == 0){
                    sum += i;
                    count++;
                    if(i != val/i){
                        sum += val/i;
                        count++;
                    }
                }
            }
            if(count == 4){
                res += sum;
            }
        }
        return res;
    }
}
