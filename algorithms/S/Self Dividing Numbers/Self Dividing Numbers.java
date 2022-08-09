class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> ans= new ArrayList<>();
        while(left<=right){
            if(fun(left))
                ans.add(left);        
            left++;
        }
        return ans;
    }
    boolean fun(int x){
        int k=x;
        while(k>0)
        {
            int y=k%10;
            k=k/10;
            if(y==0||x%y!=0)
                return false;
        }
        return true;
    }
}
