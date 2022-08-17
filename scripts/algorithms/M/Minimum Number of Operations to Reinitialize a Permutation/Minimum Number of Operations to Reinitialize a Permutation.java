class Solution {
    public int reinitializePermutation(int n) {
        int ans = 1;
        int num = 2;
        if(n == 2) return 1;
        while(true){
            if(num % (n-1) == 1)break; 
            else {
                ans++;
                num = (num * 2) % (n-1);
            }
        }
        return ans;
        
    }
}
