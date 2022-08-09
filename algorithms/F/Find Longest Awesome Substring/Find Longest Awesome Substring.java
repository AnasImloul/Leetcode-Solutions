class Solution {
    public int longestAwesome(String s) {
        Map<Integer,Integer>map=new HashMap<>();
        map.put(0,-1);
        
        int state=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            int bit=(1<<(s.charAt(i)-'0'));
            state ^=bit; //if odd freq then it becomes even or if even becomes odd
            
            if(map.containsKey(state))
               ans=Math.max(ans,i-map.get(state));
            
                for(int odd=0;odd<=9;odd++){ //become odds one by one
                    int mask=(1<<odd);
                    
                    Integer j=map.get(state^mask);
                    
                    if(j!=null)
                        ans=Math.max(ans,i-j);
                }
            
            if(!map.containsKey(state))
                map.put(state,i);
        }
        return ans;
        
    }
}
