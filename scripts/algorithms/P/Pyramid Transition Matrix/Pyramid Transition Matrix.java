class Solution {
    HashMap<String, List<Character>> map = new HashMap<>();
    HashMap<String, Boolean> dp = new HashMap<>();
    
    public boolean pyramidTransition(String bottom, List<String> allowed) {
        for(String s:allowed){
            String sub = s.substring(0,2);
            
            char c = s.charAt(2);
            
            if(!map.containsKey(sub))
                map.put(sub, new ArrayList<>());
            
            map.get(sub).add(c);
        }
        
        return dfs(bottom, "", 0);
    }
    
    boolean dfs(String currBottom, String newBottom, int index){
        
        if(currBottom.length()==1)
            return true;
        if(index+1>=currBottom.length())
            return false;
        
        String sub = currBottom.substring(index,index+2);
        
        String state = currBottom+" "+newBottom+" "+index;
        
        if(dp.containsKey(state))
            return dp.get(state);
        
        if(map.containsKey(sub)){
            List<Character> letters = map.get(sub);
            
            for(char c:letters){
                if(index==currBottom.length()-2){
                    if(dfs(newBottom+c, "", 0))
                    {
                        dp.put(state, true);
                        return true;
                    }
                }
                else if(dfs(currBottom, newBottom+c, index+1))
                {
                    dp.put(state, true);
                    return true;
                }
            }
        }
        
        dp.put(state, false);
        return false;
    }
}
