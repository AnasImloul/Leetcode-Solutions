class Solution {
    public List<Integer> mostVisited(int n, int[] rounds) {
        int[]psum=new int[n+2];
        psum[rounds[0]]+=1;
        psum[rounds[1]+1]-=1;
        if(rounds[0]>rounds[1])
            psum[1]+=1;
        for(int i=2;i<rounds.length;i++){
            psum[rounds[i-1]+1]+=1;
            psum[rounds[i]+1]-=1;
            if(rounds[i-1]>rounds[i])
                psum[1]+=1;
        }
        int max_=0;
        for(int i=1;i<=n;i++){
            psum[i]+=psum[i-1];
            if(psum[i]>max_)
                max_=psum[i];
        }
        List<Integer>ans=new ArrayList<>();
        for(int i=1;i<=n;i++){
            if(psum[i]==max_)
                ans.add(i);
        }
        return ans;
    }
}
