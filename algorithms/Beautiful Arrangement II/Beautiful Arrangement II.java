class Solution {
    public int[] constructArray(int n, int k) {
        int [] result = new int[n];
        result[0] = 1;
        int sign = 1;
        for(int i = 1 ; i < n; i++, k--){
            if(k > 0){
                result[i] = result[i-1] + k * sign;
                sign *= -1;
            }
            else{
                result[i] = i+1;
            }
        }
        return result;
    }
}
