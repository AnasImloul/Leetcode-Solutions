class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> subsets=new ArrayList<>();
        generatesubsets(1,n,new ArrayList(),subsets,k);
        return subsets;
    }
    void generatesubsets(int start,int n,List<Integer> current,List<List<Integer>> subsets,int k){
        if(current.size()==k){
            subsets.add(new ArrayList(current));
        }
        for(int i=start;i<=n;i++){
            current.add(i);
            generatesubsets(i+1,n,current,subsets,k);
            current.remove(current.size()-1);
        }
    }
}
