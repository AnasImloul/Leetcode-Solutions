class Solution {
    long[][] pascal;
     private static final long mod = 1000000007;
    long one=1;
    public int numOfWays(int[] nums) {
        ArrayList list = new ArrayList<>();
        for (int n : nums) {
            list.add(n);
        }
        formPascal(nums);
        return (int)dfs(list)-1;
    }
    
    public long dfs(ArrayList list){
        if(list.size()<=2) return 1;
        ArrayList left=new ArrayList<>();
        ArrayList right=new ArrayList<>();
        int root=list.get(0);
        for(int n:list){
            if(nroot)
                right.add(n);
        }
        
        return ((pascal[left.size()+right.size()][left.size()])*(dfs(left)%mod))%mod *(dfs(right)%mod);
        
        
    }
    
    private void formPascal(int[] nums){
        pascal=new long[nums.length+1][];
        
        for(int i=0;i<=nums.length;i++){
            pascal[i]=new long[i+1];
           Arrays.fill(pascal[i],one);
            for(int j=1;j