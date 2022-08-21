// Runtime: 1 ms (Top 86.54%) | Memory: 41.2 MB (Top 80.80%)

//Recursion

class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        //int[] arr = new int{1,2,3,4,5,6,7,8,9};
        List<Integer> ds = new ArrayList<>();
        helper(1, n, k, ds, ans);
        return ans;
    }
    private static void helper(int i, int tar, int k, List<Integer> ds, List<List<Integer>> ans){
        //base
        if(k == 0) {
            if(tar == 0){
                ans.add(new ArrayList<>(ds));
            }
            return;
        }
        if(tar == 0) return; //bcz if k is not zero and tar is zero then no possible valid combination
        if(i > tar) return;
        if(i > 9) return;

        //Take
        if(i <= tar) {
            ds.add(i);
            helper(i+1, tar - i, k-1 , ds, ans);
            ds.remove(ds.size()-1);
        }
        // Not take
        helper(i+1 , tar, k , ds, ans);

        return;
    }
}