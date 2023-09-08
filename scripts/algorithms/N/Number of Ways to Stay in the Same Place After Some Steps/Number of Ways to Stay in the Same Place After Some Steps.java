// Runtime: 205 ms (Top 20.9%) | Memory: 55.71 MB (Top 10.4%)

class Solution {
    
    HashMap<String,Long> map = new HashMap();
    
    public int numWays(int steps, int arrLen) {
        
        return (int) (ways(steps,arrLen,0) % ((Math.pow(10,9)) +7));
    }
    
    public long ways(int steps,int arrLen,int index){
        String curr = index + "->" + steps;
        
        if(index == 0 && steps == 0){
            return 1;
        }else if(index < 0 || (index >= arrLen) || steps == 0){
            return 0;
        }
        
        if(map.containsKey(curr)){
            return map.get(curr);
        }
        long stay = ways(steps-1,arrLen,index);
        long right = ways(steps-1,arrLen,index+1);
        long left = ways(steps-1,arrLen,index-1);
        
        map.put(curr , (stay+right+left) % 1000000007);
        
        return (right + left + stay) % 1000000007;
    }
}