class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        
        if(barcodes.length <= 2){
            return barcodes ; //Problem says solution always exist.
        }
        
        Map<Integer, Integer> count = new HashMap<>();
        Integer maxKey = null; // Character having max frequency
        
        for(int i: barcodes){
            count.put(i, count.getOrDefault(i, 0) + 1);
            if(maxKey == null || count.get(i) > count.get(maxKey)){
                maxKey = i;
            }
        }
        
        int pos = 0;
     
        //Fill maxChar
        int curr =  count.get(maxKey);
        while(curr-- > 0){
            barcodes[pos] = maxKey;
            pos += 2;
            if(pos >= barcodes.length){
                pos = 1;
            }
        }
        
        count.remove(maxKey); // Since that character is done, we don't need to fill it again
        
        //Fill the remaining Characters.
        for(int key: count.keySet()){
            curr = count.get(key);
            
            while(curr-- > 0){
                barcodes[pos] = key;
                pos += 2;
                if(pos >= barcodes.length){
                    pos = 1;
                }
            }
        }
        
        return barcodes;
    }
}
