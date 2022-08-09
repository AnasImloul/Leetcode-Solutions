class Solution {
    public int longestPath(int[] parent, String s) {
        ArrayList<ArrayList<Integer>> a=new ArrayList<>();
        for(int i=0;i<parent.length;i++)a.add(new ArrayList<Integer>());
        for(int i=1;i<parent.length;i++){
            a.get(parent[i]).add(i);
        }
        Pair p=dfs(0,a,s);
        return p.maxCount;
    }
    public Pair dfs(int root,ArrayList<ArrayList<Integer>> a,String s){
        if(a.get(root).size()==0)return new Pair(1,1);
        int maxCount=0,count1=0,count2=0;
        for(int child:a.get(root)){
            Pair pair=dfs(child,a,s);
            maxCount=Math.max(maxCount,pair.maxCount);
            if(s.charAt(root)!=s.charAt(child)){
                if(count1<pair.count){
                    count2=count1;
                    count1=pair.count;
                }else if(pair.count>count2){
                    count2=pair.count;
                }
            }
        }
        maxCount=Math.max(maxCount,count1+count2+1);
        return new Pair(count1+1,maxCount);
    }
    class Pair{
        int count,maxCount;
        Pair(int count,int maxCount){
            this.count=count;
            this.maxCount=maxCount;
        }
    }
}
