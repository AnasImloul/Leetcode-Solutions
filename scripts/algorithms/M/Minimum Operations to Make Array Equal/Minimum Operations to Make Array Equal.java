class Solution {
    public int minOperations(int n) {
        int ans = (n/2)*(n/2);
        if(n%2==1){
            ans += n/2;
        }
        return ans;
    }
}