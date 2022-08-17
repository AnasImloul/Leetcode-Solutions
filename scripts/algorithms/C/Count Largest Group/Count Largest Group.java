class Solution {
    public int countLargestGroup(int n) {
        Map<Integer,Integer> map=new HashMap<>();
        for(int i=1;i<=n;i++){
            int x=sum(i);
            map.put(x,map.getOrDefault(x,0)+1);
        }
        int max=Collections.max(map.values());
        int c=0;
        for(int i:map.values()){
            if(i==max) c++;
        }
        return c;
    }
    public int sum(int g){
        int summ=0;
        while(g!=0){
            int rem=g%10;
            summ+=rem;
            g/=10;
        }
        return summ;
    }
}```