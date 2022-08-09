class Solution {
    public boolean canFormArray(int[] arr, int[][] pieces) {
        HashMap<Integer,int[]> hm = new HashMap();
        for(int[] list:pieces)
            hm.put(list[0],list);
        
        int index = 0;
        while(index<arr.length){
            if(!hm.containsKey(arr[index]))
                return false;
            
            int[] list = hm.get(arr[index]);
            for(int val:list){
                if(index>=arr.length || val!=arr[index])
                    return false;
                index++;
            }
        }
        return true;
    }
}
