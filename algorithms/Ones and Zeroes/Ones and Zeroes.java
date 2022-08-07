class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        return solve(strs, m, n, 0);
    }
    
    public int solve(String[] strs, int m, int n, int i){
        if(i==strs.length) return 0;
        int count1=0;
        for(int j=0; j<strs[i].length(); j++){
            if(strs[i].charAt(j)=='1') count1++;
        }
		int count0 = strs[i].length-count1;
        
        if(count0<=m && count1<=n){
            return Math.max(solve(strs, m-count0, n-count1, i+1)+1, solve(strs, m, n, i+1));
        }
        else return solve(strs, m, n, i+1);
    }
}
