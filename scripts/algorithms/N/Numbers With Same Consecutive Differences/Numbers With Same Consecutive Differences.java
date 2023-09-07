// Runtime: 3 ms (Top 66.2%) | Memory: 41.46 MB (Top 55.2%)

class Solution {
    
    List<Integer> res = new ArrayList<>();
    public int[] numsSameConsecDiff(int n, int k) {
        
        for(int ans = 1; ans < 10; ans++){ // first digit can't be 0
            find(ans, n-1, k); // find remaining n-1 digits using backtrack
        }
        
        return res.stream().mapToInt(Integer::intValue).toArray();  // convert list to int arr
    }
    
    private void find(int ans, int n, int k){
        
        if(n == 0){
            res.add(ans); // if got length n number then put that into res
            return;
        }
        
        for(int i = 0; i < 10; i++){
            if(Math.abs(ans%10-i) == k) // find digit that have k difference with last digit
                find(ans*10+i, n-1, k);
        }
        ans /= 10; // remove last digit while backtrack
    }
}