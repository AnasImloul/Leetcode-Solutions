class Solution {
    public int kSimilarity(String s1, String s2) {
        HashSet<String> vis = new HashSet<>();
        
        ArrayDeque<String> queue = new ArrayDeque<>();
        int level = 0;
        queue.add(s1);
        
        while(queue.size() > 0){
            int size = queue.size();
            for(int i=0;i<size;i++){
                
                String rem = queue.remove();        // remove
                
                if(vis.contains(rem)){              // Mark*
                    continue;
                }
                vis.add(rem);
                
                if(rem.equals(s2)){                 // Work
                    return level;
                }
                
                // Add
                for(String s : getNeighbors(rem,s2)){
                    if(!vis.contains(s)){
                        queue.add(s);
                    }
                }
            }
            level++;
        }
        return -1;
    }
    
    public ArrayList<String> getNeighbors(String rem,String s2){
        ArrayList<String> res = new ArrayList<>();
        
        int idx = -1;
        for(int i=0;i<rem.length();i++){
            if(rem.charAt(i) != s2.charAt(i)){
                idx = i;
                break;
            }
        }
        
        for(int j=idx+1;j<rem.length();j++){
            if(rem.charAt(j) == s2.charAt(idx)){
                String s = swap(rem,idx,j);
                res.add(s);
            }
        }
        
        return res;
    }
    
    public String swap(String str,int i,int j){
        StringBuilder sb = new StringBuilder(str);
        char chi = sb.charAt(i);
        char chj = sb.charAt(j);
        
        sb.setCharAt(i,chj);
        sb.setCharAt(j,chi);
        
        return sb.toString();
    }
}
