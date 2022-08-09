class AuthenticationManager {
    private int ttl;
    private Map<String, Integer> map;

    public AuthenticationManager(int timeToLive) {
        this.ttl = timeToLive;
        this.map = new HashMap<>();
    }
    
    public void generate(String tokenId, int currentTime) {
        map.put(tokenId, currentTime + this.ttl);
    }
    
    public void renew(String tokenId, int currentTime) {
        Integer expirationTime = this.map.getOrDefault(tokenId, null);
        if (expirationTime == null || expirationTime <= currentTime)
            return;
        
        generate(tokenId, currentTime);
    }
    
    public int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (Map.Entry<String, Integer> entry: this.map.entrySet())
            if (entry.getValue() > currentTime)
                count++;
        
        return count;
    }
}

