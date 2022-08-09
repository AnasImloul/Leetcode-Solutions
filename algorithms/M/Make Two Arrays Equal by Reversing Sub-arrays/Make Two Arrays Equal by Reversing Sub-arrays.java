class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        HashMap<Integer,Integer>hm1=new HashMap();
        for(int i: arr){
            if(hm1.containsKey(i))
                hm1.put(i,hm1.get(i)+1);
            else
                hm1.put(i,1);
        }
        for(int i: target){
            if(hm1.containsKey(i)){
                hm1.put(i,hm1.getOrDefault(i,0)-1);
                if(hm1.get(i)==0)
                    hm1.remove(i);
            }
            else
                return false;
            
        }
        if(hm1.size()==0)
            return true;
        
        return false;
    }
}
