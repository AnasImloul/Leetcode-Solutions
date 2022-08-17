class Solution {
    Map<String, Integer> cache;
    
    public int minimumWhiteTiles(String floor, int numCarpets, int carpetLen) {
        cache = new HashMap<>();
        return helper(floor, 0, numCarpets, carpetLen);
    }
    
    public int helper(String floor, int position, int numCarpets, int carpetLen) {
        if (position >= floor.length()) {
            return 0;
        }
        
        if (floor.length() - position <= numCarpets * carpetLen) {
            return 0;
        }
        
        String key = position + ", " + numCarpets;
        if (cache.containsKey(key)) {
            return cache.get(key);
        }
        
        if (numCarpets == 0) {
            int output = floor.charAt(position) - '0' + helper(floor, position + 1, 0, carpetLen);
            
            cache.put(key, output);
            return output;
        }
        
        int output = Math.min(floor.charAt(position) - '0' + helper(floor, position + 1, numCarpets, carpetLen), helper(floor, position + carpetLen, numCarpets - 1, carpetLen));
        
        cache.put(key, output);
        return output;
    }
}
